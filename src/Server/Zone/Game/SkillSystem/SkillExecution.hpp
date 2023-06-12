
#ifndef HORIZON_ZONE_GAME_SKILLEXECUTION_HPP
#define HORIZON_ZONE_GAME_SKILLEXECUTION_HPP

#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Zone/Definitions/SkillDefinitions.hpp"
#include "Server/Zone/Game/Map/Coordinates.hpp"
#include "Server/Zone/Game/Map/Map.hpp"

namespace Horizon
{
namespace Zone
{
class SkillExecution
{
public:
  SkillExecution(std::shared_ptr<Map> map, int16_t skill_id, int16_t skill_lv);
  ~SkillExecution();

  void execute(std::shared_ptr<Entity> intial_source, int initial_target_guid);
  void execute(std::shared_ptr<Entity> intial_source, MapCoords map_coords);
  void execute(std::shared_ptr<Entity> intial_source, int16_t x, int16_t y);
  void execute(std::shared_ptr<Entity> intial_source, MapCoords map_coords, std::string message);
  void execute(std::shared_ptr<Entity> intial_source, int16_t x, int16_t y, std::string message);


private:
  void load();
  void start_execution();
	std::shared_ptr<Map> map() { return _map.expired() ? nullptr : _map.lock(); }
	void set_map(std::shared_ptr<Map> map)
	{
		_map = map;
		_map_container_thread = map->container();
		_lua_mgr = map->container()->get_lua_manager();
	}
	std::shared_ptr<MapContainerThread> map_container() { return _map_container_thread.lock(); }
	std::shared_ptr<LUAManager> lua_manager() { return _lua_mgr.lock(); }
	std::shared_ptr<sol::state> lua_state() { return _lua_state; }

  struct skill_cast_data _scd{0};
	std::weak_ptr<Map> _map;
	std::weak_ptr<MapContainerThread> _map_container_thread;
	std::weak_ptr<LUAManager> _lua_mgr;
	std::shared_ptr<sol::state> _lua_state;
};
}
}

#endif /* HORIZON_ZONE_GAME_SKILLEXECUTION_HPP */
