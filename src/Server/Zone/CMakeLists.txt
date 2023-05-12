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

add_subdirectory(Game)
add_subdirectory(Packets)
add_subdirectory(LUA)

set(DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PRIVATE_SOURCES
	${DIR}/Zone.hpp
	${DIR}/Zone.cpp
	${DIR}/Interface/ZoneClientInterface.cpp
	${DIR}/Interface/ZoneClientInterface.hpp
	${DIR}/Session/ZoneSession.cpp
	${DIR}/Session/ZoneSession.hpp
	${DIR}/Socket/ZoneSocket.cpp
	${DIR}/Socket/ZoneSocket.hpp
	${DIR}/SocketMgr/ClientSocketMgr.cpp
	${DIR}/SocketMgr/ClientSocketMgr.hpp
)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(zone
	${PRIVATE_SOURCES}
	${COMMON_SOURCES}
	${COMMON_HEADERS}
	${CORE_SOURCES}
	${UTILITY_SOURCES}
	${PACKET_SOURCES}
	${PACKET_HEADERS}
	${GAME_SOURCES}
	${LUA_SOURCES}
)

target_precompile_headers(zone
	PUBLIC
		../pch.hpp)

target_link_libraries(zone
	PUBLIC
        ${Boost_LIBRARIES}
		networking
		-lpthread
		mcache
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

message(status ${MYSQL_INCLUDE_DIR})
target_include_directories(zone
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

# LuaJit linker flags for macOS to avoid crashes.
if (APPLE)
	set(LUAJIT_LINK_FLAGS "-pagezero_size 10000 -image_base 100000000")
	set_target_properties(zone
			PROPERTIES
			LINK_FLAGS "${LUAJIT_LINK_FLAGS}"
	)
endif()

if (WITH_COVERAGE)
	target_compile_options(zone INTERFACE
		-O0        # no optimization
		-g         # generate debug info
		--coverage # sets all required flags
	)
	if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
		target_link_options(zone INTERFACE --coverage)
	else()
		target_link_libraries(zone INTERFACE --coverage)
	endif()
endif()

install(TARGETS zone
	DESTINATION ${CMAKE_INSTALL_PREFIX}
	CONFIGURATIONS ${CMAKE_BUILD_TYPE})

install(FILES ${PROJECT_SOURCE_DIR}/config/zone-server.lua.dist DESTINATION ${CONF_DIR})
install(DIRECTORY ${PROJECT_SOURCE_DIR}/scripts DESTINATION ${CMAKE_INSTALL_PREFIX})
install(DIRECTORY ${PROJECT_SOURCE_DIR}/db DESTINATION ${CMAKE_INSTALL_PREFIX})
