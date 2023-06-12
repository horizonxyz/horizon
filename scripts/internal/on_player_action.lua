local player, action = ...

if action == 2 or action == 3 then
	find_skill_by_name = require("scripts/modules/find_skill_by_name")
  local skill = find_skill_by_name("NV_BASIC")
  if skill == nil then
    print("on_player_action: Action ".. action .. " - Could not find skill NV_BASIC")
    return false
  else
    player:perform_skill(skill["Id"], 3)
  end
end
