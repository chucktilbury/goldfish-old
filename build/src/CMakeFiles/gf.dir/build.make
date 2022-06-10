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
include src/CMakeFiles/gf.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/gf.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/gf.dir/flags.make

../src/parser.c: ../src/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../src/parser.c, /parser.h"
	cd /home/chuck/Src/goldfish/src && bison --report=lookahead -tvdo parser.c parser.y

/parser.h: ../src/parser.c
	@$(CMAKE_COMMAND) -E touch_nocreate /parser.h

../src/scanner.c: ../src/scanner.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating ../../src/scanner.c"
	cd /home/chuck/Src/goldfish/src && flex -i -o scanner.c scanner.l

src/CMakeFiles/gf.dir/main.c.o: src/CMakeFiles/gf.dir/flags.make
src/CMakeFiles/gf.dir/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/gf.dir/main.c.o"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gf.dir/main.c.o -c /home/chuck/Src/goldfish/src/main.c

src/CMakeFiles/gf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gf.dir/main.c.i"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/main.c > CMakeFiles/gf.dir/main.c.i

src/CMakeFiles/gf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gf.dir/main.c.s"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/main.c -o CMakeFiles/gf.dir/main.c.s

src/CMakeFiles/gf.dir/cmdline.c.o: src/CMakeFiles/gf.dir/flags.make
src/CMakeFiles/gf.dir/cmdline.c.o: ../src/cmdline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/gf.dir/cmdline.c.o"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gf.dir/cmdline.c.o -c /home/chuck/Src/goldfish/src/cmdline.c

src/CMakeFiles/gf.dir/cmdline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gf.dir/cmdline.c.i"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/cmdline.c > CMakeFiles/gf.dir/cmdline.c.i

src/CMakeFiles/gf.dir/cmdline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gf.dir/cmdline.c.s"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/cmdline.c -o CMakeFiles/gf.dir/cmdline.c.s

src/CMakeFiles/gf.dir/symtable.c.o: src/CMakeFiles/gf.dir/flags.make
src/CMakeFiles/gf.dir/symtable.c.o: ../src/symtable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/gf.dir/symtable.c.o"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gf.dir/symtable.c.o -c /home/chuck/Src/goldfish/src/symtable.c

src/CMakeFiles/gf.dir/symtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gf.dir/symtable.c.i"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/symtable.c > CMakeFiles/gf.dir/symtable.c.i

src/CMakeFiles/gf.dir/symtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gf.dir/symtable.c.s"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/symtable.c -o CMakeFiles/gf.dir/symtable.c.s

src/CMakeFiles/gf.dir/errors.c.o: src/CMakeFiles/gf.dir/flags.make
src/CMakeFiles/gf.dir/errors.c.o: ../src/errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/gf.dir/errors.c.o"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gf.dir/errors.c.o -c /home/chuck/Src/goldfish/src/errors.c

src/CMakeFiles/gf.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gf.dir/errors.c.i"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/errors.c > CMakeFiles/gf.dir/errors.c.i

src/CMakeFiles/gf.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gf.dir/errors.c.s"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/errors.c -o CMakeFiles/gf.dir/errors.c.s

src/CMakeFiles/gf.dir/parser.c.o: src/CMakeFiles/gf.dir/flags.make
src/CMakeFiles/gf.dir/parser.c.o: ../src/parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/CMakeFiles/gf.dir/parser.c.o"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gf.dir/parser.c.o -c /home/chuck/Src/goldfish/src/parser.c

src/CMakeFiles/gf.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gf.dir/parser.c.i"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/parser.c > CMakeFiles/gf.dir/parser.c.i

src/CMakeFiles/gf.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gf.dir/parser.c.s"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/parser.c -o CMakeFiles/gf.dir/parser.c.s

src/CMakeFiles/gf.dir/scanner.c.o: src/CMakeFiles/gf.dir/flags.make
src/CMakeFiles/gf.dir/scanner.c.o: ../src/scanner.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/CMakeFiles/gf.dir/scanner.c.o"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gf.dir/scanner.c.o -c /home/chuck/Src/goldfish/src/scanner.c

src/CMakeFiles/gf.dir/scanner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gf.dir/scanner.c.i"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/scanner.c > CMakeFiles/gf.dir/scanner.c.i

src/CMakeFiles/gf.dir/scanner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gf.dir/scanner.c.s"
	cd /home/chuck/Src/goldfish/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/scanner.c -o CMakeFiles/gf.dir/scanner.c.s

# Object files for target gf
gf_OBJECTS = \
"CMakeFiles/gf.dir/main.c.o" \
"CMakeFiles/gf.dir/cmdline.c.o" \
"CMakeFiles/gf.dir/symtable.c.o" \
"CMakeFiles/gf.dir/errors.c.o" \
"CMakeFiles/gf.dir/parser.c.o" \
"CMakeFiles/gf.dir/scanner.c.o"

# External object files for target gf
gf_EXTERNAL_OBJECTS =

../bin/gf: src/CMakeFiles/gf.dir/main.c.o
../bin/gf: src/CMakeFiles/gf.dir/cmdline.c.o
../bin/gf: src/CMakeFiles/gf.dir/symtable.c.o
../bin/gf: src/CMakeFiles/gf.dir/errors.c.o
../bin/gf: src/CMakeFiles/gf.dir/parser.c.o
../bin/gf: src/CMakeFiles/gf.dir/scanner.c.o
../bin/gf: src/CMakeFiles/gf.dir/build.make
../bin/gf: ../bin/libgc-lib.a
../bin/gf: src/CMakeFiles/gf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuck/Src/goldfish/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ../../bin/gf"
	cd /home/chuck/Src/goldfish/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/gf.dir/build: ../bin/gf

.PHONY : src/CMakeFiles/gf.dir/build

src/CMakeFiles/gf.dir/clean:
	cd /home/chuck/Src/goldfish/build/src && $(CMAKE_COMMAND) -P CMakeFiles/gf.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/gf.dir/clean

src/CMakeFiles/gf.dir/depend: ../src/parser.c
src/CMakeFiles/gf.dir/depend: /parser.h
src/CMakeFiles/gf.dir/depend: ../src/scanner.c
	cd /home/chuck/Src/goldfish/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuck/Src/goldfish /home/chuck/Src/goldfish/src /home/chuck/Src/goldfish/build /home/chuck/Src/goldfish/build/src /home/chuck/Src/goldfish/build/src/CMakeFiles/gf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/gf.dir/depend

