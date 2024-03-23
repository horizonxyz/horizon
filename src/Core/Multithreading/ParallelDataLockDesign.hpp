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

#ifndef HORIZON_CORE_MULTITHREADING_PARALLELDATALOCKDESIGN_HPP
#define HORIZON_CORE_MULTITHREADING_PARALLELDATALOCKDESIGN_HPP

#include <iostream>
#include <string>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread.hpp>
#include <memory>
#include <queue>
#include <map>
#include <unordered_map>

class ParallelDataLockDesign
{
public:
    ParallelDataLockDesign(uint64_t thread_index) : _txn_id(thread_index) { }
    ~ParallelDataLockDesign() { }

    uint64_t get_transaction_id() { return _txn_id; }
    void set_transaction_id(uint64_t txn_id) { _txn_id = txn_id; }

    std::condition_variable _condition;
    // Mutex shared between all relevant threads sharing the data.
    std::mutex _mutex;
    // Thread transaction ID, separating the Threads in waiting from the thread that is active.
    uint64_t _txn_id{0};
};

template<typename Key, typename Value>
class ParallelOrderedMap : public ParallelDataLockDesign
{
public:
    ParallelOrderedMap() : ParallelDataLockDesign(0) { }
    ~ParallelOrderedMap() { }

    bool insert(uint64_t txn_id, Key key, Value value)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        _map.insert(std::make_pair(key, value));
        release();
        return true;
    }

    bool remove(uint64_t txn_id, Key key)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        _map.erase(key);
        release();
        return true;
    }

    Value get(uint64_t txn_id, Key key)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        return _map.at(key);
    }

    Value acquire(uint64_t txn_id, Key key)
    {
        return get(txn_id, key);
    }

    void release()
    {
        _txn_id = 0;
        _condition.notify_one();
    }

private:
    std::map<Key, Value> _map; 
};

template<typename Key, typename Value>
class ParallelUnorderedMap : public ParallelDataLockDesign
{
public:
    ParallelUnorderedMap() : ParallelDataLockDesign(0) { }
    ~ParallelUnorderedMap() { }

    bool insert(uint64_t txn_id, Key key, Value value)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        _map.insert(std::make_pair(key, value));
        release();
        return true;
    }

    bool remove(uint64_t txn_id, Key key)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        _map.erase(key);
        release();
        return true;
    }

    Value get(uint64_t txn_id, Key key)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        return _map.at(key);
    }

    Value acquire(uint64_t txn_id, Key key)
    {
        return get(txn_id, key);
    }

    void release()
    {
        _txn_id = 0;
        _condition.notify_one();
    }

private:
    std::unordered_map<Key, Value> _map; 
};

template <typename T>
class ParallelMPMCQueue : public ParallelDataLockDesign
{
public:
    ParallelMPMCQueue() : ParallelDataLockDesign(0) { }
    ~ParallelMPMCQueue() { }

    void push(uint64_t txn_id, T value)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        _queue.push(value);
        release();
    }

    T pop(uint64_t txn_id)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _condition.wait(lock, [this] { return _txn_id == 0; });
        _txn_id = txn_id;
        T value = _queue.front();
        _queue.pop();
        release();
        return value;
    }

    T acquire(uint64_t txn_id)
    {
        return pop(txn_id);
    }

    void release()
    {
        _txn_id = 0;
        _condition.notify_one();
    }

private:
    std::queue<T> _queue;
};

#endif /* HORIZON_CORE_MULTITHREADING_PARALLELDATALOCKDESIGN_HPP */
