# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liubailin/Desktop/box

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liubailin/Desktop/box/build

# Include any dependencies generated for this target.
include CMakeFiles/box.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/box.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/box.dir/flags.make

CMakeFiles/box.dir/main.cpp.o: CMakeFiles/box.dir/flags.make
CMakeFiles/box.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/box.dir/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/box.dir/main.cpp.o -c /home/liubailin/Desktop/box/main.cpp

CMakeFiles/box.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/box.dir/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liubailin/Desktop/box/main.cpp > CMakeFiles/box.dir/main.cpp.i

CMakeFiles/box.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/box.dir/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liubailin/Desktop/box/main.cpp -o CMakeFiles/box.dir/main.cpp.s

CMakeFiles/box.dir/adapt.cpp.o: CMakeFiles/box.dir/flags.make
CMakeFiles/box.dir/adapt.cpp.o: ../adapt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/box.dir/adapt.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/box.dir/adapt.cpp.o -c /home/liubailin/Desktop/box/adapt.cpp

CMakeFiles/box.dir/adapt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/box.dir/adapt.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liubailin/Desktop/box/adapt.cpp > CMakeFiles/box.dir/adapt.cpp.i

CMakeFiles/box.dir/adapt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/box.dir/adapt.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liubailin/Desktop/box/adapt.cpp -o CMakeFiles/box.dir/adapt.cpp.s

# Object files for target box
box_OBJECTS = \
"CMakeFiles/box.dir/main.cpp.o" \
"CMakeFiles/box.dir/adapt.cpp.o"

# External object files for target box
box_EXTERNAL_OBJECTS =

box: CMakeFiles/box.dir/main.cpp.o
box: CMakeFiles/box.dir/adapt.cpp.o
box: CMakeFiles/box.dir/build.make
box: src/libmain.a
box: CMakeFiles/box.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable box"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/box.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/box.dir/build: box

.PHONY : CMakeFiles/box.dir/build

CMakeFiles/box.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/box.dir/cmake_clean.cmake
.PHONY : CMakeFiles/box.dir/clean

CMakeFiles/box.dir/depend:
	cd /home/liubailin/Desktop/box/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liubailin/Desktop/box /home/liubailin/Desktop/box /home/liubailin/Desktop/box/build /home/liubailin/Desktop/box/build /home/liubailin/Desktop/box/build/CMakeFiles/box.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/box.dir/depend

