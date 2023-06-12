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

SkillExecution::SkillExecution(std::shared_ptr<Map> map, int16_t skill_id, int16_t skill_lv) : _lua_state(std::make_shared<sol::state>())
{
  set_map(map);
  load();

  _scd.skill_id = skill_id;
  _scd.skill_lv = skill_lv;
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

void SkillExecution::start_execution()
{
  std::shared_ptr<const struct skill_config_data> skd = SkillDB->get_skill_by_id(_scd.skill_id);

  if (!skd) {
    HLog(debug) << "SkillExecution::start_execution: Could not find skill with id '" << _scd.skill_id << "' in the database. Ignoring skill usage...";
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
    sol::protected_function resolve_source = skill_functions["resolve_source"];
    sol::protected_function resolve_target = skill_functions["resolve_target"];
    sol::protected_function validate_before_casting = skill_functions["validate_before_casting"];
    sol::protected_function cast_skill = skill_functions["cast_skill"];
    sol::protected_function validate_after_casting = skill_functions["validate_after_casting"];
    sol::protected_function perform_skill = skill_functions["perform_skill"];

    result = resolve_source(_scd, skd);
    if (!result.valid() || !result.get<bool>()) {
      sol::error err = result;
      HLog(error) << "SkillExecution::start_execution: Error on resolve_source function: " << err.what();
      return;
    }

    if (!_scd.source)
      return;

    result = resolve_target(_scd, skd);
    if (!result.valid() || !result.get<bool>())
      return;

    result = validate_before_casting(_scd, skd);
    if (!result.valid() || !result.get<bool>())
      return;

    result = cast_skill(_scd, skd);
    if (!result.valid() || !result.get<bool>())
      return;

    if (_scd.flags.is_instant_cast) {
      result = validate_after_casting(_scd, skd);
      if (!result.valid() || !result.get<bool>())
        return;

      result = perform_skill(_scd, skd);
      if (!result.valid() || !result.get<bool>())
        return;
    } else {
      map_container()->getScheduler().Schedule(
        Milliseconds(_scd.cast_time),
        _scd.source->get_scheduler_task_id(ENTITY_SCHEDULE_SKILL_CAST),
        [this, skd, validate_after_casting, perform_skill] (TaskContext context) {
          sol::protected_function_result result = validate_after_casting(_scd, skd);
          if (!result.valid() || !result.get<bool>())
            return;

          result = perform_skill(_scd, skd);
          if (!result.valid() || !result.get<bool>())
            return;
        }
      );
    }

  } catch (sol::error &e) {
    HLog(error) << "SkillExecution::start_execution: " << e.what();
    return;
  }
}

void SkillExecution::execute(std::shared_ptr<Entity> initial_source, int initial_target_guid)
{
  if (!initial_source)
    return;

  _scd.initial_source = initial_source;
  _scd.initial_target = initial_source->get_nearby_entity(initial_target_guid);

  start_execution();
}

void SkillExecution::execute(std::shared_ptr<Entity> initial_source, int16_t x, int16_t y)
{
  execute(initial_source, MapCoords(x, y));
}
void SkillExecution::execute(std::shared_ptr<Entity> initial_source, MapCoords map_coords)
{
  
}

void SkillExecution::execute(std::shared_ptr<Entity> initial_source, int16_t x, int16_t y, std::string message)
{
  execute(initial_source, MapCoords(x, y), message);
}
void SkillExecution::execute(std::shared_ptr<Entity> initial_source, MapCoords map_coords, std::string message)
{
  
}

