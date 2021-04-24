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

#ifndef HORIZON_ZONE_GAME_MAPCONTAINERTHREAD_HPP
#define HORIZON_ZONE_GAME_MAPCONTAINERTHREAD_HPP

#include "Core/Multithreading/ThreadSafeQueue.hpp"
#include "Core/Multithreading/LockedLookupTable.hpp"
#include "Server/Zone/Game/Script/ScriptManager.hpp"
#include "Utility/TaskScheduler.hpp"

#include <stdio.h>
#include <thread>
#include <unordered_map>
#include <atomic>

namespace Horizon
{
namespace Zone
{
class Map;
namespace Entities
{
	class Player;
}
class MapContainerThread : public std::enable_shared_from_this<MapContainerThread>
{
public:
	MapContainerThread();
	~MapContainerThread();

	//! @brief Retrieves a shared pointer to a map managed by the container.
	//! Managed maps are saved in thread-safe tables.
	//! @param[in] name const reference to the name of the map to lookup.
	//! @return Managed map if found, else a null shared_ptr instance.
	std::shared_ptr<Map> get_map(std::string const &name) const;

	//! @brief Adds a map to the container in real time. Managed map objects are
	//! stored in thread-safe tables.
	//! @param[in] m r-value reference to a shared_ptr of a map object.
	void add_map(std::shared_ptr<Map> &&map);

	//! @brief Removes a map from the container in real time. Managed maps are
	//! saved in thread-safe tables.
	void remove_map(std::string const &name);

	//! @brief Adds a player to the player buffer, marking him for addition to the
	//! list of managed players by this container on the next update.
	//! @param[in] p shared_ptr to a player object which should be managed by this map.
	//! @warning A player added for management by this container must be the only owner of the player object.
	void add_player(std::shared_ptr<Entities::Player> p);
	//! @brief Adds a player to the player buffer, marking him for removal from the
	//! list of managed players by this container on the next update.
	void remove_player(std::shared_ptr<Entities::Player> p);

	//! @brief Returns a player if found, nullptr otherwise.
	std::shared_ptr<Entities::Player> get_player(std::string const &name);
	std::shared_ptr<Entities::Player> get_player(int32_t guid);

	//! @brief Responsible for initialization of the container and is called externally.
	//! This is mainly for members that can't be initialized from the constructor method.
	void initialize();
	
	//! @brief Process container finalization by cleanly disconnecting players after saving their data.
	//! Clears all managed map instances from itself and joins the internally running thread.
	void finalize();

	//! @brief Begins running the container's thread and notifies of doing so.
	//! This function is a wrapper for the internal start function which the internal thread instance is
	//! responsible for calling. The internal start function deals with actual data loading/initializing,
	//! world update loop and finalization of the same on shutdown.
	void start();

	std::shared_ptr<ScriptManager> get_script_manager() { return _script_mgr; }

	TaskScheduler &getScheduler() { return _task_scheduler; }

private:
	//! @brief Called by the internal thread of MapContainerThread and deals with initialization of thread-accessible data.
	//! Is also responsible emulating the world update loop and performing everything in maps it manages.
	//! @thread MapContainerThread
	void start_internal();
	
	//! @brief World update loop emulator for the MapContainerThread.
	//! Performs world updates for maps managed in the specific thread container.
	//! @param[in] diff current system time.
	void update(uint64_t tick);

	std::thread _thread;
	LockedLookupTable<std::string, std::shared_ptr<Map>> _managed_maps;                     ///< Thread-safe hash-table of managed maps.
	ThreadSafeQueue<std::pair<bool, std::shared_ptr<Entities::Player>>> _player_buffer;     ///< Thread-safe queue of players to add to/remove from the container.
	LockedLookupTable<int32_t, std::shared_ptr<Entities::Player>> _managed_players;         ///< Thread-safe hash table of managed players.
	std::shared_ptr<ScriptManager> _script_mgr;                                            ///< Non-thread-safe shared pointer and owner of a script manager.
	TaskScheduler _task_scheduler;
};
}
}
#endif /* HORIZON_ZONE_GAME_MAPCONTAINERTHREAD_HPP */
