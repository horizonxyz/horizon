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

#include "MapContainerThread.hpp"
#include "Server/Zone/Game/Entities/Player/Player.hpp"
#include "Server/Zone/Game/Entities/Creature/Hostile/Monster.hpp"
#include "Server/Zone/Game/Entities/NPC/NPC.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"
#include "Server/Zone/Zone.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Core/Logging/Logger.hpp"

using namespace Horizon::Zone;

MapContainerThread::MapContainerThread()
{

}

MapContainerThread::~MapContainerThread()
{
}

//! @brief Retrieves a shared pointer to a map managed by the container.
//! Managed maps are saved in thread-safe tables.
//! @param[in] name const reference to the name of the map to lookup.
//! @return Managed map if found, else a null shared_ptr instance.
std::shared_ptr<Map> MapContainerThread::get_map(std::string const &name) const
{
	return _managed_maps.at(name);
}

//! @brief Adds a map to the container in real time. Managed maps are
//! saved in thread-safe tables.
//! @param[in] m r-value reference to a shared_ptr of a map object.
void MapContainerThread::add_map(std::shared_ptr<Map> &&m)
{
	_managed_maps.insert(m->get_name(), m);
}

//! @brief Removes a map from the container in real time. Managed maps are
//! saved in thread-safe tables.
//! @param[in] m r-value reference to a shared_ptr of a map object.
void MapContainerThread::remove_map(std::string const &name)
{
	_managed_maps.erase(name);
}

//! @brief Adds a player to the player buffer, marking him for addition to the
//! list of managed players by this container on the next update.
//! @param[in] p shared_ptr to a player object which should be managed by this map.
//! @note A player added for management by this container must be the only owner of the player object.
void MapContainerThread::add_player(std::shared_ptr<Entities::Player> p)
{
	_player_buffer.push(std::make_pair(true, p));
}

//! @brief Adds a player to the player buffer, marking him for removal from the
//! list of managed players by this container on the next update.
void MapContainerThread::remove_player(std::shared_ptr<Entities::Player> p)
{
	_player_buffer.push(std::make_pair(false, p));
}

std::shared_ptr<Entities::Player> MapContainerThread::get_player(std::string const &name)
{
	std::map<int32_t, std::shared_ptr<Entities::Player>> player_map = _managed_players.get_map();
	for (auto it = player_map.begin(); it != player_map.end(); it++)
		if (it->second->name() == name)
			return it->second;

	return nullptr;
}

std::shared_ptr<Entities::Player> MapContainerThread::get_player(int guid)
{
	std::map<int32_t, std::shared_ptr<Entities::Player>> player_map = _managed_players.get_map();
	for (auto it = player_map.begin(); it != player_map.end(); it++)
		if (it->second->guid() == guid)
			return it->second;

	return nullptr;
}

//! @brief Responsible for initialization of the container and is called externally.
//! This is mainly for members that can't be initialized from the constructor method.
void MapContainerThread::initialize()
{
	_script_mgr = std::make_shared<ScriptManager>(shared_from_this());
}

//! @brief Process container finalization by cleanly disconnecting players after saving their data.
//! Clears all managed map instances from itself.
//! This method must not be called from within the thread itself! @see MapManager::finalize()
void MapContainerThread::finalize()
{
	std::map<int32_t, std::shared_ptr<Entities::Player>> pmap = _managed_players.get_map();
	for (auto pi = pmap.begin(); pi != pmap.end();) {
		std::shared_ptr<Entities::Player> player = pi->second;

		if (player && player->get_session())
			player->save();

		// Disconnect player.
//		player->get_packet_handler()->Send_ZC_ACK_REQ_DISCONNECT(true);
		_managed_players.erase(player->guid());
		pi++;
	}

	// Clear anyone in the player buffer (You never know...)
	std::shared_ptr<std::pair<bool, std::shared_ptr<Entities::Player>>> pbuf = nullptr;

	while ((pbuf = _player_buffer.try_pop())) {
		std::shared_ptr<Entities::Player> player = pbuf->second;

		if (!player || !player->get_session())
			continue;

		player->save();
//		player->get_packet_handler()->Send_ZC_ACK_REQ_DISCONNECT(true);
	}

	if (_thread.joinable())
		_thread.join();

	_managed_maps.clear();

	HLog(info) << "Map container " << (void *) this << " has shut down.";
}

//! @brief Begins running the container's thread and notifies of doing so.
//! This function is a wrapper for the internal start function which the internal thread instance is
//! responsible for calling. The internal start function deals with actual data loading/initializing,
//! world update loop and finalization of the same on shutdown.
void MapContainerThread::start()
{
	_thread = std::thread(&MapContainerThread::start_internal, this);

	HLog(info) << "Map container " << (void *) this << " with " << _managed_maps.size() << " maps has begun working.";
}

//! @brief Called by the internal thread of MapContainerThread and deals with initialization of thread-accessible data.
//! Is also responsible emulating the world update loop and performing everything in maps it manages.
//! @thread MapContainerThread
void MapContainerThread::start_internal()
{
	get_script_manager()->initialize();

	while (!sZone->general_conf().is_test_run() && sZone->get_shutdown_stage() == SHUTDOWN_NOT_STARTED) {
		update(std::time(nullptr));
		std::this_thread::sleep_for(std::chrono::microseconds(MAX_CORE_UPDATE_INTERVAL));
	};

	get_script_manager()->finalize();
}

//! @brief World update loop for a MapContainerThread.
//! Performs world updates for maps managed in the specific thread container.
//! @param[in] diff current system time.
void MapContainerThread::update(uint64_t diff)
{
	std::shared_ptr<std::pair<bool, std::shared_ptr<Entities::Player>>> pbuf = nullptr;

	// Add any new players / remove anyone else.
	while ((pbuf = _player_buffer.try_pop())) {
		std::shared_ptr<Entities::Player> player = pbuf->second;

		if (player->get_session() == nullptr)
			continue;

		if (pbuf->first) {
			if (!player->is_initialized())
				player->initialize();
			_managed_players.insert(player->guid(), player);
		} else {
			_managed_players.erase(player->guid());
		}
	}

	// Update sessions
	std::map<int32_t, std::shared_ptr<Entities::Player>> pmap = _managed_players.get_map();
	for (auto pi = pmap.begin(); pi != pmap.end();) {
		std::shared_ptr<Entities::Player> player = pi->second;

		if (!player
			|| !player->get_session()
			|| !player->get_session()->get_socket()
			|| !player->character()._online
			) {
			_managed_players.erase(player->guid());
			pi++;
			continue;
		}
		// process packets
		player->get_session()->update(diff);
		pi++;
	}

	// Update Monsters
	getScheduler().Update();
}
