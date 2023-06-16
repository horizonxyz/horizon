/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
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

#include "MapComponent.hpp"

#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/Game/Map/Coordinates.hpp"

using namespace Horizon::Zone;

void MapComponent::sync_definitions(std::shared_ptr<sol::state> state)
{
}

void MapComponent::sync_data_types(std::shared_ptr<sol::state> state)
{
	state->new_usertype<GridCoords>("GridCoords",
		sol::constructors<GridCoords(uint16_t, uint16_t)>(),
		"x", &GridCoords::x,
		"y", &GridCoords::y,
		"move_cost", &GridCoords::move_cost,
		"set_move_cost", &GridCoords::set_move_cost
	);

	state->new_usertype<MapCoords>("MapCoords",
		sol::constructors<MapCoords(uint16_t, uint16_t)>(),
		"x", &MapCoords::x,
		"y", &MapCoords::y,
		"move_cost", &MapCoords::move_cost,
		"set_move_cost", &MapCoords::set_move_cost
	);

	state->new_usertype<Map>("Map",
		"name", sol::readonly_property(&Map::get_name),
		"width", sol::readonly_property(&Map::get_width),
		"height", sol::readonly_property(&Map::get_height),
		"has_obstruction_at", &Map::has_obstruction_at,
		"get_random_coordinates_in_walkable_range", &Map::get_random_coordinates_in_walkable_range,
		"get_random_coordinates_in_walkable_area", &Map::get_random_coordinates_in_walkable_area
	);
}

void MapComponent::sync_functions(std::shared_ptr<sol::state> state)
{
	state->set_function("get_map_by_name",
		[] (std::string const &name)
		{
			return MapMgr->get_map(name);
		});

	state->set_function("get_map_for_container",
		[this] (std::string const &name)
		{
			std::shared_ptr<Map> map = MapMgr->get_map(name);

			if (map == nullptr)
				return std::shared_ptr<Map>();

			return map;
		});
}