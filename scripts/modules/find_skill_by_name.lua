local skill_id = ...

local skill_db = require("db/skill_db")

local function find_skill_by_name(skill_name)
	for k, v in pairs(skill_db) do
		if k == skill_name then
			return v
		end
	end
	return nil
end

return find_skill_by_name