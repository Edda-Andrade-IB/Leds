# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/edda/Documentos/CESE/TSSE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edda/Documentos/CESE/TSSE/Leds

# Include any dependencies generated for this target.
include CMakeFiles/test_leds.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_leds.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_leds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_leds.dir/flags.make

CMakeFiles/test_leds.dir/src/leds.c.o: CMakeFiles/test_leds.dir/flags.make
CMakeFiles/test_leds.dir/src/leds.c.o: src/leds.c
CMakeFiles/test_leds.dir/src/leds.c.o: CMakeFiles/test_leds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edda/Documentos/CESE/TSSE/Leds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_leds.dir/src/leds.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_leds.dir/src/leds.c.o -MF CMakeFiles/test_leds.dir/src/leds.c.o.d -o CMakeFiles/test_leds.dir/src/leds.c.o -c /home/edda/Documentos/CESE/TSSE/Leds/src/leds.c

CMakeFiles/test_leds.dir/src/leds.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_leds.dir/src/leds.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edda/Documentos/CESE/TSSE/Leds/src/leds.c > CMakeFiles/test_leds.dir/src/leds.c.i

CMakeFiles/test_leds.dir/src/leds.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_leds.dir/src/leds.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edda/Documentos/CESE/TSSE/Leds/src/leds.c -o CMakeFiles/test_leds.dir/src/leds.c.s

CMakeFiles/test_leds.dir/test/test_leds.c.o: CMakeFiles/test_leds.dir/flags.make
CMakeFiles/test_leds.dir/test/test_leds.c.o: test/test_leds.c
CMakeFiles/test_leds.dir/test/test_leds.c.o: CMakeFiles/test_leds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edda/Documentos/CESE/TSSE/Leds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_leds.dir/test/test_leds.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_leds.dir/test/test_leds.c.o -MF CMakeFiles/test_leds.dir/test/test_leds.c.o.d -o CMakeFiles/test_leds.dir/test/test_leds.c.o -c /home/edda/Documentos/CESE/TSSE/Leds/test/test_leds.c

CMakeFiles/test_leds.dir/test/test_leds.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_leds.dir/test/test_leds.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edda/Documentos/CESE/TSSE/Leds/test/test_leds.c > CMakeFiles/test_leds.dir/test/test_leds.c.i

CMakeFiles/test_leds.dir/test/test_leds.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_leds.dir/test/test_leds.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edda/Documentos/CESE/TSSE/Leds/test/test_leds.c -o CMakeFiles/test_leds.dir/test/test_leds.c.s

CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o: CMakeFiles/test_leds.dir/flags.make
CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o: lib/Unity/src/unity.c
CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o: CMakeFiles/test_leds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edda/Documentos/CESE/TSSE/Leds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o -MF CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o.d -o CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o -c /home/edda/Documentos/CESE/TSSE/Leds/lib/Unity/src/unity.c

CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edda/Documentos/CESE/TSSE/Leds/lib/Unity/src/unity.c > CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.i

CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edda/Documentos/CESE/TSSE/Leds/lib/Unity/src/unity.c -o CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.s

# Object files for target test_leds
test_leds_OBJECTS = \
"CMakeFiles/test_leds.dir/src/leds.c.o" \
"CMakeFiles/test_leds.dir/test/test_leds.c.o" \
"CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o"

# External object files for target test_leds
test_leds_EXTERNAL_OBJECTS =

test_leds: CMakeFiles/test_leds.dir/src/leds.c.o
test_leds: CMakeFiles/test_leds.dir/test/test_leds.c.o
test_leds: CMakeFiles/test_leds.dir/lib/Unity/src/unity.c.o
test_leds: CMakeFiles/test_leds.dir/build.make
test_leds: CMakeFiles/test_leds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edda/Documentos/CESE/TSSE/Leds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable test_leds"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_leds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_leds.dir/build: test_leds
.PHONY : CMakeFiles/test_leds.dir/build

CMakeFiles/test_leds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_leds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_leds.dir/clean

CMakeFiles/test_leds.dir/depend:
	cd /home/edda/Documentos/CESE/TSSE/Leds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edda/Documentos/CESE/TSSE /home/edda/Documentos/CESE/TSSE /home/edda/Documentos/CESE/TSSE/Leds /home/edda/Documentos/CESE/TSSE/Leds /home/edda/Documentos/CESE/TSSE/Leds/CMakeFiles/test_leds.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_leds.dir/depend
