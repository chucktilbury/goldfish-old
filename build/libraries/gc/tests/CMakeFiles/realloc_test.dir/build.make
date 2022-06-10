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
include libraries/gc/tests/CMakeFiles/realloc_test.dir/depend.make

# Include the progress variables for this target.
include libraries/gc/tests/CMakeFiles/realloc_test.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/gc/tests/CMakeFiles/realloc_test.dir/flags.make

libraries/gc/tests/CMakeFiles/realloc_test.dir/realloc_test.c.o: libraries/gc/tests/CMakeFiles/realloc_test.dir/flags.make
libraries/gc/tests/CMakeFiles/realloc_test.dir/realloc_test.c.o: ../libraries/gc/tests/realloc_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libraries/gc/tests/CMakeFiles/realloc_test.dir/realloc_test.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/realloc_test.dir/realloc_test.c.o -c /home/chuck/Src/goldfish/libraries/gc/tests/realloc_test.c

libraries/gc/tests/CMakeFiles/realloc_test.dir/realloc_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/realloc_test.dir/realloc_test.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/gc/tests/realloc_test.c > CMakeFiles/realloc_test.dir/realloc_test.c.i

libraries/gc/tests/CMakeFiles/realloc_test.dir/realloc_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/realloc_test.dir/realloc_test.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/gc/tests/realloc_test.c -o CMakeFiles/realloc_test.dir/realloc_test.c.s

# Object files for target realloc_test
realloc_test_OBJECTS = \
"CMakeFiles/realloc_test.dir/realloc_test.c.o"

# External object files for target realloc_test
realloc_test_EXTERNAL_OBJECTS =

../bin/realloc_test: libraries/gc/tests/CMakeFiles/realloc_test.dir/realloc_test.c.o
../bin/realloc_test: libraries/gc/tests/CMakeFiles/realloc_test.dir/build.make
../bin/realloc_test: ../bin/libgc-lib.a
../bin/realloc_test: libraries/gc/tests/CMakeFiles/realloc_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/realloc_test"
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/realloc_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/gc/tests/CMakeFiles/realloc_test.dir/build: ../bin/realloc_test

.PHONY : libraries/gc/tests/CMakeFiles/realloc_test.dir/build

libraries/gc/tests/CMakeFiles/realloc_test.dir/clean:
	cd /home/chuck/Src/goldfish/build/libraries/gc/tests && $(CMAKE_COMMAND) -P CMakeFiles/realloc_test.dir/cmake_clean.cmake
.PHONY : libraries/gc/tests/CMakeFiles/realloc_test.dir/clean

libraries/gc/tests/CMakeFiles/realloc_test.dir/depend:
	cd /home/chuck/Src/goldfish/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuck/Src/goldfish /home/chuck/Src/goldfish/libraries/gc/tests /home/chuck/Src/goldfish/build /home/chuck/Src/goldfish/build/libraries/gc/tests /home/chuck/Src/goldfish/build/libraries/gc/tests/CMakeFiles/realloc_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libraries/gc/tests/CMakeFiles/realloc_test.dir/depend

