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

#ifndef HORIZON_ZONE_GAME_ENTITIES_MONSTER_HPP
#define HORIZON_ZONE_GAME_ENTITIES_MONSTER_HPP

#include "Server/Zone/Game/Entities/Creature/Creature.hpp"
#include "Server/Zone/Game/Entities/GridObject.hpp"
#include "Server/Zone/Game/StaticDB/MonsterDB.hpp"

#include <memory>

#define MIN_RANDOM_TRAVEL_TIME 4000
#define MOB_LAZY_MOVE_RATE 1000
#define MOB_MIN_THINK_TIME 100
#define MOB_MIN_THINK_TIME_LAZY (MOB_MIN_THINK_TIME * 10)

namespace Horizon
{
namespace Zone
{
class Map;
namespace Entities
{
class Monster : public Creature, public GridObject<Monster>
{
public:
	explicit Monster(std::shared_ptr<Map> map, MapCoords mcoords,
		std::shared_ptr<const monster_config_data> md,
		std::shared_ptr<std::vector<std::shared_ptr<const monster_skill_config_data>>> mskd);
	~Monster();

	void initialize() override;

	virtual void stop_movement() override;
	virtual void on_pathfinding_failure() override;
	virtual void on_movement_begin() override;
	virtual void on_movement_step() override;
	virtual void on_movement_end() override;

	void set_spotted(bool spotted) { _spotted = spotted; }
	bool is_spotted() { return _spotted; }

	void perform_ai_lazy();

	std::shared_ptr<const monster_config_data> monster_config() { return _wmd_data.lock(); }
	void set_monster_config(std::shared_ptr<const monster_config_data> md) { _wmd_data = md; }

private:
	bool _spotted{false};
	int _next_walktime{0}, _last_spotted_time{0};
	std::weak_ptr<const monster_config_data> _wmd_data;
	std::weak_ptr<std::vector<std::shared_ptr<const monster_skill_config_data>>> _wms_data;

};
}
}
}

#endif /* HORIZON_ZONE_GAME_ENTITIES_MONSTER_HPP */
