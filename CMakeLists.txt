###################################################
#       _   _            _                        #
#      | | | |          (_)                       #
#      | |_| | ___  _ __ _ _______  _ __          #
#      |  _  |/ _ \| '__| |_  / _ \| '_  \        #
#      | | | | (_) | |  | |/ / (_) | | | |        #
#      \_| |_/\___/|_|  |_/___\___/|_| |_|        #
###################################################
# This file is part of Horizon (c).
# Copyright (c) 2019 Sagun K. (sagunxp@gmail.com).
# Copyright (c) 2019 Horizon Dev Team.
#
# Base Author - Sagun K. (sagunxp@gmail.com)
#
# This library is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this library.  If not, see <http://www.gnu.org/licenses/>.
####################################################

#################################
# Project Setup
#################################
cmake_minimum_required (VERSION 3.7 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "Horizon")

project (${PROJECT_NAME})
enable_language(CXX)
enable_language(C)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Project ${PROJECT_NAME} initiated configuring in ${CMAKE_BUILD_TYPE} mode.")

#################################
# CMAKE Module Path
#################################
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/macros")

#################################
# Find revision ID and hash of the sourcetree
#################################
if(NOT WITHOUT_GIT)
	find_package(Git)
endif()

#################################
# Binary Installation Directory
#################################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#################################
# INCLUDE COMPONENTS
#################################
include(CheckCXXSourceRuns)
include(CheckIncludeFiles)
include(CheckPlatform)
include(GroupSources)
include(AutoCollect)

#################
# Generate version.hpp File
#################
set(CMAKE_DISABLE_SOURCE_CHANGES OFF)
set(CMAKE_DISABLE_IN_SOURCE_BUILD OFF)
include(cmake/genversion/genversion.cmake)

#################################
# Disable in-source builds and changes
#################################
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

#################################
# print out the results before continuing
#################################
include(cmake/showoptions.cmake)

include (CheckCXXSourceCompiles)

check_cxx_source_compiles("
	#include <regex>
	int main() { std::wregex r(L\".*\"); }"
				STD_HAS_WORKING_WREGEX)


#################################
# Boost Library
#################################
set(BOOST_REQUIRED_VERSION 1.69.0)

set(BOOST_COMPONENTS locale filesystem log log_setup)

if (WITH_TESTS)
	set(BOOST_COMPONENTS ${BOOST_COMPONENTS} unit_test_framework)
endif()

message(STATUS "Boost Components: ${BOOST_COMPONENTS}")

find_package(Boost ${BOOST_REQUIRED_VERSION} REQUIRED COMPONENTS ${BOOST_COMPONENTS})

#################
# Readline Library
#################
set(Readline_FIND_REQUIRED true)
include(FindReadline)

###############
# LuaJit
###############
set(LUA_FIND_REQUIRED true)
include(FindLua)

###############
# Sol2
###############
set(SOL2_FIND_REQUIRED true)
include(FindSol2)

#################
# Find ZLIB
#################
find_package(ZLIB REQUIRED)

#################
# Find MySQL
#################
if (WIN32)
find_package(libmysql REQUIRED)
find_package(unofficial-mysql-connector-cpp CONFIG REQUIRED)
endif()

#################
# Horizon Project Source
#################
add_subdirectory(src)
