# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release

# Include any dependencies generated for this target.
include CMakeFiles/entitysystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/entitysystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/entitysystem.dir/flags.make

CMakeFiles/entitysystem.dir/src/Engine.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/Engine.cpp.o: ../../src/Engine.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/Engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/Engine.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/Engine.cpp

CMakeFiles/entitysystem.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/Engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/Engine.cpp > CMakeFiles/entitysystem.dir/src/Engine.cpp.i

CMakeFiles/entitysystem.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/Engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/Engine.cpp -o CMakeFiles/entitysystem.dir/src/Engine.cpp.s

CMakeFiles/entitysystem.dir/src/Engine.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/Engine.cpp.o.requires

CMakeFiles/entitysystem.dir/src/Engine.cpp.o.provides: CMakeFiles/entitysystem.dir/src/Engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/Engine.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/Engine.cpp.o.provides

CMakeFiles/entitysystem.dir/src/Engine.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/Engine.cpp.o

CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o: ../../src/EntityProcessingSystem.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/EntityProcessingSystem.cpp

CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/EntityProcessingSystem.cpp > CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.i

CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/EntityProcessingSystem.cpp -o CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.s

CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.requires

CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.provides: CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.provides

CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o

CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o: ../../src/EntityManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/EntityManager.cpp

CMakeFiles/entitysystem.dir/src/EntityManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/EntityManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/EntityManager.cpp > CMakeFiles/entitysystem.dir/src/EntityManager.cpp.i

CMakeFiles/entitysystem.dir/src/EntityManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/EntityManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/EntityManager.cpp -o CMakeFiles/entitysystem.dir/src/EntityManager.cpp.s

CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.requires

CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.provides: CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.provides

CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o

CMakeFiles/entitysystem.dir/src/TagManager.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/TagManager.cpp.o: ../../src/TagManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/TagManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/TagManager.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/TagManager.cpp

CMakeFiles/entitysystem.dir/src/TagManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/TagManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/TagManager.cpp > CMakeFiles/entitysystem.dir/src/TagManager.cpp.i

CMakeFiles/entitysystem.dir/src/TagManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/TagManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/TagManager.cpp -o CMakeFiles/entitysystem.dir/src/TagManager.cpp.s

CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.requires

CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.provides: CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.provides

CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/TagManager.cpp.o

CMakeFiles/entitysystem.dir/src/main.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/main.cpp.o: ../../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/main.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/main.cpp

CMakeFiles/entitysystem.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/main.cpp > CMakeFiles/entitysystem.dir/src/main.cpp.i

CMakeFiles/entitysystem.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/main.cpp -o CMakeFiles/entitysystem.dir/src/main.cpp.s

CMakeFiles/entitysystem.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/main.cpp.o.requires

CMakeFiles/entitysystem.dir/src/main.cpp.o.provides: CMakeFiles/entitysystem.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/main.cpp.o.provides

CMakeFiles/entitysystem.dir/src/main.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/main.cpp.o

CMakeFiles/entitysystem.dir/src/Entity.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/Entity.cpp.o: ../../src/Entity.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/Entity.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/Entity.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/Entity.cpp

CMakeFiles/entitysystem.dir/src/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/Entity.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/Entity.cpp > CMakeFiles/entitysystem.dir/src/Entity.cpp.i

CMakeFiles/entitysystem.dir/src/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/Entity.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/Entity.cpp -o CMakeFiles/entitysystem.dir/src/Entity.cpp.s

CMakeFiles/entitysystem.dir/src/Entity.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/Entity.cpp.o.requires

CMakeFiles/entitysystem.dir/src/Entity.cpp.o.provides: CMakeFiles/entitysystem.dir/src/Entity.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/Entity.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/Entity.cpp.o.provides

CMakeFiles/entitysystem.dir/src/Entity.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/Entity.cpp.o

CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o: ../../src/SystemManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/SystemManager.cpp

CMakeFiles/entitysystem.dir/src/SystemManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/SystemManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/SystemManager.cpp > CMakeFiles/entitysystem.dir/src/SystemManager.cpp.i

CMakeFiles/entitysystem.dir/src/SystemManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/SystemManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/SystemManager.cpp -o CMakeFiles/entitysystem.dir/src/SystemManager.cpp.s

CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.requires

CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.provides: CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.provides

CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o

CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o: ../../src/InputComponent.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/InputComponent.cpp

CMakeFiles/entitysystem.dir/src/InputComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/InputComponent.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/InputComponent.cpp > CMakeFiles/entitysystem.dir/src/InputComponent.cpp.i

CMakeFiles/entitysystem.dir/src/InputComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/InputComponent.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/InputComponent.cpp -o CMakeFiles/entitysystem.dir/src/InputComponent.cpp.s

CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.requires

CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.provides: CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.provides

CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o

CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o: CMakeFiles/entitysystem.dir/flags.make
CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o: ../../src/WindowManager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o -c /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/WindowManager.cpp

CMakeFiles/entitysystem.dir/src/WindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entitysystem.dir/src/WindowManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/WindowManager.cpp > CMakeFiles/entitysystem.dir/src/WindowManager.cpp.i

CMakeFiles/entitysystem.dir/src/WindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entitysystem.dir/src/WindowManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/src/WindowManager.cpp -o CMakeFiles/entitysystem.dir/src/WindowManager.cpp.s

CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.requires:
.PHONY : CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.requires

CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.provides: CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/entitysystem.dir/build.make CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.provides.build
.PHONY : CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.provides

CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.provides.build: CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o

# Object files for target entitysystem
entitysystem_OBJECTS = \
"CMakeFiles/entitysystem.dir/src/Engine.cpp.o" \
"CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o" \
"CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o" \
"CMakeFiles/entitysystem.dir/src/TagManager.cpp.o" \
"CMakeFiles/entitysystem.dir/src/main.cpp.o" \
"CMakeFiles/entitysystem.dir/src/Entity.cpp.o" \
"CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o" \
"CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o" \
"CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o"

# External object files for target entitysystem
entitysystem_EXTERNAL_OBJECTS =

../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/Engine.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/TagManager.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/main.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/Entity.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o
../../bin/entitysystem: CMakeFiles/entitysystem.dir/build.make
../../bin/entitysystem: ../../linux/x64/lib/libsfml-graphics.so
../../bin/entitysystem: ../../linux/x64/lib/libsfml-audio.so
../../bin/entitysystem: ../../linux/x64/lib/libsfml-window.so
../../bin/entitysystem: ../../linux/x64/lib/libsfml-network.so
../../bin/entitysystem: ../../linux/x64/lib/libsfml-system.so
../../bin/entitysystem: CMakeFiles/entitysystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/entitysystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/entitysystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/entitysystem.dir/build: ../../bin/entitysystem
.PHONY : CMakeFiles/entitysystem.dir/build

CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/Engine.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/EntityProcessingSystem.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/EntityManager.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/TagManager.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/main.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/Entity.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/SystemManager.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/InputComponent.cpp.o.requires
CMakeFiles/entitysystem.dir/requires: CMakeFiles/entitysystem.dir/src/WindowManager.cpp.o.requires
.PHONY : CMakeFiles/entitysystem.dir/requires

CMakeFiles/entitysystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/entitysystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/entitysystem.dir/clean

CMakeFiles/entitysystem.dir/depend:
	cd /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1 /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1 /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release /home/symphonym/Desktop/Projects/ENTITYSYSTEM_TEST_1/CMakeFiles/release/CMakeFiles/entitysystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/entitysystem.dir/depend

