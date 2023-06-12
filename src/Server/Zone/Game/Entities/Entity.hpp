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

#ifndef HORIZON_ZONE_GAME_ENTITY_HPP
#define HORIZON_ZONE_GAME_ENTITY_HPP

#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Zone/Definitions/EntityDefinitions.hpp"
#include "Server/Zone/Definitions/SkillDefinitions.hpp"
#include "Server/Zone/Definitions/StatusEffectDefinitions.hpp"
#include "Server/Zone/Game/Entities/Battle/Combat.hpp"
#include "Server/Zone/Game/Map/Grid/GridDefinitions.hpp"
#include "Server/Zone/Game/Map/Coordinates.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/Game/Map/MapContainerThread.hpp"
#include "Server/Zone/LUA/LUAManager.hpp"
#include "Utility/TaskScheduler.hpp"

#define MIN_RANDOM_TRAVEL_TIME 4000
#define MOB_LAZY_MOVE_RATE 1000
#define MOB_MIN_THINK_TIME 100
#define MOB_MIN_THINK_TIME_LAZY (MOB_MIN_THINK_TIME * 10)

enum entity_task_schedule_group
{
	ENTITY_SCHEDULE_WALK       = 1,
	ENTITY_SCHEDULE_SAVE       = 2,
	ENTITY_SCHEDULE_AI_THINK   = 3,
	ENTITY_SCHEDULE_AI_WALK    = 4,
	ENTITY_SCHEDULE_STATUS_EFFECT_CLEAR = 5,
	ENTITY_SCHEDULE_AI_ACTIVE  = 6,
	ENTITY_SCHEDULE_ATTACK     = 7,
	ENTITY_SCHEDULE_SKILL_CAST = 8
};

enum entity_walk_state
{
	ENTITY_WALK_STOPPED = 0,
	ENTITY_WALK_MOVING = 1
};

#define ENTITY_STATUS_EFFECT_CHECK_TIME 1000

namespace Horizon
{
namespace Zone
{
	namespace Traits
	{
		class Status;
	}
class Map;

static int32_t _last_np_entity_guid = NPC_START_GUID;

class Entity : public std::enable_shared_from_this<Entity>
{
public:
	Entity(uint32_t guid, entity_type type, std::shared_ptr<Map> map, MapCoords map_coords);
	Entity(uint32_t guid, entity_type type);
	virtual ~Entity();

	bool initialize();

	bool is_initialized() const { return _is_initialized; }

	/**
	 * Movement
	 */
	MapCoords const &dest_coords() const { return _dest_pos; }
	virtual bool walk_to_coordinates(int16_t x, int16_t y);
	virtual bool walk_to_entity(std::shared_ptr<Entity> entity);
	bool is_walking() const { return (dest_coords() != MapCoords(0, 0)); }

	virtual void stop_movement() = 0;
protected:
	bool schedule_walk();
	void walk();
	bool stop_walking(bool cancel = false);
	
	virtual void on_pathfinding_failure() = 0;
	virtual void on_movement_begin() = 0;
	virtual void on_movement_step() = 0;
	virtual void on_movement_end() = 0;

	/**
	 * Unit Data
	 */
public:
	uint32_t guid() const { return _guid; }
	void set_guid(uint32_t guid) { _guid = guid; }

	uint16_t job_id() const { return _job_id; }
	void set_job_id(uint16_t job_id) { _job_id = job_id; }

	entity_posture_type posture() const { return _posture; }
	void set_posture(entity_posture_type posture) { _posture = posture; }

	const std::string &name() const { return _name; }
	void set_name(const std::string &name) { _name = name; }

	directions direction() const { return _facing_dir; }
	void set_direction(directions dir) { _facing_dir = dir; }

	std::shared_ptr<Horizon::Zone::Traits::Status> status() { return _status; }
	void set_status(std::shared_ptr<Horizon::Zone::Traits::Status> st) { _status = st; }

	void force_movement_stop_internal(bool stop = false) { _jump_walk_stop = stop; }
	/**
	 * Map & Map Container
	 */
	std::shared_ptr<Map> map() { return _map.expired() ? nullptr : _map.lock(); }
	void set_map(std::shared_ptr<Map> map)
	{
		_map = map;
		_map_container_thread = map->container();
		_lua_mgr = map->container()->get_lua_manager();
	}

	std::shared_ptr<MapContainerThread> map_container() { return _map_container_thread.lock(); }
	std::shared_ptr<LUAManager> lua_manager() { return _lua_mgr.lock(); }

	AStar::CoordinateList get_walk_path() { return _walk_path; }

	/**
	 * Entity applications
	 */
	entity_type type() const { return _type; }

	template <class T>
	std::shared_ptr<T> downcast()
	{
		return std::dynamic_pointer_cast<T>(shared_from_this());
	}

	/**
	 * Grid applications.
	 */
	MapCoords const &map_coords() const { return _map_coords; }
	void set_map_coords(MapCoords const &coords) { _map_coords = coords; }

	GridCoords const &grid_coords() const { return _grid_coords; }
	void set_grid_coords(GridCoords const &coords) { _grid_coords = coords; }

	bool is_in_range_of(std::shared_ptr<Entity> entity, uint8_t range = MAX_VIEW_RANGE);
	void notify_nearby_players_of_existence(entity_viewport_notification_type notif_type);
	void notify_nearby_players_of_spawn();
	void notify_nearby_players_of_movement(bool new_entry = false);
	std::shared_ptr<Entity> get_nearby_entity(uint32_t guid);

	uint64_t get_scheduler_task_id(entity_task_schedule_group group) { return ((uint64_t) guid() << 32) + (int) group; }
    
    std::map<int16_t, std::shared_ptr<status_change_entry>> &get_status_effects() { return _status_effects; }
    
    /**
     * Status Effects
     */
    bool status_effect_start(int type, int total_time, int val1, int val2, int val3, int val4);
    bool status_effect_end(int type);

    virtual void on_status_effect_start(std::shared_ptr<status_change_entry> sce) = 0;
    virtual void on_status_effect_end(std::shared_ptr<status_change_entry> sce) = 0;
    virtual void on_status_effect_change(std::shared_ptr<status_change_entry> sce) = 0;

	std::shared_ptr<AStar::CoordinateList> path_to(std::shared_ptr<Entity> e);
	int distance_from(std::shared_ptr<Entity> e) { return path_to(e)->size(); }

	virtual bool attack(std::shared_ptr<Entity> target, bool continuous = false);
	virtual bool stop_attacking();
	bool is_attacking();

	bool is_dead();

private:
	bool _is_initialized{false}, _jump_walk_stop{false};
	uint32_t _guid{0};
	entity_type _type{ENTITY_UNKNOWN};
	std::weak_ptr<Map> _map;
	MapCoords _map_coords{0, 0};
	GridCoords _grid_coords{0, 0};

	/* Simplified References */
	std::weak_ptr<MapContainerThread> _map_container_thread;
	std::weak_ptr<LUAManager> _lua_mgr;

	MapCoords _changed_dest_pos{0, 0}, _dest_pos{0, 0};
	AStar::CoordinateList _walk_path;
    int16_t _walk_path_index{0};

	std::shared_ptr<Horizon::Zone::Traits::Status> _status;

	// General Data
	std::string _name{""};
	uint16_t _job_id{0};
	entity_posture_type _posture{POSTURE_STANDING};
	directions _facing_dir{DIR_SOUTH};

	std::map<int16_t, std::shared_ptr<status_change_entry>> _status_effects;

	int32_t _attackable_time{0};
};
}
}

#endif /* HORIZON_ZONE_GAME_ENTITY_HPP */
