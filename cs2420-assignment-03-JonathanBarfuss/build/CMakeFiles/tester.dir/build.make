# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/build"

# Include any dependencies generated for this target.
include CMakeFiles/tester.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tester.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tester.dir/flags.make

CMakeFiles/tester.dir/src/tester.cpp.o: CMakeFiles/tester.dir/flags.make
CMakeFiles/tester.dir/src/tester.cpp.o: ../src/tester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tester.dir/src/tester.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tester.dir/src/tester.cpp.o -c "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/src/tester.cpp"

CMakeFiles/tester.dir/src/tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tester.dir/src/tester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/src/tester.cpp" > CMakeFiles/tester.dir/src/tester.cpp.i

CMakeFiles/tester.dir/src/tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tester.dir/src/tester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/src/tester.cpp" -o CMakeFiles/tester.dir/src/tester.cpp.s

CMakeFiles/tester.dir/src/tester.cpp.o.requires:

.PHONY : CMakeFiles/tester.dir/src/tester.cpp.o.requires

CMakeFiles/tester.dir/src/tester.cpp.o.provides: CMakeFiles/tester.dir/src/tester.cpp.o.requires
	$(MAKE) -f CMakeFiles/tester.dir/build.make CMakeFiles/tester.dir/src/tester.cpp.o.provides.build
.PHONY : CMakeFiles/tester.dir/src/tester.cpp.o.provides

CMakeFiles/tester.dir/src/tester.cpp.o.provides.build: CMakeFiles/tester.dir/src/tester.cpp.o


# Object files for target tester
tester_OBJECTS = \
"CMakeFiles/tester.dir/src/tester.cpp.o"

# External object files for target tester
tester_EXTERNAL_OBJECTS =

tester: CMakeFiles/tester.dir/src/tester.cpp.o
tester: CMakeFiles/tester.dir/build.make
tester: CMakeFiles/tester.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tester"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tester.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tester.dir/build: tester

.PHONY : CMakeFiles/tester.dir/build

CMakeFiles/tester.dir/requires: CMakeFiles/tester.dir/src/tester.cpp.o.requires

.PHONY : CMakeFiles/tester.dir/requires

CMakeFiles/tester.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tester.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tester.dir/clean

CMakeFiles/tester.dir/depend:
	cd "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss" "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss" "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/build" "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/build" "/mnt/c/Users/18jon/OneDrive/Documents/CS 2420/Assignments/cs2420-assignment-03-JonathanBarfuss/build/CMakeFiles/tester.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tester.dir/depend

