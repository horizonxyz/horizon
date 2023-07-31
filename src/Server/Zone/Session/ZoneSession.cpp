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
#include "ZoneSession.hpp"

#include "Server/Zone/Game/Map/MapManager.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/Socket/ZoneSocket.hpp"
#include "Server/Zone/Zone.hpp"


using namespace Horizon::Zone;
using namespace Horizon::Zone::Entities;

ZoneSession::ZoneSession(int64_t uid, std::shared_ptr<ZoneSocket> socket)
: Session(uid, socket)
{
}

ZoneSession::~ZoneSession()
{
	//
}

/**
 * @brief Initializes the zone session's members.
 * @thread Initialized from the Network Thread after socket and session creation.
 */
void ZoneSession::initialize()
{
	try {
		// Initialize the packet length table. This is used to determine the length of the packet from the packet id.
		_pkt_tbl = std::make_unique<ClientPacketLengthTable>(shared_from_this());
		// Initialize the packet handler. This is used to handle the packets received from the client.
		_clif = std::make_unique<ZoneClientInterface>(shared_from_this());
		// It is the responsibility of this method to initialize the player, but 
		// since player is the map owning thread's responsibility, we wait for the
		// session to start by letting the client send a CZ_ENTER packet.
		// When the packet is sent, the player will be created by the Networking Thread.
		// Initialized by the MapContainerThread.
		set_initialized(true);
	}
	catch (std::exception& error) {
		HLog(error) << "ZoneSession::initialize: " << error.what();
	}
}

//! @brief Queues a buffer to be sent to the client.
//! @param _buffer The buffer to be sent.
//! @param size The size of the buffer.
//! @return void
void ZoneSession::transmit_buffer(ByteBuffer _buffer, std::size_t size)
{
	if (get_socket() == nullptr || !get_socket()->is_open())
		return;
	
	if (!_buffer.is_empty()) {
		uint16_t packet_id = 0x0;
		int16_t packet_len = 0;
		
		memcpy(&packet_id, _buffer.get_read_pointer(), sizeof(int16_t));
		
		TPacketTablePairType p = _pkt_tbl->get_tpacket_info(packet_id);

		if (p.first == -1) {
			memcpy(&packet_len, _buffer.get_read_pointer() + 2, sizeof(int16_t));
		} else {
			packet_len = p.first;
		}

		// Warns when the packet length is not the same as the buffer length.
		if (packet_len != _buffer.active_length()) {
			HLog(warning) << "Packet 0x" << std::hex << packet_id << " has length " << std::dec << packet_len << " but buffer has " << _buffer.active_length() << " bytes... ignoring.";
			return;
		}

		// Queue the buffer for the Network Thread to send.
		get_socket()->queue_buffer(std::move(_buffer));
	}
}

/**
 * @brief Update loop for each Zone Session.
 * @thread called from MapContainerThread.
 */
void ZoneSession::update(uint32_t /*diff*/)
{
	std::shared_ptr<ByteBuffer> read_buf;
	while ((read_buf = get_socket()->_buffer_recv_queue.try_pop())) {
		uint16_t packet_id = 0x0;
		memcpy(&packet_id, read_buf->get_read_pointer(), sizeof(int16_t));
		HPacketTablePairType p = _pkt_tbl->get_hpacket_info(packet_id);
		
		HLog(debug) << "Handling packet 0x" << std::hex << packet_id << " - len:" << std::dec << p.first << std::endl;
		
		p.second->handle(std::move(*read_buf));
	}
}

/**
 * @brief Performs generic logout of player in cases where the
 * connection was closed abruptly or by instruction.
 * Also marks the player for removal from the MapContainerThread.
 * @thread Called from the NetworkThread.
 */
void ZoneSession::perform_cleanup()
{
	if (player() != nullptr) {
		player()->set_logged_in(false);
		player()->save();
		player()->remove_grid_reference();
		player()->map()->container()->remove_session(shared_from_this());
	}
}
