cmake_minimum_required(VERSION 2.8)
project(ENTITYSYSTEM_TEST_1)

# Executable name

set(PROJ_EXE_NAME entitysystem)

set(PROJ_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(PROJ_LINUX_DIR "${CMAKE_SOURCE_DIR}/linux")
set(PROJ_WINDOWS_DIR "${CMAKE_SOURCE_DIR}/windows")
set(PROJ_MAC_DIR "${CMAKE_SOURCE_DIR}/osx")

set(EXECUTABLE_OUTPUT_PATH ${PROJ_BIN_DIR})

# Append "_dev" to exe name if debugging

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(PROJ_EXE_NAME "${PROJ_EXE_NAME}_dev")
endif()

# Detect system architechture

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(PROJ_SYS_ARCH "x64")
else()
	set(PROJ_SYS_ARCH "x32")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
	add_definitions("-std=c++11")
endif()

# Platform specific options

if(UNIX)
	set(PROJ_LIBRARY_DIR "${PROJ_LINUX_DIR}/${PROJ_SYS_ARCH}/lib")
	set(PROJ_INCLUDE_DIR "${PROJ_LINUX_DIR}/${PROJ_SYS_ARCH}/include")

	set(CMAKE_INSTALL_RPATH "\$ORIGIN/lib")
	set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 

	file(COPY ${PROJ_LIBRARY_DIR} DESTINATION ${PROJ_BIN_DIR})
elseif(WIN32)
	set(PROJ_LIBRARY_DIR "${PROJ_WINDOWS_DIR}/${PROJ_SYS_ARCH}/lib")
	set(PROJ_INCLUDE_DIR "${PROJ_WINDOWS_DIR}/${PROJ_SYS_ARCH}/include")
elseif(APPLE)
	set(PROJ_LIBRARY_DIR "${PROJ_APPLE_DIR}/${PROJ_SYS_ARCH}/lib")
	set(PROJ_INCLUDE_DIR "${PROJ_APPLE_DIR}/${PROJ_SYS_ARCH}/include")
endif()

#file(GLOB PROJ_LIBRARY_FILES "${PROJ_LIBRARY_DIR}/*${PROJ_LIBRARY_EXTENSION}")
#file(COPY )

# Find libraries

find_library(SFML_GRAPHICS_LIB sfml-graphics ${PROJ_LIBRARY_DIR})
find_library(SFML_AUDIO_LIB sfml-audio ${PROJ_LIBRARY_DIR})
find_library(SFML_WINDOW_LIB sfml-window ${PROJ_LIBRARY_DIR})
find_library(SFML_NETWORK_LIB sfml-network ${PROJ_LIBRARY_DIR})
find_library(SFML_SYSTEM_LIB sfml-system ${PROJ_LIBRARY_DIR})

# Include headers

include_directories(${PROJ_INCLUDE_DIR})

# Glob files, add exe and finally link libraries

file(GLOB PROJ_SOURCE_FILES "src/*.cpp")

if(PROJ_SOURCE_FILES)
	add_executable(${PROJ_EXE_NAME} ${PROJ_SOURCE_FILES})
	target_link_libraries(${PROJ_EXE_NAME} ${SFML_GRAPHICS_LIB})
	target_link_libraries(${PROJ_EXE_NAME} ${SFML_AUDIO_LIB})
	target_link_libraries(${PROJ_EXE_NAME} ${SFML_WINDOW_LIB})
	target_link_libraries(${PROJ_EXE_NAME} ${SFML_NETWORK_LIB})
	target_link_libraries(${PROJ_EXE_NAME} ${SFML_SYSTEM_LIB})
endif()