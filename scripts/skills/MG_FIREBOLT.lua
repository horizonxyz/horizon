local MG_FIREBOLT = require("scripts/skills/base_skill")

function MG_FIREBOLT.perform_skill(scd, skd)
  if scd.target_type == SkillTargetType.Single then
    local int = scd.source:status():intelligence():get()
    local min_matk = int + math.floor(int / 7) ^ 2
    local max_matk = int + math.floor(int / 5) ^ 2

    local damage = math.random(min_matk, max_matk) * scd.skill_lv

    scd.target:status():current_hp():sub(damage)

    local attack_motion = 3050
    local attacked_motion = 500

    if scd.target:type() == 5 then
      schedule(attacked_motion, function ()
        local monster = cast_entity_to_monster(scd.target)
        monster:on_damage_received(scd.source, damage)
      end)
    end
    scd.source:show_skill_damage(scd.target, scd.skill_id, scd.skill_lv, os.time(), attack_motion, attacked_motion, damage, scd.skill_lv, 8)
  end
  return true
end

return MG_FIREBOLT
