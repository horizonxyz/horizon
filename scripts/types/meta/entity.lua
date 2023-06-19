---@meta entity

---@param entity Entity
---@return Monster
function cast_entity_to_monster(entity) end

---@class Intelligence
Intelligence = {}

---@return integer # Total amount of intelligence that the entity has
function Intelligence:get() end

---@class CurrentHP
CurrentHP = {}

---@param amount integer How much hp to subtract
function CurrentHP:sub(amount) end

---@class Status
Status = {}

---@return CurrentHP
function Status:current_hp() end

---@return Intelligence
function Status:intelligence() end

---@class Entity
Entity = {}

-- TODO: add entity_type enum
---@return integer # the entity type value
function Entity:type() end

---@return boolean # Returns true if entity is dead
function Entity:is_dead() end

---@return Map
function Entity:map() end

---@return MapCoords
function Entity:map_coords() end

---@return Status
function Entity:status() end

---@return integer # Entity's unique id
function Entity:guid() end

---@param target Entity
---@param skill_id integer
---@param skill_lv integer
---@param start_time integer
---@param attack_motion integer
---@param attacked_motion integer
---@param damage integer
---@param count integer
---@param action_type DmgActionType
function Entity:show_skill_damage(target, skill_id, skill_lv, start_time, attack_motion, attacked_motion, damage, count, action_type) end

---@param target Entity
---@param skill_id integer
---@param cast_time integer
---@param element Element
function Entity:cast_skill_at_target(target, skill_id, cast_time, element) end

---@param entity Entity
---@param range integer
---@return boolean
function Entity:is_in_range_of(entity, range) end

---@return Combat? # Instance of combat if in combat
function Entity:combat() end
