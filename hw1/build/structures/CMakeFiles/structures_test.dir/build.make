# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /opt/software/software/CMake/3.16.4-GCCcore-9.3.0/bin/cmake

# The command to remove a file.
RM = /opt/software/software/CMake/3.16.4-GCCcore-9.3.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /homes/kevduong/Operating_systems/hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /homes/kevduong/Operating_systems/hw1/build

# Include any dependencies generated for this target.
include structures/CMakeFiles/structures_test.dir/depend.make

# Include the progress variables for this target.
include structures/CMakeFiles/structures_test.dir/progress.make

# Include the compile flags for this target's objects.
include structures/CMakeFiles/structures_test.dir/flags.make

structures/CMakeFiles/structures_test.dir/test/test.cpp.o: structures/CMakeFiles/structures_test.dir/flags.make
structures/CMakeFiles/structures_test.dir/test/test.cpp.o: ../structures/test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/homes/kevduong/Operating_systems/hw1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object structures/CMakeFiles/structures_test.dir/test/test.cpp.o"
	cd /homes/kevduong/Operating_systems/hw1/build/structures && /opt/software/software/GCCcore/9.3.0/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/structures_test.dir/test/test.cpp.o -c /homes/kevduong/Operating_systems/hw1/structures/test/test.cpp

structures/CMakeFiles/structures_test.dir/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/structures_test.dir/test/test.cpp.i"
	cd /homes/kevduong/Operating_systems/hw1/build/structures && /opt/software/software/GCCcore/9.3.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /homes/kevduong/Operating_systems/hw1/structures/test/test.cpp > CMakeFiles/structures_test.dir/test/test.cpp.i

structures/CMakeFiles/structures_test.dir/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/structures_test.dir/test/test.cpp.s"
	cd /homes/kevduong/Operating_systems/hw1/build/structures && /opt/software/software/GCCcore/9.3.0/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /homes/kevduong/Operating_systems/hw1/structures/test/test.cpp -o CMakeFiles/structures_test.dir/test/test.cpp.s

structures/CMakeFiles/structures_test.dir/src/structures.c.o: structures/CMakeFiles/structures_test.dir/flags.make
structures/CMakeFiles/structures_test.dir/src/structures.c.o: ../structures/src/structures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/homes/kevduong/Operating_systems/hw1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object structures/CMakeFiles/structures_test.dir/src/structures.c.o"
	cd /homes/kevduong/Operating_systems/hw1/build/structures && /opt/software/software/GCCcore/9.3.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/structures_test.dir/src/structures.c.o   -c /homes/kevduong/Operating_systems/hw1/structures/src/structures.c

structures/CMakeFiles/structures_test.dir/src/structures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/structures_test.dir/src/structures.c.i"
	cd /homes/kevduong/Operating_systems/hw1/build/structures && /opt/software/software/GCCcore/9.3.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /homes/kevduong/Operating_systems/hw1/structures/src/structures.c > CMakeFiles/structures_test.dir/src/structures.c.i

structures/CMakeFiles/structures_test.dir/src/structures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/structures_test.dir/src/structures.c.s"
	cd /homes/kevduong/Operating_systems/hw1/build/structures && /opt/software/software/GCCcore/9.3.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /homes/kevduong/Operating_systems/hw1/structures/src/structures.c -o CMakeFiles/structures_test.dir/src/structures.c.s

# Object files for target structures_test
structures_test_OBJECTS = \
"CMakeFiles/structures_test.dir/test/test.cpp.o" \
"CMakeFiles/structures_test.dir/src/structures.c.o"

# External object files for target structures_test
structures_test_EXTERNAL_OBJECTS =

structures/structures_test: structures/CMakeFiles/structures_test.dir/test/test.cpp.o
structures/structures_test: structures/CMakeFiles/structures_test.dir/src/structures.c.o
structures/structures_test: structures/CMakeFiles/structures_test.dir/build.make
structures/structures_test: structures/CMakeFiles/structures_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/homes/kevduong/Operating_systems/hw1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable structures_test"
	cd /homes/kevduong/Operating_systems/hw1/build/structures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/structures_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
structures/CMakeFiles/structures_test.dir/build: structures/structures_test

.PHONY : structures/CMakeFiles/structures_test.dir/build

structures/CMakeFiles/structures_test.dir/clean:
	cd /homes/kevduong/Operating_systems/hw1/build/structures && $(CMAKE_COMMAND) -P CMakeFiles/structures_test.dir/cmake_clean.cmake
.PHONY : structures/CMakeFiles/structures_test.dir/clean

structures/CMakeFiles/structures_test.dir/depend:
	cd /homes/kevduong/Operating_systems/hw1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/kevduong/Operating_systems/hw1 /homes/kevduong/Operating_systems/hw1/structures /homes/kevduong/Operating_systems/hw1/build /homes/kevduong/Operating_systems/hw1/build/structures /homes/kevduong/Operating_systems/hw1/build/structures/CMakeFiles/structures_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : structures/CMakeFiles/structures_test.dir/depend
