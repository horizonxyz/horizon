local SM_BASH = {}

function SM_BASH.resolve_source(scd, skd)
  --[[
    The data we need is:
      scd - skill db data
      scd - The originating entity (if skill is called from client it will be the player, but if it is called from server side, it can be any entity)
      scd - The target id (if called from client it can be the player for self targeted skills or combos, if called from server can be any entity)
      scd - The skill level (For some reason some guild skills can call it with id 0 from the client)
      - The state of the entity (status and status changes, map, coordinates, party information. not data must be available upfront, it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)

    What will be defined and done here:
      - set the right source for the skill into the SCD
  ]]
  -- print("Resolving source for skill SM_BASH - scd: " .. scd .. " | skd : " .. skd)
  scd.source = scd.initial_source
  print("Resolving source for skill SM_BASH " .. scd.source:guid())
  return true
end

function SM_BASH.resolve_target(scd)
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not data must be available upfront, it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)
    
    What will be defined and done here:
      - set the right target type (if the type is an entity we define the target entity as well, but if it a ground skill, define the coordinates)
  ]]
  scd.target  = scd.initial_target
  print("Resolving target for skill SM_BASH: " .. scd.target:guid())
  return true
end

function SM_BASH.validate_before_casting(...)
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not all data must be available upfront, but it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)

    What will be defined and done here
      - validate if the skill can be initiated
  ]]
  print("Validating before cast for skill SM_BASH")
  return true
end

function SM_BASH.cast_skill(scd)
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
  scd.cast_time = 2000
  print("Casting skill for skill SM_BASH. Cast Time of  " .. scd.cast_time .. " milliseconds")
  return true
end

function SM_BASH.validate_after_casting(...)
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
  print("Validating after cast for skill SM_BASH")
  return true
end

function SM_BASH.perform_skill()
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not all data must be available upfront, but it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)

    What will be defined and done here
      - will execute the effects of the skill.
      - Some skills may be delayed so here will happen the scheduling of those cases.
  ]]
  print("Performing skill for skill SM_BASH")
  return true
end

return SM_BASH
