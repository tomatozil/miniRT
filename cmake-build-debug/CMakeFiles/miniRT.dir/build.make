# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jiyun/miniminirt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jiyun/miniminirt/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/miniRT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/miniRT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/miniRT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/miniRT.dir/flags.make

CMakeFiles/miniRT.dir/main.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/main.c.o: ../main.c
CMakeFiles/miniRT.dir/main.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/miniRT.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/main.c.o -MF CMakeFiles/miniRT.dir/main.c.o.d -o CMakeFiles/miniRT.dir/main.c.o -c /Users/jiyun/miniminirt/main.c

CMakeFiles/miniRT.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/main.c > CMakeFiles/miniRT.dir/main.c.i

CMakeFiles/miniRT.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/main.c -o CMakeFiles/miniRT.dir/main.c.s

CMakeFiles/miniRT.dir/vector.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/vector.c.o: ../vector.c
CMakeFiles/miniRT.dir/vector.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/miniRT.dir/vector.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/vector.c.o -MF CMakeFiles/miniRT.dir/vector.c.o.d -o CMakeFiles/miniRT.dir/vector.c.o -c /Users/jiyun/miniminirt/vector.c

CMakeFiles/miniRT.dir/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/vector.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/vector.c > CMakeFiles/miniRT.dir/vector.c.i

CMakeFiles/miniRT.dir/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/vector.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/vector.c -o CMakeFiles/miniRT.dir/vector.c.s

CMakeFiles/miniRT.dir/ray.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/ray.c.o: ../ray.c
CMakeFiles/miniRT.dir/ray.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/miniRT.dir/ray.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/ray.c.o -MF CMakeFiles/miniRT.dir/ray.c.o.d -o CMakeFiles/miniRT.dir/ray.c.o -c /Users/jiyun/miniminirt/ray.c

CMakeFiles/miniRT.dir/ray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/ray.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/ray.c > CMakeFiles/miniRT.dir/ray.c.i

CMakeFiles/miniRT.dir/ray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/ray.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/ray.c -o CMakeFiles/miniRT.dir/ray.c.s

CMakeFiles/miniRT.dir/object.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/object.c.o: ../object.c
CMakeFiles/miniRT.dir/object.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/miniRT.dir/object.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/object.c.o -MF CMakeFiles/miniRT.dir/object.c.o.d -o CMakeFiles/miniRT.dir/object.c.o -c /Users/jiyun/miniminirt/object.c

CMakeFiles/miniRT.dir/object.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/object.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/object.c > CMakeFiles/miniRT.dir/object.c.i

CMakeFiles/miniRT.dir/object.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/object.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/object.c -o CMakeFiles/miniRT.dir/object.c.s

CMakeFiles/miniRT.dir/hit.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/hit.c.o: ../hit.c
CMakeFiles/miniRT.dir/hit.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/miniRT.dir/hit.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/hit.c.o -MF CMakeFiles/miniRT.dir/hit.c.o.d -o CMakeFiles/miniRT.dir/hit.c.o -c /Users/jiyun/miniminirt/hit.c

CMakeFiles/miniRT.dir/hit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/hit.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/hit.c > CMakeFiles/miniRT.dir/hit.c.i

CMakeFiles/miniRT.dir/hit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/hit.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/hit.c -o CMakeFiles/miniRT.dir/hit.c.s

CMakeFiles/miniRT.dir/util.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/util.c.o: ../util.c
CMakeFiles/miniRT.dir/util.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/miniRT.dir/util.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/util.c.o -MF CMakeFiles/miniRT.dir/util.c.o.d -o CMakeFiles/miniRT.dir/util.c.o -c /Users/jiyun/miniminirt/util.c

CMakeFiles/miniRT.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/util.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/util.c > CMakeFiles/miniRT.dir/util.c.i

CMakeFiles/miniRT.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/util.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/util.c -o CMakeFiles/miniRT.dir/util.c.s

CMakeFiles/miniRT.dir/init.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/init.c.o: ../init.c
CMakeFiles/miniRT.dir/init.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/miniRT.dir/init.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/init.c.o -MF CMakeFiles/miniRT.dir/init.c.o.d -o CMakeFiles/miniRT.dir/init.c.o -c /Users/jiyun/miniminirt/init.c

CMakeFiles/miniRT.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/init.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/init.c > CMakeFiles/miniRT.dir/init.c.i

CMakeFiles/miniRT.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/init.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/init.c -o CMakeFiles/miniRT.dir/init.c.s

CMakeFiles/miniRT.dir/lighting.c.o: CMakeFiles/miniRT.dir/flags.make
CMakeFiles/miniRT.dir/lighting.c.o: ../lighting.c
CMakeFiles/miniRT.dir/lighting.c.o: CMakeFiles/miniRT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/miniRT.dir/lighting.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/miniRT.dir/lighting.c.o -MF CMakeFiles/miniRT.dir/lighting.c.o.d -o CMakeFiles/miniRT.dir/lighting.c.o -c /Users/jiyun/miniminirt/lighting.c

CMakeFiles/miniRT.dir/lighting.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miniRT.dir/lighting.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jiyun/miniminirt/lighting.c > CMakeFiles/miniRT.dir/lighting.c.i

CMakeFiles/miniRT.dir/lighting.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miniRT.dir/lighting.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jiyun/miniminirt/lighting.c -o CMakeFiles/miniRT.dir/lighting.c.s

# Object files for target miniRT
miniRT_OBJECTS = \
"CMakeFiles/miniRT.dir/main.c.o" \
"CMakeFiles/miniRT.dir/vector.c.o" \
"CMakeFiles/miniRT.dir/ray.c.o" \
"CMakeFiles/miniRT.dir/object.c.o" \
"CMakeFiles/miniRT.dir/hit.c.o" \
"CMakeFiles/miniRT.dir/util.c.o" \
"CMakeFiles/miniRT.dir/init.c.o" \
"CMakeFiles/miniRT.dir/lighting.c.o"

# External object files for target miniRT
miniRT_EXTERNAL_OBJECTS =

miniRT: CMakeFiles/miniRT.dir/main.c.o
miniRT: CMakeFiles/miniRT.dir/vector.c.o
miniRT: CMakeFiles/miniRT.dir/ray.c.o
miniRT: CMakeFiles/miniRT.dir/object.c.o
miniRT: CMakeFiles/miniRT.dir/hit.c.o
miniRT: CMakeFiles/miniRT.dir/util.c.o
miniRT: CMakeFiles/miniRT.dir/init.c.o
miniRT: CMakeFiles/miniRT.dir/lighting.c.o
miniRT: CMakeFiles/miniRT.dir/build.make
miniRT: CMakeFiles/miniRT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable miniRT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/miniRT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/miniRT.dir/build: miniRT
.PHONY : CMakeFiles/miniRT.dir/build

CMakeFiles/miniRT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/miniRT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/miniRT.dir/clean

CMakeFiles/miniRT.dir/depend:
	cd /Users/jiyun/miniminirt/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jiyun/miniminirt /Users/jiyun/miniminirt /Users/jiyun/miniminirt/cmake-build-debug /Users/jiyun/miniminirt/cmake-build-debug /Users/jiyun/miniminirt/cmake-build-debug/CMakeFiles/miniRT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/miniRT.dir/depend

