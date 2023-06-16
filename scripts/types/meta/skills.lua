---@meta skills

-- TODO: finish type definitions
---@class SkillConfigData
---@field skill_id integer
---@field name string
---@field desc string
---@field max_level integer
---@field primary_type SkillType
---@field secondary_type SkillSubType
---@field dmg_property any
---@field cast_time_options any
---@field skill_delay_options any
---@field weapon_type any
---@field ammunition_type any
---@field placement_flag any
SkillConfigData = {}

---@param skill_lv integer The level of the skill to get the use range. Must not be less than 0 nor more than MAX_SKILL_LEVEL
---@return integer
function SkillConfigData:get_use_range(skill_lv) end

---@class SkillCastData
---@field skill_id integer
---@field skill_lv integer
---@field target_type SkillTargetType
---@field initial_source Entity
---@field source Entity?
---@field initial_target Entity?
---@field target Entity?
---@field map_coords MapCoords?
---@field cast_time integer?
---@field flags any?
SkillCastData = {}

---@class SkillExecution
---@field initiate_skill_use fun(scd: SkillCastData, skd: SkillConfigData)
---@field resolve_source fun(scd: SkillCastData, skd: SkillConfigData): boolean
---@field resolve_target fun(scd: SkillCastData, skd: SkillConfigData): boolean
---@field validate_before_casting fun(scd: SkillCastData, skd: SkillConfigData): boolean
---@field cast_skill fun(scd: SkillCastData, skd: SkillConfigData): boolean
---@field validate_after_casting fun(scd: SkillCastData, skd: SkillConfigData): boolean
---@field perform_skill fun(scd: SkillCastData, skd: SkillConfigData): boolean
SkillExecution = {}

---@enum SkillTargetType
SkillTargetType = {
  Single = 1,
  Ground = 2
}

---@enum SkillType
SkillType = {
  Passive   = 0x00,
  Attack    = 0x01,
  Placement = 0x02,
  Self      = 0x04,
  -- 0x08 is not assigned
  Friendly  = 0x10,
  Trap      = 0x20
}

---@enum SkillSubType
SkillSubType = {
  None                = 0x000000,
  Quest               = 0x000001,
  NPC                 = 0x000002,
  Wedding             = 0x000004,
  Spirit              = 0x000008,
  Guild               = 0x000010,
  Song                = 0x000020,
  Ensemble            = 0x000040,
  Trap                = 0x000080,
  TargetSelf          = 0x000100,
  NoTargetSelf        = 0x000200,
  PartyOnly           = 0x000400,
  GuildOnly           = 0x000800,
  NoEnemy             = 0x001000,
  IgnoreLandProtector = 0x002000,
  Chorus              = 0x004000,
  FreeCastReduced     = 0x008000,
  FreeCastNormal      = 0x010000,
  ShowSkillScale      = 0x020000,
  AllowReproduce      = 0x040000,
  HiddenTrap          = 0x080000,
  IsCombo             = 0x100000,
}
