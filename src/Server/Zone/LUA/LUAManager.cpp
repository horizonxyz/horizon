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

#include "LUAManager.hpp"



#include "Server/Zone/Definitions/ItemDefinitions.hpp"
#include "Core/Logging/Logger.hpp"
#include "Server/Zone/Game/Map/MapManager.hpp"
#include "Server/Zone/Interface/ZoneClientInterface.hpp"
#include "Server/Zone/Session/ZoneSession.hpp"
#include "Server/Zone/Zone.hpp"

using namespace Horizon::Zone;
using namespace Horizon::Zone::Entities;

LUAManager::LUAManager(std::shared_ptr<MapContainerThread> container)
: _container(container), 
_lua_state(std::make_shared<sol::state>()),
_player_component(std::make_shared<PlayerComponent>()),
_npc_component(std::make_shared<NPCComponent>()),
_monster_component(std::make_shared<MonsterComponent>()),
_map_component(std::make_shared<MapComponent>()),
_item_component(std::make_shared<ItemComponent>()),
_entity_component(std::make_shared<EntityComponent>()),
_skill_component(std::make_shared<SkillComponent>()),
_status_effect_component(std::make_shared<StatusEffectComponent>()),
_combat_component(std::make_shared<CombatComponent>())
{
}

LUAManager::~LUAManager()
{

}

void LUAManager::initialize_for_container()
{
	initialize_basic_state(_lua_state);
	initialize_monster_state(_lua_state);
	initialize_npc_state(_lua_state);

	load_constants();
	load_scripts();
}

void LUAManager::initialize_basic_state(std::shared_ptr<sol::state> state)
{
	sol::protected_function_result res{};

	state->open_libraries(sol::lib::base);
	state->open_libraries(sol::lib::string);
	state->open_libraries(sol::lib::math);
	state->open_libraries(sol::lib::coroutine);
	state->open_libraries(sol::lib::jit);
	state->open_libraries(sol::lib::table);
	state->open_libraries(sol::lib::package);
	state->open_libraries(sol::lib::os);

	// Load timer function
	
	state->set_function("get_time", get_sys_time);
	state->set_function("schedule", [this] (uint32_t time, sol::function fn) {
		_container.lock()->getScheduler().Schedule(
		  Milliseconds(time),
		  [fn] (TaskContext context) {
		    sol::protected_function_result result = fn();
		    if (!result.valid()) {
					sol::error err = result;
					HLog(error) << "LUAManager::initialize_basic_state: Error on scheduled function: " << err.what();
				}
		  }
		);
	});

	_map_component->sync_definitions(state);
	_map_component->sync_data_types(state);
	_map_component->sync_functions(state);

	_item_component->sync_definitions(state);
	_item_component->sync_data_types(state);
	_item_component->sync_functions(state);

	_skill_component->sync_definitions(state);
	_skill_component->sync_data_types(state);
	_skill_component->sync_functions(state);

	_status_effect_component->sync_definitions(state);
	_status_effect_component->sync_data_types(state);
	_status_effect_component->sync_functions(state);

	_combat_component->sync_definitions(state);
	_combat_component->sync_data_types(state);
	_combat_component->sync_functions(state);

	_entity_component->sync_definitions(state);
	_entity_component->sync_data_types(state);
	_entity_component->sync_functions(state);

	std::string script_root_path = sZone->config().get_script_root_path().string();
	std::string static_db_root_path = sZone->config().get_static_db_path().string();
	std::vector<std::string> _loadable_files = {
		script_root_path.append("utils/strutils.lua"),
		static_db_root_path.append("definitions/constants.lua")
	};

	for (auto &file : _loadable_files) {
		try {
			res = state->script_file(file);

			if (!res.valid()) {
				sol::error error = res;
				HLog(error) << "LUAManager::initialize_state: " << error.what();
			}
		} catch (sol::error &error) {
			HLog(error) << "LUAManager::initialize_state: " << error.what();
		}
	}

	// Macro to constants
	(*state)["MAX_LEVEL"]            = MAX_LEVEL;
	(*state)["MAX_STATUS_POINTS"]    = MAX_STATUS_POINTS;
	(*state)["MAX_CHARACTER_SLOTS"]  = MAX_CHARACTER_SLOTS;
	(*state)["MAX_VIEW_RANGE"]       = MAX_VIEW_RANGE;
	(*state)["MIN_INVENTORY_SIZE"]   = MIN_INVENTORY_SIZE;
	(*state)["MAX_INVENTORY_SIZE"]   = MAX_INVENTORY_SIZE;
	(*state)["MIN_STORAGE_SIZE"]     = MIN_STORAGE_SIZE;
	(*state)["MAX_STORAGE_SIZE"]     = MAX_STORAGE_SIZE;
	(*state)["MAX_INVENTORY_STACK_LIMIT"]  = MAX_INVENTORY_STACK_LIMIT;
	(*state)["MAX_CART_STACK_LIMIT"]  = MAX_CART_STACK_LIMIT;
	(*state)["MAX_STORAGE_STACK_LIMIT"]  = MAX_STORAGE_STACK_LIMIT;
	(*state)["MAX_GSTORAGE_STACK_LIMIT"]  = MAX_GSTORAGE_STACK_LIMIT;

#ifdef RENEWAL
	(*state)["RENEWAL"]              = true;
#else
	(*state)["RENEWAL"]              = false;
#endif

	(*state)["basic_component"] = true;
}

void LUAManager::initialize_player_state(std::shared_ptr<sol::state> state)
{
	if ((*state)["basic_component"] == sol::lua_nil)
		initialize_basic_state(state);

	_player_component->sync_definitions(state);
	_player_component->sync_data_types(state);
	_player_component->sync_functions(state);

	(*state)["player_component"] = true;
}

void LUAManager::initialize_npc_state(std::shared_ptr<sol::state> state)
{
	if ((*state)["basic_component"] == sol::lua_nil)
		initialize_basic_state(state);

	_npc_component->sync_definitions(state);
	_npc_component->sync_data_types(state);
	_npc_component->sync_functions(state, _container.lock());

	(*state)["npc_component"] = true;
}

void LUAManager::initialize_monster_state(std::shared_ptr<sol::state> state)
{
	if ((*state)["basic_component"] == sol::lua_nil)
		initialize_basic_state(state);

	_monster_component->sync_definitions(state);
	_monster_component->sync_data_types(state);
	_monster_component->sync_functions(state, _container.lock());


	(*state)["monster_component"] = true;
}

void LUAManager::finalize()
{
	_script_files.clear();
}

void LUAManager::load_scripts()
{
	std::string script_root_path = sZone->config().get_script_root_path().string();

	try {
		_lua_state->script_file(script_root_path + "include.lua");

		sol::table scripts = (*_lua_state)["scripts"];

		int count = 0;
		scripts.for_each([this, &count, &script_root_path](sol::object const &/*key*/, sol::object const& value) {
			std::string script_file = value.as<std::string>();
			sol::protected_function fn = _lua_state->load_file(script_root_path + script_file);
			sol::protected_function_result result = fn();
			if (!result.valid()) {
				sol::error error = result;
				HLog(warning) << "Failed to load file '" << script_file << "' from '" << script_root_path << "', reason: " << error.what();
				return;
			}
			count++;
		});
		HLog(info) << "Read " << count << " NPC scripts from '" << script_root_path << "' for map container " << (void *)_container.lock().get() << ".";
	} catch (sol::error &e) {
		HLog(warning) << "Failed to load included script files from '" << script_root_path << "', reason: " << e.what();
	}
}
void LUAManager::load_constants()
{
	std::string file_path = sZone->config().get_static_db_path().string();

	try {
		_lua_state->script_file(file_path.append("definitions/constants.lua"));
		sol::table const_table = _lua_state->get<sol::table>("constants");
		HLog(info) << "Read constants from '" << file_path << "' for map container " << (void *)_container.lock().get() << ".";
	} catch (sol::error &e) {
		HLog(error) << "Failed to read constants from '" << file_path << "', reason: " << e.what();
	}
}
