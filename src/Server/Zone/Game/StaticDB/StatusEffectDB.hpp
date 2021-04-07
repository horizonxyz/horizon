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

#ifndef HORIZON_ZONE_STATICDB_STATUSEFFECTDB_HPP
#define HORIZON_ZONE_STATICDB_STATUSEFFECTDB_HPP

#include "Core/Multithreading/LockedLookupTable.hpp" // Linux

#include <sol.hpp>

namespace Horizon
{
namespace Zone
{
struct status_effect_config_data
{
	int32_t status_id{0};
	std::string name{""};
	int32_t behavior{0};
	std::string icon{""};
	bool visible{true};
};
class StatusEffectDatabase
{
public:
	StatusEffectDatabase();
	~StatusEffectDatabase();
	
	static StatusEffectDatabase *get_instance()
	{
		static StatusEffectDatabase instance;
		return &instance;
	}

	bool load();

protected:
	bool load_internal(sol::object const &key, sol::object const &value);

public:
	std::shared_ptr<const status_effect_config_data> get_status_effect_by_id(int32_t id) { return _status_effect_db.at(id); }

private:
	LockedLookupTable<uint32_t, std::shared_ptr<const status_effect_config_data>> _status_effect_db;
};
}
}

#define StatusEffectDB Horizon::Zone::StatusEffectDatabase::get_instance()

#endif /* HORIZON_ZONE_STATICDB_STATUSEFFECTDB_HPP */
