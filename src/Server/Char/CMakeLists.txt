###################################################
#       _   _            _                        #
#      | | | |          (_)                       #
#      | |_| | ___  _ __ _ _______  _ __          #
#      |  _  |/ _ \| '__| |_  / _ \| '_  \        #
#      | | | | (_) | |  | |/ / (_) | | | |        #
#      \_| |_/\___/|_|  |_/___\___/|_| |_|        #
###################################################
# This file is part of Horizon (c).
#
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
###################################################

CollectSourceFiles(
    ${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE_SOURCES
)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(char
	${PRIVATE_SOURCES}
	${COMMON_SOURCES}
	${CORE_SOURCES}
    ${UTILITY_SOURCES})

target_precompile_headers(char
	PUBLIC
		../pch.hpp)

target_link_libraries(char
	PUBLIC
        ${Boost_LIBRARIES}
        networking
	    -lpthread
        ${Readline_LIBRARY}
		${LUA_LIBRARIES}
		${MYSQL_LIBRARIES}
		unofficial::mysql-connector-cpp::connector
)

set(INCLUDE_DIRS
        ${PROJECT_SOURCE_DIR}/src
)

CollectIncludeDirectories(
	${INCLUDE_DIRS}
	PUBLIC_INCLUDES
)

# LuaJit linker flags for macOS to avoid crashes.
if (APPLE)
set_target_properties(char
	PROPERTIES
	LINK_FLAGS "-pagezero_size 10000 -image_base 100000000"
	)
endif()

target_include_directories(char
	PUBLIC
		${Boost_INCLUDE_DIRS}
		${PUBLIC_INCLUDES}
        ${Readline_INCLUDE_DIR}
		${LUA_INCLUDE_DIR}
		${SOL2_INCLUDE_DIR}
		${SQLPP11_INCLUDE_DIR}
		${MYSQL_INCLUDE_DIR}
		${UNOFFICIAL_MYSQL_CONNECTOR_CPP_INCLUDE_DIR}
	PRIVATE
		${CMAKE_CURRENT_BINARY_DIR}
)

if (WITH_COVERAGE)
	target_compile_options(char INTERFACE
		-O0        # no optimization
		-g         # generate debug info
		--coverage # sets all required flags
	)
	if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
		target_link_options(char INTERFACE --coverage)
	else()
		target_link_libraries(char INTERFACE --coverage)
	endif()
endif()

install(TARGETS char
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    CONFIGURATIONS ${CMAKE_BUILD_TYPE})

install(FILES ${PROJECT_SOURCE_DIR}/config/char-server.lua.dist DESTINATION ${CONF_DIR})
