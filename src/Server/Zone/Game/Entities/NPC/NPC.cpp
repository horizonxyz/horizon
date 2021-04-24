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

#include "NPC.hpp"
#include "Common/Definitions/EntityDefinitions.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/Game/Entities/Traits/Status.hpp"


using namespace Horizon::Zone::Entities;

NPC::NPC(std::string const &name, std::shared_ptr<Map> map, uint16_t x, uint16_t y, uint32_t job_id, directions dir)
: Entity(_last_np_entity_guid++, ENTITY_NPC, map, MapCoords(x, y))
{
	set_name(name);
	set_job_id(job_id);
	set_direction(dir);
}

NPC::NPC(std::string const &name, std::shared_ptr<Map> map, uint16_t x, uint16_t y, std::string const &script)
: Entity(_last_np_entity_guid++, ENTITY_NPC, map, MapCoords(x, y))
{
	set_name(name);
	set_job_id(NPC_TYPE_PORTAL);
	set_direction(DIR_NORTH);
}

NPC::~NPC()
{
	if (has_valid_grid_reference())
		remove_grid_reference();
}

void NPC::initialize()
{
	Entity::initialize();

	status()->initialize();
	map()->ensure_grid_for_entity(this, map_coords());
}

void NPC::stop_movement()
{

}

void NPC::on_pathfinding_failure()
{

}

void NPC::on_movement_begin()
{

}

void NPC::on_movement_step()
{
	map()->ensure_grid_for_entity(this, map_coords());
}

void NPC::on_movement_end()
{

}
