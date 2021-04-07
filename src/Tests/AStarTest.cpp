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
 * Base Author - Sagun Khosla <sagunxp@gmail.com>
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

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "AStarTest"

#include "Server/Zone/Game/Map/Path/AStar.hpp"
#include "Server/Zone/Game/Map/Grid/Cell/Cell.hpp"
#include "Server/Zone/Game/Map/Grid/GridDefinitions.hpp"

#include <boost/test/unit_test.hpp>
#include <cstring>
#include <fstream>

using namespace Horizon::Zone;

// #define PRINT_FILE

#define MAP_WIDTH 268
#define MAP_HEIGHT 300

#include "prontera.cpp"

Cell cell[MAP_WIDTH][MAP_HEIGHT];

bool check_collision(int16_t x, int16_t y)
{
	if (x < 0 || y < 0 ||
		x >= MAP_WIDTH || y >= MAP_HEIGHT)
		return true;

	return cell[x][y].isWalkable() ? false : true;
}

#define MAX_TEST_COUNT 100

BOOST_AUTO_TEST_CASE(AStarTest)
{
	std::srand(std::time(nullptr));

	for (int i = 0; i < MAX_TEST_COUNT; i++) {
		MapCoords start, end;
		int idx = 0;

		// maps are stored from max-y,x down to 0,0
		// we store in cell[][] starting from 0,0 to max-y 0
		for (int y = MAP_HEIGHT - 1; y >= 0; y--) {
			for (int x = 0; x < MAP_WIDTH; ++x) {
				cell[x][y] = Cell(izlude[idx++]);
			}
		}

		do {
			do {
				start = MapCoords( rand() % MAP_WIDTH - 1, rand() % MAP_HEIGHT - 1 );
			} while(check_collision(start.x(), start.y()));

			do {
				end = MapCoords( rand() % MAP_WIDTH - 1, rand() % MAP_HEIGHT - 1 );
			} while(check_collision(end.x(), end.y()));
		} while (!start.is_within_range(end, MAX_VIEW_RANGE));

//	auto start_time = std::chrono::high_resolution_clock::now();
//	astar.navigate(start, end);
//	auto finish_time = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> elapsed = finish_time - start_time;
//	printf("Euclidean: %.2fs\n", elapsed.count());

		Horizon::Zone::AStar::Generator astar({ MAP_WIDTH, MAP_HEIGHT }, &check_collision, true, &Horizon::Zone::AStar::Heuristic::manhattan);
		auto start_time = std::chrono::high_resolution_clock::now();
		astar.setHeuristic(&AStar::Heuristic::manhattan);
		auto path = astar.findPath(start, end);
		auto finish_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish_time - start_time;
		bool path_found = !(path.size() == 0 || (path.at(0).x() != end.x() && path.at(0).y() != end.y()));
		printf("Manhattan: %.2fs %d %s (%d, %d) -> (%d, %d)\n", elapsed.count(), i, path_found ? "path found" : "path not found", start.x(), start.y(), end.x(), end.y());

#ifdef PRINT_FILE
		std::ofstream mapfile;
		char filename[100];
		snprintf(filename, 100, "izlude-%d.txt", i);
		mapfile.open(filename);
		for (int y = MAP_HEIGHT - 1; y >= 0; --y) {
			for (int x = 0; x < MAP_WIDTH; ++x) {
				MapCoords coords = MapCoords(x, y);
				bool found = false;
	
				for (auto c : path) {
					if (coords == c) {
						if (start.x() == x && start.y() == y)
							mapfile << "@ (" << x << ", " << y << ")";
						else if (end.x() == x && end.y() == y)
							mapfile << "T (" << x << ", " << y << ")";
						else if (c.x() == x && c.y() == y)
							mapfile << "^";
						found = true;
					}
				}
	
				if (!found) {
					if (start.x() == x && start.y() == y)
						mapfile << "@ (" << x << ", " << y << ")";
					else if (end.x() == x && end.y() == y)
						mapfile << "T (" << x << ", " << y << ")";
					else if (cell[x][y].isWalkable())
						mapfile << " ";
					else
						mapfile << "|";
				}
			}
	
			mapfile << "\n";
		}
	
		mapfile.close();
#endif
	}

//	start_time = std::chrono::high_resolution_clock::now();
//	astar.setHeuristic(&AStar::Heuristic::octagonal);
//	astar.navigate(start, end);
//	finish_time = std::chrono::high_resolution_clock::now();
//	elapsed = finish_time - start_time;
//	printf("Octogonal: %.2fs\n", elapsed.count());

	//BOOST_ASSERT(path->size() > 1);
}
