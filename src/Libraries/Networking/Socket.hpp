/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 *
 * Copyright (c) 2019 Sagun K. (sagunxp@gmail.com).
 * Copyright (c) 2019 Horizon Dev Team.
 *
 * Base Author - Sagun K. (sagunxp@gmail.com)
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************/

#ifndef HORIZON_NETWORKING_SOCKET_HPP
#define HORIZON_NETWORKING_SOCKET_HPP

#include "Core/Logging/Logger.hpp"
#include "Buffer/ByteBuffer.hpp"
#include "Core/Multithreading/ThreadSafeQueue.hpp"

#include <atomic>
#include <queue>
#include <memory>
#include <functional>
#include <future>
#include <type_traits>
#include <boost/asio/ip/tcp.hpp>
#include <boost/bind.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/use_future.hpp>

#include <iostream>

using boost::asio::ip::tcp;

#define READ_BLOCK_SIZE 0x1000

namespace Horizon
{
namespace Networking
{
/**
 * @brief A Socket object that handles a single connection.
 *        Sockets are moved into the thread by SocketMgr, once accepted or connected.
 *        Once started, the object blocks to handle I/O events and requires explicit stopping.
 * @tparam SocketType The type of the Socket object. The Socket object is templated to allow the SocketMgr to handle different types of Socket objects. The Socket object must inherit from the Socket class. 
 * The SocketMgr will call the start() method of the Socket object. The Socket object must implement the start() method. The start() method is called once 
 * from the NetworkThread. The Socket object must implement the update() method. The update() method is called every n nanoseconds 
 * from the NetworkThread.
 * @param socket_id The unique identifier of the Socket object.
 * @param socket The boost::asio::ip::tcp::socket object.
 * @param _remote_ip_address The remote IP address of the Socket object.
 * @param _remote_port The remote port of the Socket object.
 * @param _read_buffer The ByteBuffer object that holds the read buffer.
 * @param _closed The atomic boolean that indicates whether the Socket object is closed. The variables are set only from the NetworkThread. 
 * Once set, the Socket object will not accept any new read/write requests.
 * @param _closing The atomic boolean that indicates whether the Socket object is closing. The variables are set only from the NetworkThread. 
 * Once set, the Socket object will not accept any new write requests. The Socket object will continue to read until the read buffer is empty. 
 * Once the read buffer is empty, the Socket object will be closed.
 * @param _is_writing_async The atomic boolean that indicates whether the Socket object is writing asynchronously.
 * @param _write_queue The ThreadSafeQueue object that holds the write queue. The write queue is processed in the NetworkThread.
 */
template <class SocketType>
class Socket : public std::enable_shared_from_this<SocketType>
{
public:
	explicit Socket(uint64_t socket_id, std::shared_ptr<tcp::socket> socket)
	: _socket_id(socket_id), _socket(socket), _remote_ip_address(_socket->remote_endpoint().address().to_string()),
	_remote_port(_socket->remote_endpoint().port()), _read_buffer(), _closed(false), _closing(false), _is_writing_async(false)
	{
		_read_buffer.resize(READ_BLOCK_SIZE);
	}

	virtual ~Socket()
	{
		boost::system::error_code error;
		_socket->close(error);
	}

    /**
     * @brief Initial method invoked once from the network thread that handles the AuthSocket.
     * @thread NetworkThread
     */
	virtual void start() = 0;

    /**
     * @brief Socket update loop called from its NetworkThread every n nanoseconds.
     * Processes the message queue.
     * @thread NetworkThread
     */
	virtual bool update()
	{
		if (_closed)
			return false;

		if (_is_writing_async || (_write_queue.empty() && !_closing))
			return true;

		while (handle_queue())
			;

		return true;
	}

	/* Socket Id */
	uint64_t get_socket_id() { return _socket_id; }

	/* Remote IP and Port */
	std::string &remote_ip_address() { return _remote_ip_address; }
	uint16_t remote_port() const { return _remote_port; }

    /**
     * @brief Asynchronous read operation
     * @thread NetworkThread
     */
	void async_read()
	{
		if (!is_open())
			return;

		_read_buffer.flush();
		_read_buffer.ensure_free_space();
		
		_socket->async_read_some(boost::asio::buffer(_read_buffer.get_write_pointer(), _read_buffer.remaining_space()),
								 boost::bind(&Socket<SocketType>::read_handler_internal, this, boost::placeholders::_1, boost::placeholders::_2));
	}
    
    /**
     * @brief Asynchronous read operation with callback handler
     * @thread NetworkThread
     */
	void async_read_with_callback(ByteBuffer &buf, void (Socket<SocketType>::*)(boost::system::error_code, std::size_t))
	{
		if (!is_open())
			return;

		_read_buffer.flush();
		_read_buffer.ensure_free_space();

		_socket->async_read_some(boost::asio::buffer(buf.get_write_pointer(), buf.remaining_space()),
								 boost::bind(&Socket<SocketType>::read_handler_internal, this, boost::placeholders::_1, boost::placeholders::_2));
	}

	void queue_buffer(ByteBuffer &&buffer) { _write_queue.push(std::move(buffer)); }

	bool is_open() { return !_closed && !_closing; }

    /**
     * @brief Socket close operation that performs cleanups before shutting down the connection.
     * @thread NetworkThread
     */
	void close_socket()
	{
		boost::system::error_code socket_error;

		if (_closed.exchange(true))
			return;

		// Finalise the child-class socket first.
		on_close();

		/**
		 * Socket finalisation.
		 */
		// Shutdown the socket.
		_socket->shutdown(boost::asio::socket_base::shutdown_send, socket_error);
		// Close the socket.
		_socket->close();

		if (socket_error) {
			HLog(error) << "Error when shutting down socket from IP " <<
						   remote_ip_address() << "(error code:" << socket_error.value() << " - " << socket_error.message().c_str() << ")";
		}
	}

	void delayed_close_socket() { if (_closing.exchange(true)) return; }

    ByteBuffer &get_read_buffer() { return _read_buffer; }
	
	ThreadSafeQueue<ByteBuffer> &get_recv_queue() { return _buffer_recv_queue; }

protected:
	virtual void on_close() = 0;
	virtual void read_handler() = 0;
	virtual void on_error() = 0;

	/**
	 * @brief Socket write operation.
	 * @thread NetworkThread
  	 */
	bool async_process_queue()
	{
		if (_is_writing_async)
			return false;

		_is_writing_async = true;

		_socket->async_write_some(boost::asio::null_buffers(),
								  boost::bind(&Socket<SocketType>::write_handler_wrapper,
											  this, boost::placeholders::_1, boost::placeholders::_2));

		return true;
	}

	/**
	 * Disable the Nagle Algorithm on our socket.
	 * @param enable
	 */
	void set_no_delay(bool enable)
	{
		boost::system::error_code error;
		_socket->set_option(tcp::no_delay(enable), error);
		if (error) {
			HLog(error) << "Networking: Socket::set_no_delay: failed to set_option(boost::asio::ip::tcp::no_delay) for IP " << remote_ip_address() << " (error_code: " << error.value() << " - " << error.message().c_str() << ")";
		}
	}

	/**
	 * Write a message to the buffer.
	 * @param to_send
	 * @param error
	 * @return
	 */
	std::size_t write_buffer_and_send(ByteBuffer &to_send, boost::system::error_code &error)
	{
		int16_t packet_id;
		std::size_t bytes_to_send = to_send.active_length();
		memcpy(&packet_id, to_send.get_read_pointer(), sizeof(int16_t));
		std::size_t bytes_sent = _socket->write_some(boost::asio::buffer(to_send.get_read_pointer(), bytes_to_send), error);
		return bytes_sent;
	}
private:
    
	/**
	 * Aysnchronous reading handler method.
	 * @param error
	 * @param transferredBytes
	 * @thread NetworkThread
	 */
	void read_handler_internal(boost::system::error_code error, size_t transferredBytes)
	{
		// If there is an error on the socket, we need to close it.
		if (error) {
			// If the socket is already closed, we don't need to do anything.
			if (error.value() == boost::asio::error::eof) {
				close_socket();
			// If the connection was reset or timed out, we need to close the socket.
			} else if (error.value() == boost::system::errc::connection_reset
					   || error.value() == boost::system::errc::timed_out) {
				on_error();
				close_socket();
			// If there was any unknown error on the socket, we need to close it.
			} else {
				on_error();
				close_socket();
			}
			// Retreive the error code and handle it accordingly.
			switch (error.value())
			{
			case 2: // End of file
				break;
			default:
				HLog(debug) << "Socket::read_handler_internal: " << error.value() << " (Code: " << error.message() << ").";
			}
			return;
		}

		if (transferredBytes > 0) {
			// write_completed will move the write pointer forward, so we need to save the current position of the write pointer.
			_read_buffer.write_completed(transferredBytes);
			// read handler will process the data that has been written to the buffer.
			read_handler();
		}

		// Invoke the next read operation.
		async_read();
	}

	/**
	 * Write handler wrapper.
	 * @param error
	 * @param transferedBytes
	 */
	void write_handler_wrapper(boost::system::error_code /*error*/, std::size_t /*transferedBytes*/)
	{
		_is_writing_async = false;
		handle_queue();
	}

	/**
	 * Handle the queue
	 * @return true if the queue is not empty, false otherwise. 
	 * @thread NetworkThread
	 */
	bool handle_queue()
	{
		boost::system::error_code error;

		if (_write_queue.empty())
			return false;

		std::shared_ptr<ByteBuffer> to_send = _write_queue.front();

		std::size_t bytes_sent = write_buffer_and_send(*to_send, error);

		/**
		 * If we have a would block error, we need to re-process the queue.
		 */
		if (error == boost::asio::error::would_block || error == boost::asio::error::try_again)
			return async_process_queue();

		/**
		 * Re-process queue if we have remaining bytes.
		 */
		if (!error && bytes_sent < to_send->active_length()) {
			to_send->read_completed(bytes_sent);
			return async_process_queue();
		}

		// Pop the front element.
		_write_queue.try_pop();

		// Close if required.
		if (_closing && _write_queue.empty())
			close_socket();

		// Return true if the queue is not empty. Indicating that the sending operation was successful.
		return !_write_queue.empty() && bytes_sent;
	}

private:
	uint64_t _socket_id;
	std::shared_ptr<tcp::socket> _socket;               ///< After accepting, the reference count of this pointer should be 1.
	std::string _remote_ip_address;
	uint16_t _remote_port;
	ByteBuffer _read_buffer;
	ThreadSafeQueue<ByteBuffer> _write_queue;
	std::atomic<bool> _closed;
	std::atomic<bool> _closing;
	bool _is_writing_async;

public:
	ThreadSafeQueue<ByteBuffer> _buffer_recv_queue;
};
}
}

#endif //HORIZON_NETWORKING_SOCKET_HPP
