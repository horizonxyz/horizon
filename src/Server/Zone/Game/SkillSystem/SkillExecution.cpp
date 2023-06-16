#include "SkillExecution.hpp"

#include "Server/Zone/Game/Entities/Entity.hpp"
#include "Server/Zone/Game/Map/Map.hpp"
#include "Server/Zone/Game/StaticDB/SkillDB.hpp"
#include "Server/Zone/LUA/Components/CombatComponent.hpp"
#include "Server/Zone/LUA/Components/ItemComponent.hpp"
#include "Server/Zone/LUA/Components/SkillComponent.hpp"
#include "Server/Zone/LUA/Components/EntityComponent.hpp"
#include "Server/Zone/Definitions/SkillDefinitions.hpp"
#include "Server/Zone/Zone.hpp"

using namespace Horizon::Zone;

SkillExecution::SkillExecution(std::shared_ptr<Map> map, int16_t skill_id, int16_t skill_lv)
: _skill_id(skill_id), _skill_lv(skill_lv), _lua_state(std::make_shared<sol::state>()), _map_coords(MapCoords(0, 0))
{
  set_map(map);
  load();
}

SkillExecution::~SkillExecution()
{
}

void SkillExecution::load()
{
	lua_manager()->initialize_player_state(lua_state());
	lua_manager()->initialize_npc_state(lua_state());
	lua_manager()->initialize_monster_state(lua_state());
}

void SkillExecution::start_execution(enum skill_target_type target_type)
{
  std::shared_ptr<const struct skill_config_data> skd = SkillDB->get_skill_by_id(_skill_id);

  if (target_type == SKTT_SINGLE_TARGETED && _initial_target == nullptr)
    return;

  if (!skd) {
    HLog(debug) << "SkillExecution::start_execution: Could not find skill with id '" << _skill_id << "' in the database. Ignoring skill usage...";
    return;
  }

  try {
    sol::load_result fx = lua_state()->load_file(sZone->config().get_script_root_path().string().append("skills/" + skd->name + ".lua"));
    sol::protected_function_result result = fx();
    if (!result.valid()) {
      sol::error err = result;
      HLog(error) << "SkillExecution::start_execution: " << err.what();
      return;
    }

    sol::table skill_functions = result;
    sol::protected_function initiate_skill_use = skill_functions["initiate_skill_use"];

    sol::table scd = lua_state()->create_table();
    scd["initial_source"] = _initial_source;
    scd["skill_id"] = _skill_id;
    scd["skill_lv"] = _skill_lv;
    scd["target_type"] = target_type;

    if (target_type == SKTT_SINGLE_TARGETED) {
      scd["initial_target"] = _initial_target;
    } else {
      scd["map_coords"] = _map_coords;
    }

    result = initiate_skill_use(scd, skd);
    if (!result.valid()) {
      sol::error err = result;
      HLog(error) << "SkillExecution::start_execution: Error on initiate_skill_use function: " << err.what();
      return;
    }
  } catch (sol::error &e) {
    HLog(error) << "SkillExecution::start_execution: " << e.what();
    return;
  }
}

void SkillExecution::execute(std::shared_ptr<Entity> initial_source, int initial_target_guid)
{
  if (initial_source == nullptr)
    return;

  _initial_source = initial_source;
  _initial_target = initial_source->get_nearby_entity(initial_target_guid);
  start_execution(SKTT_SINGLE_TARGETED);
}

void SkillExecution::execute(std::shared_ptr<Entity> initial_source, int16_t x, int16_t y)
{
  execute(initial_source, MapCoords(x, y));
}
void SkillExecution::execute(std::shared_ptr<Entity> initial_source, MapCoords map_coords)
{
  if (initial_source == nullptr)
    return;

  _initial_source = initial_source;
  _map_coords = map_coords;
  start_execution(SKTT_GROUND_TARGETED);
}

void SkillExecution::execute(std::shared_ptr<Entity> initial_source, int16_t x, int16_t y, std::string message)
{
  execute(initial_source, MapCoords(x, y), message);
}
void SkillExecution::execute(std::shared_ptr<Entity> initial_source, MapCoords map_coords, std::string message)
{
  if (initial_source == nullptr)
    return;

  _initial_source = initial_source;
  _map_coords = map_coords;
  _message = message;
  start_execution(SKTT_GROUND_TARGETED);
}

