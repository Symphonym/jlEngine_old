cmake_minimum_required(VERSION 2.8)
project(ENTITYSYSTEM_TEST_1)

# Executable name

set(PROJ_EXE_NAME entitysystem)

set(PROJ_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJ_BIN_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(PROJ_EXE_NAME "${PROJ_EXE_NAME}_dev")
endif()

add_definitions("-std=c++11")

file(GLOB PROJ_SOURCE_FILES "src/*.cpp")

add_executable(${PROJ_EXE_NAME} ${PROJ_SOURCE_FILES})