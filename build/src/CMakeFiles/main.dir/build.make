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
include src/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/block.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/block.cpp.o: ../src/block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/main.dir/block.cpp.o"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/block.cpp.o -c /home/liubailin/Desktop/box/src/block.cpp

src/CMakeFiles/main.dir/block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/block.cpp.i"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liubailin/Desktop/box/src/block.cpp > CMakeFiles/main.dir/block.cpp.i

src/CMakeFiles/main.dir/block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/block.cpp.s"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liubailin/Desktop/box/src/block.cpp -o CMakeFiles/main.dir/block.cpp.s

src/CMakeFiles/main.dir/box.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/box.cpp.o: ../src/box.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/main.dir/box.cpp.o"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/box.cpp.o -c /home/liubailin/Desktop/box/src/box.cpp

src/CMakeFiles/main.dir/box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/box.cpp.i"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liubailin/Desktop/box/src/box.cpp > CMakeFiles/main.dir/box.cpp.i

src/CMakeFiles/main.dir/box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/box.cpp.s"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liubailin/Desktop/box/src/box.cpp -o CMakeFiles/main.dir/box.cpp.s

src/CMakeFiles/main.dir/content.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/content.cpp.o: ../src/content.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/main.dir/content.cpp.o"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/content.cpp.o -c /home/liubailin/Desktop/box/src/content.cpp

src/CMakeFiles/main.dir/content.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/content.cpp.i"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liubailin/Desktop/box/src/content.cpp > CMakeFiles/main.dir/content.cpp.i

src/CMakeFiles/main.dir/content.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/content.cpp.s"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liubailin/Desktop/box/src/content.cpp -o CMakeFiles/main.dir/content.cpp.s

src/CMakeFiles/main.dir/person.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/person.cpp.o: ../src/person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/main.dir/person.cpp.o"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/person.cpp.o -c /home/liubailin/Desktop/box/src/person.cpp

src/CMakeFiles/main.dir/person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/person.cpp.i"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liubailin/Desktop/box/src/person.cpp > CMakeFiles/main.dir/person.cpp.i

src/CMakeFiles/main.dir/person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/person.cpp.s"
	cd /home/liubailin/Desktop/box/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liubailin/Desktop/box/src/person.cpp -o CMakeFiles/main.dir/person.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/block.cpp.o" \
"CMakeFiles/main.dir/box.cpp.o" \
"CMakeFiles/main.dir/content.cpp.o" \
"CMakeFiles/main.dir/person.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

src/libmain.a: src/CMakeFiles/main.dir/block.cpp.o
src/libmain.a: src/CMakeFiles/main.dir/box.cpp.o
src/libmain.a: src/CMakeFiles/main.dir/content.cpp.o
src/libmain.a: src/CMakeFiles/main.dir/person.cpp.o
src/libmain.a: src/CMakeFiles/main.dir/build.make
src/libmain.a: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liubailin/Desktop/box/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libmain.a"
	cd /home/liubailin/Desktop/box/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean_target.cmake
	cd /home/liubailin/Desktop/box/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: src/libmain.a

.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd /home/liubailin/Desktop/box/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /home/liubailin/Desktop/box/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liubailin/Desktop/box /home/liubailin/Desktop/box/src /home/liubailin/Desktop/box/build /home/liubailin/Desktop/box/build/src /home/liubailin/Desktop/box/build/src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

