/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 *
 * Copyright (c) 2019 Sagun K. (sagunxp@gmail.com).
 * Copyright (c) 2019 Horizon Dev Team.
 *
 * Base Author - Sagun K. (sagunxp@gmail.com)
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************/

#ifndef HORIZON_ZONE_GAME_MAP_HPP
#define HORIZON_ZONE_GAME_MAP_HPP

#include "Path/AStar.hpp"
#include "Server/Common/Configuration/Horizon.hpp"
#include "Server/Common/Definitions/EntityDefinitions.hpp"
#include "Server/Zone/Game/Map/Grid/Cell/Cell.hpp"
#include "Server/Zone/Game/Map/Grid/GridDefinitions.hpp"
#include "Server/Zone/Game/Map/Grid/Container/GridReferenceContainerVisitor.hpp"
#include "Server/Zone/Game/Map/Grid/GridHolder.hpp"

#include <cassert>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include <boost/multi_array.hpp>

namespace Horizon
{
namespace Zone
{
class Map
{
friend class MapManager;
public:
	Map(std::weak_ptr<MapContainerThread>, std::string const &, uint16_t, uint16_t, std::vector<uint8_t> const &);
	~Map();

	std::shared_ptr<MapContainerThread> container() { return _container.lock(); }

	std::string const &get_name() { return _name; }

	int get_area() { return _width * _height; }

	uint16_t get_width() { return _width; }
	uint16_t get_height() { return _height; }

	GridHolderType &getGridHolder() { return _gridholder; }

	bool has_obstruction_at(int16_t x, int16_t y);

	MapCoords get_random_accessible_coordinates()
	{
		int16_t x = 0;
		int16_t y = 0;

		do {
			x = rand() % _width;
			y = rand() % _height;
		} while (has_obstruction_at(x, y));

		return { x, y };
	}

	template <class T>
	bool ensure_grid_for_entity(T *entity, MapCoords coords);

	template<class T, class CONTAINER>
	void visit(GridCoords const &grid, GridReferenceContainerVisitor<T, CONTAINER> &visitor);

	template<class T, class CONTAINER>
	void visit(GridCoords const &lower_bound, GridCoords const &upper_bound, GridReferenceContainerVisitor<T, CONTAINER> &visitor);

	template<class T, class CONTAINER>
	void visit_in_range(MapCoords const &map_coords, GridReferenceContainerVisitor<T, CONTAINER> &visitor, uint16_t range = MAX_VIEW_RANGE);

	AStar::Generator &get_pathfinder() { return _pathfinder; }

	MapCoords get_random_coordinates_in_walkable_range(uint16_t x, uint16_t y, int16_t min, int16_t max)
	{
		std::vector<MapCoords> available_cells;

		assert(min <= max);

		for (int i = std::max(x - max, 0); i < std::min(x + max, (int) _width); i++) {
			for (int j = std::max(y - max, 0); j < std::min(y + max,(int) _height); j++) {
				if (i == x && j == y)
					continue;
				if (abs(i - x) < min || abs(j - y) < min)
					continue;
				if (!has_obstruction_at(i, j))
					available_cells.push_back(MapCoords(i, j));
			}
		}

		if (available_cells.size() == 0)
			return MapCoords(0, 0);

		int rnd = rand() % available_cells.size();

		return available_cells.at(rnd);
	}

	MapCoords get_random_coordinates_in_walkable_area(uint16_t x, uint16_t y, int16_t xs, int16_t ys)
	{
		std::vector<MapCoords> available_cells;

		assert(xs >= 0);
		assert(ys >= 0);

		for (int i = std::max(x - xs, 0); i < std::min(x + xs, (int) _width); i++) {
			for (int j = std::max(y - ys, 0); j < std::min(y + ys,(int) _height); j++) {
				if (i == x && j == y)
					continue;
				if (!has_obstruction_at(i, j))
					available_cells.push_back(MapCoords(i, j));
			}
		}

		if (available_cells.size() == 0)
			return MapCoords(0, 0);

		int rnd = rand() % available_cells.size();

		return available_cells.at(rnd);
	}
	
private:
	std::weak_ptr<MapContainerThread> _container;
	std::string _name{""};
	uint16_t _width{0}, _height{0};
	GridCoords _max_grids;
	Cell _cells[MAX_CELLS_PER_MAP][MAX_CELLS_PER_MAP]{{0}};
	GridHolderType _gridholder;
	AStar::Generator _pathfinder;
};
}
}

template <class T>
bool Horizon::Zone::Map::ensure_grid_for_entity(T *entity, MapCoords mcoords)
{
	std::string const &new_map_name = entity->map()->get_name();
	GridCoords new_gcoords = mcoords.scale<MAX_CELLS_PER_GRID, MAX_GRIDS_PER_MAP>();

	if (new_map_name.compare(get_name()) == 0 && entity->grid_coords() == new_gcoords)
		return false;

	if (entity->has_valid_grid_reference())
		entity->remove_grid_reference();

	entity->set_grid_coords(new_gcoords);

	_gridholder.get_grid(new_gcoords).add_object(entity);

	return true;
}

template<class T, class CONTAINER>
inline void Horizon::Zone::Map::visit(GridCoords const &grid, GridReferenceContainerVisitor<T, CONTAINER> &visitor)
{
	_gridholder.get_grid(grid).visit(visitor);
}

template<class T, class CONTAINER>
inline void Horizon::Zone::Map::visit_in_range(MapCoords const &map_coords, GridReferenceContainerVisitor<T, CONTAINER> &visitor, uint16_t range)
{
	MapCoords lower_bounds = map_coords.at_range<MAX_CELLS_PER_MAP>(-range);
	MapCoords upper_bounds = map_coords.at_range<MAX_CELLS_PER_MAP>(range);

	visit(lower_bounds.scale<MAX_CELLS_PER_GRID, MAX_GRIDS_PER_MAP>(), upper_bounds.scale<MAX_CELLS_PER_GRID, MAX_GRIDS_PER_MAP>(), visitor);
}

template<class T, class CONTAINER>
inline void Horizon::Zone::Map::visit(GridCoords const &lower_bound, GridCoords const &upper_bound, GridReferenceContainerVisitor<T, CONTAINER> &visitor)
{
	for (int y = upper_bound.y(); y >= lower_bound.y(); --y) {
		for (int x = lower_bound.x(); x <= upper_bound.x(); ++x) {
			visit(GridCoords(x, y), visitor);
		}
	}
}

#endif /* HORIZON_ZONE_GAME_MAP_HPP */
