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
include CMakeFiles/gcmt-dll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gcmt-dll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gcmt-dll.dir/flags.make

CMakeFiles/gcmt-dll.dir/alloc.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/alloc.c.o: ../alloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/gcmt-dll.dir/alloc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/alloc.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/alloc.c

CMakeFiles/gcmt-dll.dir/alloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/alloc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/alloc.c > CMakeFiles/gcmt-dll.dir/alloc.c.i

CMakeFiles/gcmt-dll.dir/alloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/alloc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/alloc.c -o CMakeFiles/gcmt-dll.dir/alloc.c.s

CMakeFiles/gcmt-dll.dir/reclaim.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/reclaim.c.o: ../reclaim.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/gcmt-dll.dir/reclaim.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/reclaim.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/reclaim.c

CMakeFiles/gcmt-dll.dir/reclaim.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/reclaim.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/reclaim.c > CMakeFiles/gcmt-dll.dir/reclaim.c.i

CMakeFiles/gcmt-dll.dir/reclaim.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/reclaim.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/reclaim.c -o CMakeFiles/gcmt-dll.dir/reclaim.c.s

CMakeFiles/gcmt-dll.dir/allchblk.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/allchblk.c.o: ../allchblk.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/gcmt-dll.dir/allchblk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/allchblk.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/allchblk.c

CMakeFiles/gcmt-dll.dir/allchblk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/allchblk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/allchblk.c > CMakeFiles/gcmt-dll.dir/allchblk.c.i

CMakeFiles/gcmt-dll.dir/allchblk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/allchblk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/allchblk.c -o CMakeFiles/gcmt-dll.dir/allchblk.c.s

CMakeFiles/gcmt-dll.dir/misc.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/misc.c.o: ../misc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/gcmt-dll.dir/misc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/misc.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/misc.c

CMakeFiles/gcmt-dll.dir/misc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/misc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/misc.c > CMakeFiles/gcmt-dll.dir/misc.c.i

CMakeFiles/gcmt-dll.dir/misc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/misc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/misc.c -o CMakeFiles/gcmt-dll.dir/misc.c.s

CMakeFiles/gcmt-dll.dir/mach_dep.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/mach_dep.c.o: ../mach_dep.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/gcmt-dll.dir/mach_dep.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/mach_dep.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/mach_dep.c

CMakeFiles/gcmt-dll.dir/mach_dep.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/mach_dep.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/mach_dep.c > CMakeFiles/gcmt-dll.dir/mach_dep.c.i

CMakeFiles/gcmt-dll.dir/mach_dep.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/mach_dep.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/mach_dep.c -o CMakeFiles/gcmt-dll.dir/mach_dep.c.s

CMakeFiles/gcmt-dll.dir/os_dep.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/os_dep.c.o: ../os_dep.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/gcmt-dll.dir/os_dep.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/os_dep.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/os_dep.c

CMakeFiles/gcmt-dll.dir/os_dep.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/os_dep.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/os_dep.c > CMakeFiles/gcmt-dll.dir/os_dep.c.i

CMakeFiles/gcmt-dll.dir/os_dep.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/os_dep.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/os_dep.c -o CMakeFiles/gcmt-dll.dir/os_dep.c.s

CMakeFiles/gcmt-dll.dir/mark_rts.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/mark_rts.c.o: ../mark_rts.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/gcmt-dll.dir/mark_rts.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/mark_rts.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/mark_rts.c

CMakeFiles/gcmt-dll.dir/mark_rts.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/mark_rts.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/mark_rts.c > CMakeFiles/gcmt-dll.dir/mark_rts.c.i

CMakeFiles/gcmt-dll.dir/mark_rts.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/mark_rts.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/mark_rts.c -o CMakeFiles/gcmt-dll.dir/mark_rts.c.s

CMakeFiles/gcmt-dll.dir/headers.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/headers.c.o: ../headers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/gcmt-dll.dir/headers.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/headers.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/headers.c

CMakeFiles/gcmt-dll.dir/headers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/headers.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/headers.c > CMakeFiles/gcmt-dll.dir/headers.c.i

CMakeFiles/gcmt-dll.dir/headers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/headers.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/headers.c -o CMakeFiles/gcmt-dll.dir/headers.c.s

CMakeFiles/gcmt-dll.dir/mark.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/mark.c.o: ../mark.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/gcmt-dll.dir/mark.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/mark.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/mark.c

CMakeFiles/gcmt-dll.dir/mark.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/mark.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/mark.c > CMakeFiles/gcmt-dll.dir/mark.c.i

CMakeFiles/gcmt-dll.dir/mark.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/mark.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/mark.c -o CMakeFiles/gcmt-dll.dir/mark.c.s

CMakeFiles/gcmt-dll.dir/obj_map.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/obj_map.c.o: ../obj_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/gcmt-dll.dir/obj_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/obj_map.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/obj_map.c

CMakeFiles/gcmt-dll.dir/obj_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/obj_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/obj_map.c > CMakeFiles/gcmt-dll.dir/obj_map.c.i

CMakeFiles/gcmt-dll.dir/obj_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/obj_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/obj_map.c -o CMakeFiles/gcmt-dll.dir/obj_map.c.s

CMakeFiles/gcmt-dll.dir/blacklst.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/blacklst.c.o: ../blacklst.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/gcmt-dll.dir/blacklst.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/blacklst.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/blacklst.c

CMakeFiles/gcmt-dll.dir/blacklst.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/blacklst.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/blacklst.c > CMakeFiles/gcmt-dll.dir/blacklst.c.i

CMakeFiles/gcmt-dll.dir/blacklst.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/blacklst.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/blacklst.c -o CMakeFiles/gcmt-dll.dir/blacklst.c.s

CMakeFiles/gcmt-dll.dir/finalize.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/finalize.c.o: ../finalize.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/gcmt-dll.dir/finalize.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/finalize.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/finalize.c

CMakeFiles/gcmt-dll.dir/finalize.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/finalize.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/finalize.c > CMakeFiles/gcmt-dll.dir/finalize.c.i

CMakeFiles/gcmt-dll.dir/finalize.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/finalize.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/finalize.c -o CMakeFiles/gcmt-dll.dir/finalize.c.s

CMakeFiles/gcmt-dll.dir/new_hblk.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/new_hblk.c.o: ../new_hblk.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/gcmt-dll.dir/new_hblk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/new_hblk.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/new_hblk.c

CMakeFiles/gcmt-dll.dir/new_hblk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/new_hblk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/new_hblk.c > CMakeFiles/gcmt-dll.dir/new_hblk.c.i

CMakeFiles/gcmt-dll.dir/new_hblk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/new_hblk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/new_hblk.c -o CMakeFiles/gcmt-dll.dir/new_hblk.c.s

CMakeFiles/gcmt-dll.dir/dbg_mlc.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/dbg_mlc.c.o: ../dbg_mlc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/gcmt-dll.dir/dbg_mlc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/dbg_mlc.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/dbg_mlc.c

CMakeFiles/gcmt-dll.dir/dbg_mlc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/dbg_mlc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/dbg_mlc.c > CMakeFiles/gcmt-dll.dir/dbg_mlc.c.i

CMakeFiles/gcmt-dll.dir/dbg_mlc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/dbg_mlc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/dbg_mlc.c -o CMakeFiles/gcmt-dll.dir/dbg_mlc.c.s

CMakeFiles/gcmt-dll.dir/malloc.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/malloc.c.o: ../malloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/gcmt-dll.dir/malloc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/malloc.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/malloc.c

CMakeFiles/gcmt-dll.dir/malloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/malloc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/malloc.c > CMakeFiles/gcmt-dll.dir/malloc.c.i

CMakeFiles/gcmt-dll.dir/malloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/malloc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/malloc.c -o CMakeFiles/gcmt-dll.dir/malloc.c.s

CMakeFiles/gcmt-dll.dir/dyn_load.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/dyn_load.c.o: ../dyn_load.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/gcmt-dll.dir/dyn_load.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/dyn_load.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/dyn_load.c

CMakeFiles/gcmt-dll.dir/dyn_load.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/dyn_load.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/dyn_load.c > CMakeFiles/gcmt-dll.dir/dyn_load.c.i

CMakeFiles/gcmt-dll.dir/dyn_load.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/dyn_load.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/dyn_load.c -o CMakeFiles/gcmt-dll.dir/dyn_load.c.s

CMakeFiles/gcmt-dll.dir/typd_mlc.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/typd_mlc.c.o: ../typd_mlc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/gcmt-dll.dir/typd_mlc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/typd_mlc.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/typd_mlc.c

CMakeFiles/gcmt-dll.dir/typd_mlc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/typd_mlc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/typd_mlc.c > CMakeFiles/gcmt-dll.dir/typd_mlc.c.i

CMakeFiles/gcmt-dll.dir/typd_mlc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/typd_mlc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/typd_mlc.c -o CMakeFiles/gcmt-dll.dir/typd_mlc.c.s

CMakeFiles/gcmt-dll.dir/ptr_chck.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/ptr_chck.c.o: ../ptr_chck.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/gcmt-dll.dir/ptr_chck.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/ptr_chck.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/ptr_chck.c

CMakeFiles/gcmt-dll.dir/ptr_chck.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/ptr_chck.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/ptr_chck.c > CMakeFiles/gcmt-dll.dir/ptr_chck.c.i

CMakeFiles/gcmt-dll.dir/ptr_chck.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/ptr_chck.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/ptr_chck.c -o CMakeFiles/gcmt-dll.dir/ptr_chck.c.s

CMakeFiles/gcmt-dll.dir/mallocx.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/mallocx.c.o: ../mallocx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/gcmt-dll.dir/mallocx.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/mallocx.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/mallocx.c

CMakeFiles/gcmt-dll.dir/mallocx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/mallocx.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/mallocx.c > CMakeFiles/gcmt-dll.dir/mallocx.c.i

CMakeFiles/gcmt-dll.dir/mallocx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/mallocx.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/mallocx.c -o CMakeFiles/gcmt-dll.dir/mallocx.c.s

CMakeFiles/gcmt-dll.dir/gc_cpp.cc.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/gc_cpp.cc.o: ../gc_cpp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/gcmt-dll.dir/gc_cpp.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gcmt-dll.dir/gc_cpp.cc.o -c /home/chuck/Src/goldfish/src/libraries/gc/gc_cpp.cc

CMakeFiles/gcmt-dll.dir/gc_cpp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gcmt-dll.dir/gc_cpp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/gc_cpp.cc > CMakeFiles/gcmt-dll.dir/gc_cpp.cc.i

CMakeFiles/gcmt-dll.dir/gc_cpp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gcmt-dll.dir/gc_cpp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/gc_cpp.cc -o CMakeFiles/gcmt-dll.dir/gc_cpp.cc.s

CMakeFiles/gcmt-dll.dir/gcj_mlc.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/gcj_mlc.c.o: ../gcj_mlc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/gcmt-dll.dir/gcj_mlc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/gcj_mlc.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/gcj_mlc.c

CMakeFiles/gcmt-dll.dir/gcj_mlc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/gcj_mlc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/gcj_mlc.c > CMakeFiles/gcmt-dll.dir/gcj_mlc.c.i

CMakeFiles/gcmt-dll.dir/gcj_mlc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/gcj_mlc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/gcj_mlc.c -o CMakeFiles/gcmt-dll.dir/gcj_mlc.c.s

CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.o: CMakeFiles/gcmt-dll.dir/flags.make
CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.o: ../fnlz_mlc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building C object CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.o -c /home/chuck/Src/goldfish/src/libraries/gc/fnlz_mlc.c

CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/chuck/Src/goldfish/src/libraries/gc/fnlz_mlc.c > CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.i

CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/chuck/Src/goldfish/src/libraries/gc/fnlz_mlc.c -o CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.s

# Object files for target gcmt-dll
gcmt__dll_OBJECTS = \
"CMakeFiles/gcmt-dll.dir/alloc.c.o" \
"CMakeFiles/gcmt-dll.dir/reclaim.c.o" \
"CMakeFiles/gcmt-dll.dir/allchblk.c.o" \
"CMakeFiles/gcmt-dll.dir/misc.c.o" \
"CMakeFiles/gcmt-dll.dir/mach_dep.c.o" \
"CMakeFiles/gcmt-dll.dir/os_dep.c.o" \
"CMakeFiles/gcmt-dll.dir/mark_rts.c.o" \
"CMakeFiles/gcmt-dll.dir/headers.c.o" \
"CMakeFiles/gcmt-dll.dir/mark.c.o" \
"CMakeFiles/gcmt-dll.dir/obj_map.c.o" \
"CMakeFiles/gcmt-dll.dir/blacklst.c.o" \
"CMakeFiles/gcmt-dll.dir/finalize.c.o" \
"CMakeFiles/gcmt-dll.dir/new_hblk.c.o" \
"CMakeFiles/gcmt-dll.dir/dbg_mlc.c.o" \
"CMakeFiles/gcmt-dll.dir/malloc.c.o" \
"CMakeFiles/gcmt-dll.dir/dyn_load.c.o" \
"CMakeFiles/gcmt-dll.dir/typd_mlc.c.o" \
"CMakeFiles/gcmt-dll.dir/ptr_chck.c.o" \
"CMakeFiles/gcmt-dll.dir/mallocx.c.o" \
"CMakeFiles/gcmt-dll.dir/gc_cpp.cc.o" \
"CMakeFiles/gcmt-dll.dir/gcj_mlc.c.o" \
"CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.o"

# External object files for target gcmt-dll
gcmt__dll_EXTERNAL_OBJECTS =

libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/alloc.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/reclaim.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/allchblk.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/misc.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/mach_dep.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/os_dep.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/mark_rts.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/headers.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/mark.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/obj_map.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/blacklst.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/finalize.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/new_hblk.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/dbg_mlc.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/malloc.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/dyn_load.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/typd_mlc.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/ptr_chck.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/mallocx.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/gc_cpp.cc.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/gcj_mlc.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/fnlz_mlc.c.o
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/build.make
libgcmt-dll.so: CMakeFiles/gcmt-dll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Linking CXX shared library libgcmt-dll.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gcmt-dll.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gcmt-dll.dir/build: libgcmt-dll.so

.PHONY : CMakeFiles/gcmt-dll.dir/build

CMakeFiles/gcmt-dll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gcmt-dll.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gcmt-dll.dir/clean

CMakeFiles/gcmt-dll.dir/depend:
	cd /home/chuck/Src/goldfish/src/libraries/gc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuck/Src/goldfish/src/libraries/gc /home/chuck/Src/goldfish/src/libraries/gc /home/chuck/Src/goldfish/src/libraries/gc/build /home/chuck/Src/goldfish/src/libraries/gc/build /home/chuck/Src/goldfish/src/libraries/gc/build/CMakeFiles/gcmt-dll.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gcmt-dll.dir/depend

