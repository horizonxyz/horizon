###################################################
#       _   _            _                        #
#      | | | |          (_)                       #
#      | |_| | ___  _ __ _ _______  _ __          #
#      |  _  |/ _ \| '__| |_  / _ \| '_  \        #
#      | | | | (_) | |  | |/ / (_) | | | |        #
#      \_| |_/\___/|_|  |_/___\___/|_| |_|        #
###################################################
# This file is part of Horizon (c).
# Copyright (c) 2018 Horizon Dev Team.
#
# Base Author - Sagun Khosla. (sagunxp@gmail.com)
#
# Under a proprietary license this file is not for use
# or viewing without permission.
###################################################

if (WIN32)
  set(CONCPP_DIR_NAME "Connector C++ 8.0")
else()
  set(CONCPP_DIR_NAME "mysql-connector-c++")
endif()

find_path(CONCPP_ROOT_DIR
        NAMES ${CONCPP_DIR_NAME}
        HINTS
          /usr/local/
          "C:/Program Files/MySQL"
        )

find_path(CONCPP_INCLUDE_DIR
        NAMES mysqlx/xdevapi.h
        HINTS ${CONCPP_ROOT_DIR}/${CONCPP_DIR_NAME}/include
        )

if((NOT CONCPP_INCLUDE_DIR) OR CONCPP_INCLUDE_DIR STREQUAL "CONCPP_INCLUDE_DIR-NOTFOUND")
  message(FATAL_ERROR
    "Could not find MySQL Connector/C++ 8.0 headers at specified"
    " location: ${CONCPP_INCLUDE_DIR}"
  )
endif()

if (WIN32)
  set(CONCPP_LIB_DIR "lib64/vs14")
else()
  set(CONCPP_LIB_DIR "lib64")
endif()

set(CONCPP_LIB_PATH "${CONCPP_ROOT_DIR}/${CONCPP_DIR_NAME}/${CONCPP_LIB_DIR}")

set(LIBCPPCONN_NAME mysqlcppconn8)

find_library(CONCPP_LIB NAMES ${LIBCPPCONN_NAME}
  PATHS "${CONCPP_LIB_PATH}"
  NO_DEFAULT_PATH
)

if(NOT CONCPP_LIB)
  message(FATAL_ERROR
    "Could not find MySQL Connector/C++ 8.0 library ${LIBCPPCONN_NAME} at specified"
    " location: ${CONCPP_LIB_PATH}"
  )
endif()

# Set CONCPP_LIBS

if(CONCPP_LIB)
  list(APPEND CONCPP_LIBS optimized "${CONCPP_LIB}")
  if(NOT WIN32)
    list(APPEND CONCPP_LIBS general "${CONCPP_LIB}")
  endif()
endif()

message(STATUS "Found MySQL Connector C++ 8.0 libraries: ${CONCPP_LIBS}")

#
# Connector/C++ requires pthread library on Unix. Legacy connector needs
# even more.
#

# pthread is already apended by default.
#IF(CMAKE_HOST_UNIX)
#  list(APPEND CONCPP_LIBS pthread)
#ENDIF()

#
# On Solaris we additionally need socket and nsl libraries.
#

if(CMAKE_SYSTEM_NAME MATCHES "SunOS")
  list(APPEND CONCPP_LIBS socket nsl)
  # TODO: Could be couple more libs required..
  # MYSQL_LIBRARIES: stdc++;gcc_s;CrunG3;c;..;socket;nsl;m;rt
endif()

#
# Use clang's native C++ runtime library to match the one used
# by Connector/C++.
#

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

include_directories(${CONCPP_INCLUDE_DIR})

message("${debug_libs}")
