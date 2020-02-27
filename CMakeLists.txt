cmake_minimum_required(VERSION 3.12)

project(sorting C CXX)

enable_testing()

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release")
endif()

set(CXX_FLAGS
  -g
  -Wall
  -Werror
  -Wshadow
  # -MMD
  -std=c++11
)
if(CMAKE_BUILD_BITS EQUAL 32)
	list(APPEND CXX_FLAGS "-m32")
endif()
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER, "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(EXECUTABLE_OUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/sort)

add_subdirectory(sort)