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
CMAKE_SOURCE_DIR = /home/chuck/Src/goldfish/src/libraries/gc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chuck/Src/goldfish/src/libraries/gc/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/hugetest.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/hugetest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/hugetest.dir/flags.make

tests/CMakeFiles/hugetest.dir/huge_test.c.o: tests/CMakeFiles/hugetest.dir/flags.make
tests/CMakeFiles/hugetest.dir/huge_test.c.o: ../tests/huge_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/hugetest.dir/huge_test.c.o"
	cd /home/chuck/Src/goldfish/src/libraries/gc/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hugetest.dir/huge_test.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/tests/huge_test.c

tests/CMakeFiles/hugetest.dir/huge_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hugetest.dir/huge_test.c.i"
	cd /home/chuck/Src/goldfish/src/libraries/gc/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/tests/huge_test.c > CMakeFiles/hugetest.dir/huge_test.c.i

tests/CMakeFiles/hugetest.dir/huge_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hugetest.dir/huge_test.c.s"
	cd /home/chuck/Src/goldfish/src/libraries/gc/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/tests/huge_test.c -o CMakeFiles/hugetest.dir/huge_test.c.s

# Object files for target hugetest
hugetest_OBJECTS = \
"CMakeFiles/hugetest.dir/huge_test.c.o"

# External object files for target hugetest
hugetest_EXTERNAL_OBJECTS =

tests/hugetest: tests/CMakeFiles/hugetest.dir/huge_test.c.o
tests/hugetest: tests/CMakeFiles/hugetest.dir/build.make
tests/hugetest: libgc-lib.a
tests/hugetest: tests/CMakeFiles/hugetest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hugetest"
	cd /home/chuck/Src/goldfish/src/libraries/gc/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hugetest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/hugetest.dir/build: tests/hugetest

.PHONY : tests/CMakeFiles/hugetest.dir/build

tests/CMakeFiles/hugetest.dir/clean:
	cd /home/chuck/Src/goldfish/src/libraries/gc/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/hugetest.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/hugetest.dir/clean

tests/CMakeFiles/hugetest.dir/depend:
	cd /home/chuck/Src/goldfish/src/libraries/gc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuck/Src/goldfish/src/libraries/gc /home/chuck/Src/goldfish/src/libraries/gc/tests /home/chuck/Src/goldfish/src/libraries/gc/build /home/chuck/Src/goldfish/src/libraries/gc/build/tests /home/chuck/Src/goldfish/src/libraries/gc/build/tests/CMakeFiles/hugetest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/hugetest.dir/depend

