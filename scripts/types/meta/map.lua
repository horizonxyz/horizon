---@meta map

---@class Map
---@field name string # Map's name
---@field width integer # Map's width
---@field height integer # Map's height
Map = {}

---@class MapCoords
MapCoords = {}

---@return integer # the X coordinate
function MapCoords:x() end

---@return integer # the Y coordinate
function MapCoords:y() end
