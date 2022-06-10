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
include libraries/ucpp/CMakeFiles/cpp.dir/depend.make

# Include the progress variables for this target.
include libraries/ucpp/CMakeFiles/cpp.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/ucpp/CMakeFiles/cpp.dir/flags.make

libraries/ucpp/CMakeFiles/cpp.dir/mem.c.o: libraries/ucpp/CMakeFiles/cpp.dir/flags.make
libraries/ucpp/CMakeFiles/cpp.dir/mem.c.o: ../libraries/ucpp/mem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libraries/ucpp/CMakeFiles/cpp.dir/mem.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpp.dir/mem.c.o -c /home/chuck/Src/goldfish/libraries/ucpp/mem.c

libraries/ucpp/CMakeFiles/cpp.dir/mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpp.dir/mem.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/ucpp/mem.c > CMakeFiles/cpp.dir/mem.c.i

libraries/ucpp/CMakeFiles/cpp.dir/mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpp.dir/mem.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/ucpp/mem.c -o CMakeFiles/cpp.dir/mem.c.s

libraries/ucpp/CMakeFiles/cpp.dir/nhash.c.o: libraries/ucpp/CMakeFiles/cpp.dir/flags.make
libraries/ucpp/CMakeFiles/cpp.dir/nhash.c.o: ../libraries/ucpp/nhash.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libraries/ucpp/CMakeFiles/cpp.dir/nhash.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpp.dir/nhash.c.o -c /home/chuck/Src/goldfish/libraries/ucpp/nhash.c

libraries/ucpp/CMakeFiles/cpp.dir/nhash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpp.dir/nhash.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/ucpp/nhash.c > CMakeFiles/cpp.dir/nhash.c.i

libraries/ucpp/CMakeFiles/cpp.dir/nhash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpp.dir/nhash.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/ucpp/nhash.c -o CMakeFiles/cpp.dir/nhash.c.s

libraries/ucpp/CMakeFiles/cpp.dir/cpp.c.o: libraries/ucpp/CMakeFiles/cpp.dir/flags.make
libraries/ucpp/CMakeFiles/cpp.dir/cpp.c.o: ../libraries/ucpp/cpp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object libraries/ucpp/CMakeFiles/cpp.dir/cpp.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpp.dir/cpp.c.o -c /home/chuck/Src/goldfish/libraries/ucpp/cpp.c

libraries/ucpp/CMakeFiles/cpp.dir/cpp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpp.dir/cpp.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/ucpp/cpp.c > CMakeFiles/cpp.dir/cpp.c.i

libraries/ucpp/CMakeFiles/cpp.dir/cpp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpp.dir/cpp.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/ucpp/cpp.c -o CMakeFiles/cpp.dir/cpp.c.s

libraries/ucpp/CMakeFiles/cpp.dir/lexer.c.o: libraries/ucpp/CMakeFiles/cpp.dir/flags.make
libraries/ucpp/CMakeFiles/cpp.dir/lexer.c.o: ../libraries/ucpp/lexer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object libraries/ucpp/CMakeFiles/cpp.dir/lexer.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpp.dir/lexer.c.o -c /home/chuck/Src/goldfish/libraries/ucpp/lexer.c

libraries/ucpp/CMakeFiles/cpp.dir/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpp.dir/lexer.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/ucpp/lexer.c > CMakeFiles/cpp.dir/lexer.c.i

libraries/ucpp/CMakeFiles/cpp.dir/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpp.dir/lexer.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/ucpp/lexer.c -o CMakeFiles/cpp.dir/lexer.c.s

libraries/ucpp/CMakeFiles/cpp.dir/assert.c.o: libraries/ucpp/CMakeFiles/cpp.dir/flags.make
libraries/ucpp/CMakeFiles/cpp.dir/assert.c.o: ../libraries/ucpp/assert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object libraries/ucpp/CMakeFiles/cpp.dir/assert.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpp.dir/assert.c.o -c /home/chuck/Src/goldfish/libraries/ucpp/assert.c

libraries/ucpp/CMakeFiles/cpp.dir/assert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpp.dir/assert.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/ucpp/assert.c > CMakeFiles/cpp.dir/assert.c.i

libraries/ucpp/CMakeFiles/cpp.dir/assert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpp.dir/assert.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/ucpp/assert.c -o CMakeFiles/cpp.dir/assert.c.s

libraries/ucpp/CMakeFiles/cpp.dir/macro.c.o: libraries/ucpp/CMakeFiles/cpp.dir/flags.make
libraries/ucpp/CMakeFiles/cpp.dir/macro.c.o: ../libraries/ucpp/macro.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object libraries/ucpp/CMakeFiles/cpp.dir/macro.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpp.dir/macro.c.o -c /home/chuck/Src/goldfish/libraries/ucpp/macro.c

libraries/ucpp/CMakeFiles/cpp.dir/macro.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpp.dir/macro.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/ucpp/macro.c > CMakeFiles/cpp.dir/macro.c.i

libraries/ucpp/CMakeFiles/cpp.dir/macro.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpp.dir/macro.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/ucpp/macro.c -o CMakeFiles/cpp.dir/macro.c.s

libraries/ucpp/CMakeFiles/cpp.dir/eval.c.o: libraries/ucpp/CMakeFiles/cpp.dir/flags.make
libraries/ucpp/CMakeFiles/cpp.dir/eval.c.o: ../libraries/ucpp/eval.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object libraries/ucpp/CMakeFiles/cpp.dir/eval.c.o"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cpp.dir/eval.c.o -c /home/chuck/Src/goldfish/libraries/ucpp/eval.c

libraries/ucpp/CMakeFiles/cpp.dir/eval.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cpp.dir/eval.c.i"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/libraries/ucpp/eval.c > CMakeFiles/cpp.dir/eval.c.i

libraries/ucpp/CMakeFiles/cpp.dir/eval.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cpp.dir/eval.c.s"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/libraries/ucpp/eval.c -o CMakeFiles/cpp.dir/eval.c.s

# Object files for target cpp
cpp_OBJECTS = \
"CMakeFiles/cpp.dir/mem.c.o" \
"CMakeFiles/cpp.dir/nhash.c.o" \
"CMakeFiles/cpp.dir/cpp.c.o" \
"CMakeFiles/cpp.dir/lexer.c.o" \
"CMakeFiles/cpp.dir/assert.c.o" \
"CMakeFiles/cpp.dir/macro.c.o" \
"CMakeFiles/cpp.dir/eval.c.o"

# External object files for target cpp
cpp_EXTERNAL_OBJECTS =

../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/mem.c.o
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/nhash.c.o
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/cpp.c.o
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/lexer.c.o
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/assert.c.o
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/macro.c.o
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/eval.c.o
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/build.make
../bin/cpp: libraries/ucpp/CMakeFiles/cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable ../../../bin/cpp"
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/ucpp/CMakeFiles/cpp.dir/build: ../bin/cpp

.PHONY : libraries/ucpp/CMakeFiles/cpp.dir/build

libraries/ucpp/CMakeFiles/cpp.dir/clean:
	cd /home/chuck/Src/goldfish/build/libraries/ucpp && $(CMAKE_COMMAND) -P CMakeFiles/cpp.dir/cmake_clean.cmake
.PHONY : libraries/ucpp/CMakeFiles/cpp.dir/clean

libraries/ucpp/CMakeFiles/cpp.dir/depend:
	cd /home/chuck/Src/goldfish/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuck/Src/goldfish /home/chuck/Src/goldfish/libraries/ucpp /home/chuck/Src/goldfish/build /home/chuck/Src/goldfish/build/libraries/ucpp /home/chuck/Src/goldfish/build/libraries/ucpp/CMakeFiles/cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libraries/ucpp/CMakeFiles/cpp.dir/depend

