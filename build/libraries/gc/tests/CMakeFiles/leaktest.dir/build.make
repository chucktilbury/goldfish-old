# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chuck/Src/goldfish

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chuck/Src/goldfish/build

# Include any dependencies generated for this target.
include libraries/gc/tests/CMakeFiles/leaktest.dir/depend.make

# Include the progress variables for this target.
include libraries/gc/tests/CMakeFiles/leaktest.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/gc/tests/CMakeFiles/leaktest.dir/flags.make

libraries/gc/tests/CMakeFiles/leaktest.dir/leak_test.c.o: libraries/gc/tests/CMakeFiles/leaktest.dir/flags.make
libraries/gc/tests/CMakeFiles/leaktest.dir/leak_test.c.o: ../libraries/gc/tests/leak_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/gc/tests/CMakeFiles/leaktest.dir/leak_test.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leaktest.dir/leak_test.c.o -c /home/chuck/Src/goldfish/libraries/gc/tests/leak_test.c

libraries/gc/tests/CMakeFiles/leaktest.dir/leak_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leaktest.dir/leak_test.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chuck/Src/goldfish/libraries/gc/tests/leak_test.c > CMakeFiles/leaktest.dir/leak_test.c.i

libraries/gc/tests/CMakeFiles/leaktest.dir/leak_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leaktest.dir/leak_test.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chuck/Src/goldfish/libraries/gc/tests/leak_test.c -o CMakeFiles/leaktest.dir/leak_test.c.s

# Object files for target leaktest
leaktest_OBJECTS = \
"CMakeFiles/leaktest.dir/leak_test.c.o"

# External object files for target leaktest
leaktest_EXTERNAL_OBJECTS =

../bin/leaktest: libraries/gc/tests/CMakeFiles/leaktest.dir/leak_test.c.o
../bin/leaktest: libraries/gc/tests/CMakeFiles/leaktest.dir/build.make
../bin/leaktest: ../bin/libgc-lib.a
../bin/leaktest: libraries/gc/tests/CMakeFiles/leaktest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/leaktest"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leaktest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/gc/tests/CMakeFiles/leaktest.dir/build: ../bin/leaktest

.PHONY : libraries/gc/tests/CMakeFiles/leaktest.dir/build

libraries/gc/tests/CMakeFiles/leaktest.dir/clean:
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && $(CMAKE_COMMAND) -P CMakeFiles/leaktest.dir/cmake_clean.cmake
.PHONY : libraries/gc/tests/CMakeFiles/leaktest.dir/clean

libraries/gc/tests/CMakeFiles/leaktest.dir/depend:
	cd /home/chuck/Src/goldfish/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuck/Src/goldfish /home/chuck/Src/goldfish/libraries/gc/tests /home/chuck/Src/goldfish/build /home/chuck/Src/goldfish/build/libraries/gc/tests /home/chuck/Src/goldfish/build/libraries/gc/tests/CMakeFiles/leaktest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libraries/gc/tests/CMakeFiles/leaktest.dir/depend

