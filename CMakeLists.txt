cmake_minimum_required(VERSION 3.10.2) # version supported by android studio
project(demo)
cmake_policy(SET CMP0054 NEW)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE
     SOURCE_FILES
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.mm
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

add_subdirectory(mge)

add_executable( ${PROJECT_NAME} "${SOURCE_FILES}")

target_link_libraries(${PROJECT_NAME} mge)

target_compile_definitions(
		${PROJECT_NAME}
		PRIVATE 
        	"-D_CRT_SECURE_NO_WARNINGS" #
		"-D__STDC_FORMAT_MACROS" #
	)

set_property(
    TARGET 
    ${PROJECT_NAME} 
    PROPERTY 
    VS_DEBUGGER_WORKING_DIRECTORY 
    "${CMAKE_CURRENT_SOURCE_DIR}/runtime")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/mge/include/mge/)