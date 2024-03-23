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
#define BOOST_TEST_MODULE "ParallelDataLockDesignTest"

#include <boost/test/unit_test.hpp>
#include "Core/Multithreading/ParallelDataLockDesign.hpp"
#include <cstring>
#include <fstream>
#include <iostream>

BOOST_AUTO_TEST_CASE(ParallelDataLockDesignTest)
{
    ParallelOrderedMap<int, int> map;
    ParallelUnorderedMap<int, int> u_map;
    ParallelMPMCQueue<int> q;
    std::srand(std::time(0));

#define MAX_TRIES 10000
#define MAX_THREADS 2

    std::thread *t[MAX_THREADS];
	std::atomic<bool> go;

    std::vector<int> values;

    for (int i = 1; i <= MAX_TRIES; i++) {
        values.push_back(std::rand() % 1000000);
    }

    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&map, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) { 
                printf ("Ordered Map Inserting %d\n", i);
                map.insert(std::rand() % 1000000 + 1, i, values[i]);
            }
    	});
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }
    
    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&map, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) { 
                printf ("Ordered Map Checking value[%d] is %d \n", i, values[i]);
                BOOST_CHECK_EQUAL(map.acquire(std::rand() % 1000000 + 1, i), values[i]);
                map.release();
            }
    	});
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }

    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&map, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) { 
                printf ("Ordered Map Removing %d\n", i);
                map.remove(std::rand() % 1000000 + 1, i);
            }
    	});
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }
    
    // Unordered Map
    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&u_map, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) { 
                printf ("Unordered Map Inserting %d\n", i);
                u_map.insert(std::rand() % 1000000 + 1, i, values[i]);
            }
    	});
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }
    
    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&u_map, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) { 
                printf ("Unordered Map Checking value[%d] is %d \n", i, values[i]);
                BOOST_CHECK_EQUAL(u_map.acquire(std::rand() % 1000000 + 1, i), values[i]);
                u_map.release();
            }
    	});
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }

    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&u_map, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) { 
                printf ("Unordered Map Removing %d\n", i);
                u_map.remove(std::rand() % 1000000 + 1, i);
            }
    	});
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }

    
    // Queue
    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&q, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) { 
                printf ("Queue Push %d\n", i);
                q.push(std::rand() % 1000000 + 1, values[i]);
            }
    	});
    }
    
    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }
    
    for (int j = 0; j < MAX_THREADS; j++) {
        int c = MAX_TRIES / MAX_THREADS * (j + 1);
    	t[j] = new std::thread([&q, &go, j, values, c]() {
            for (int i = j == 0 ? 1 : c / (j + 1); i < c; i++) {  
                printf ("Queue Pop %d -> %d \n", i, q.pop(std::rand() % 1000000 + 1));
            }
    	});
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        t[i]->join();
        delete t[i];
    }
}

