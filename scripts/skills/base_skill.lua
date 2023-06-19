---@type SkillExecution
local BASE_SKILL = {}

function BASE_SKILL.initiate_skill_use(scd, skd)
  if BASE_SKILL.resolve_source(scd, skd) == false or scd.source == nil then return end
  if BASE_SKILL.resolve_target(scd, skd) == false then return end
  if BASE_SKILL.validate_before_casting(scd, skd) == false then return end
  if BASE_SKILL.cast_skill(scd, skd) == false then return end

  if scd.cast_time ~= nil and scd.cast_time > 0 then
    schedule(scd.cast_time, function()
      if BASE_SKILL.validate_after_casting(scd, skd) == false then return end
      if BASE_SKILL.perform_skill(scd, skd) == false then return end
    end)
  else
    if BASE_SKILL.validate_after_casting(scd, skd) == false then return end
    if BASE_SKILL.perform_skill(scd, skd) == false then return end
  end
end

function BASE_SKILL.resolve_source(scd, skd)
  scd.source = scd.initial_source

  -- Is source dead?
  if scd.source:is_dead() then
    return false
  end

  return true
end

function BASE_SKILL.resolve_target(scd, skd)

  if (scd.target_type == SkillTargetType.Single) then
    scd.target = scd.initial_target

    -- Could not find the target
    if scd.target == nil then
      return false
    end

    -- Is target dead? (only for targeted) (skills that can be used in dead targets must override this function)
    if scd.target:is_dead() then
      return false
    end

    -- Is target in different map?
    if scd.target:map().name ~= scd.source:map().name then
      return false
    end

    -- Must check if the following is correct.
    -- If the target is the source and the skill is self but cannot be used on self, the target is the current combat target.
    if scd.source:guid() == scd.target:guid() and (skd.primary_type & SkillType.Self) ~= 0 and (skd.secondary_type & SkillSubType.NoTargetSelf) ~= 0 then
      -- Target is the current hit target
      if scd.source:combat() and scd.source:combat():target() then
        scd.target = scd.source:combat():target()
      else
        return false -- no current target
      end
    end
  else
    ; -- TODO: Ground targeted.
  end

  return true
end

function BASE_SKILL.validate_before_casting(scd, skd)

  -- Is talking to NPC? And the config allow skill use? (Player Only)

  -- Is vending or buying? Or in the pre-vending state (preparing to open shop) (Player Only)

  -- Is in Chat? (Player Only)

  -- Have a Body State that is not BURNING? (Body State = Herc sc->opt1) (Must see if is player only)

  -- Is trading with another character? (Player only)

  -- Is interacting with Storage (and is not a self targeted no damage skill)? (player only)

  -- Is using any of the following UIs: Refine, Lapine, Grade, Reform, Enchant (Player only)

  -- Is Sitting (player only)

  -- Source is on a NOSKILL cell? (e.g. Classical Pluck)

  -- Is attack motion not finished?

  -- Is in cooldown?

  -- Has Any Status Effect that blocks skill usage? (Mush think on how to make this) (not sure if monsters can bypass this)

  -- Is in a map / mapflag that does not allow using the skill? (not sure if it is player only)

  -- Is in the middle of a cast and this new skill was not autocasted?

  -- Is in After Cast Delay and is this skill was not autocasted?

  -- Is EffectState Costume? (EffectState is the same of sc->option in herc) (May be player only)

  -- Is in Menuskill? (player only)

  -- Is skill_lv < 0?
  if scd.skill_lv < 0 then
    return false
  end

  if scd.target_type == SkillTargetType.Single then
    if not scd.source:is_in_range_of(scd.target, skd:get_use_range(scd.skill_lv)) then
      return false
    end
  end

  return true
end

function BASE_SKILL.cast_skill(scd, skd)
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not all data must be available upfront, but it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)
      - cast time information (it will be in the SCD[skill db data] but for the case of skills used by monsters the casttime is overwritten by the mob_skill_db)

    What will be defined and done here
      - If the casttime is 0 it will flag SCD to perform the skill imediatelly
      - If there is a cast time, it will start the casttime (maybe schedule it from a method in SCD)
      - Depending on the skill it can perform the cast skill animation (show cast bar and other effects, refer to herc's clif->useskill and ZC_USESKILL_ACK)
  ]]
  -- local ct = skd.
  scd.cast_time = 2000


  scd.source:cast_skill_at_target(scd.target, scd.skill_id, scd.cast_time, Element.Fire)
  print("Casting skill for skill BASE_SKILL. Cast Time of  " .. scd.cast_time .. " milliseconds")
  return true
end

function BASE_SKILL.validate_after_casting(scd, skd)
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not all data must be available upfront, but it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)

    What will be defined and done here
      - Check some conditions again and some new checks like for casting spells on hidden targets. if the target is hidden when the cast ends, the skill fails.
      - validate if the skill can be performed
      - Consume requirements
  ]]
  print("Validating after cast for skill BASE_SKILL")
  return true
end

function BASE_SKILL.perform_skill(scd, skd)
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not all data must be available upfront, but it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)

    What will be defined and done here
      - will execute the effects of the skill.
      - Some skills may be delayed so here will happen the scheduling of those cases.
  ]]
  return true
end

return BASE_SKILL
