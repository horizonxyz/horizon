local MG_FIREBOLT = {
  perform_skill = function ()
    print("hello")
  end
}

function MG_FIREBOLT.resolve_source(...)
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
end

function MG_FIREBOLT.resolve_target(...)
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not data must be available upfront, it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)
    
    What will be defined and done here:
      - set the right target type (if the type is an entity we define the target entity as well, but if it a ground skill, define the coordinates)
  ]]
end

function MG_FIREBOLT.validate_before_casting(...)
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not all data must be available upfront, but it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)

    What will be defined and done here
      - validate if the skill can be initiated
  ]]
end

function MG_FIREBOLT.cast_skill(...)
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
end

function MG_FIREBOLT.validate_after_casting(...)
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
end

function MG_FIREBOLT.perform_skill()
  --[[
    The data we need is:
      - SCD
      - The state of the entity (status and status changes, map, coordinates, party information. not all data must be available upfront, but it must be possible to get party data from player for example)
      - Load the entity from the target Id (so we can validate the same statuses as the item above)

    What will be defined and done here
      - will execute the effects of the skill.
      - Some skills may be delayed so here will happen the scheduling of those cases.
  ]]
  print("bye2")
end

return MG_FIREBOLT
