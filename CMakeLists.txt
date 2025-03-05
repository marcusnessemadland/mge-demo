cmake_minimum_required(VERSION 3.10.2) 
project(vulkan-renderer-demo)
cmake_policy(SET CMP0054 NEW)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Makefile generators on apple need this flag to compile mixed objective/c++
if(APPLE AND NOT XCODE)
	set(CMAKE_CXX_FLAGS "-ObjC++")
endif()

include(CMakeDependentOption)

option(BX_AMALGAMATED "Amalgamated bx build for faster compilation" OFF)
option(BX_CONFIG_DEBUG "Log debug messages (default: on in debug)" OFF)
option(BX_BUILD_TESTS "Build tests" OFF)

set(VR_LIBRARY_TYPE "STATIC" CACHE STRING "Linking type for library")
set_property(CACHE VR_LIBRARY_TYPE PROPERTY STRINGS "STATIC" "SHARED")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vulkan-renderer)

#
file(
	GLOB_RECURSE
	DEMO_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)
add_executable(vulkan-renderer-demo ${DEMO_SOURCES})
target_link_libraries(vulkan-renderer-demo PRIVATE vulkan-renderer)