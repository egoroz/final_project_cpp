# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/egor/repoes/final_project_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/egor/repoes/final_project_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/MyProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProject.dir/flags.make

CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o: /home/egor/repoes/final_project_cpp/lib/level/TmxLevel.cpp
CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/egor/repoes/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o -MF CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o.d -o CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o -c /home/egor/repoes/final_project_cpp/lib/level/TmxLevel.cpp

CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egor/repoes/final_project_cpp/lib/level/TmxLevel.cpp > CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.i

CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egor/repoes/final_project_cpp/lib/level/TmxLevel.cpp -o CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.s

CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o: /home/egor/repoes/final_project_cpp/lib/tinyxml2/tinyxml2.cpp
CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/egor/repoes/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o -MF CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o.d -o CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o -c /home/egor/repoes/final_project_cpp/lib/tinyxml2/tinyxml2.cpp

CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egor/repoes/final_project_cpp/lib/tinyxml2/tinyxml2.cpp > CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.i

CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egor/repoes/final_project_cpp/lib/tinyxml2/tinyxml2.cpp -o CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.s

CMakeFiles/MyProject.dir/src/background.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/background.cpp.o: /home/egor/repoes/final_project_cpp/src/background.cpp
CMakeFiles/MyProject.dir/src/background.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/egor/repoes/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MyProject.dir/src/background.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/src/background.cpp.o -MF CMakeFiles/MyProject.dir/src/background.cpp.o.d -o CMakeFiles/MyProject.dir/src/background.cpp.o -c /home/egor/repoes/final_project_cpp/src/background.cpp

CMakeFiles/MyProject.dir/src/background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/background.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egor/repoes/final_project_cpp/src/background.cpp > CMakeFiles/MyProject.dir/src/background.cpp.i

CMakeFiles/MyProject.dir/src/background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/background.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egor/repoes/final_project_cpp/src/background.cpp -o CMakeFiles/MyProject.dir/src/background.cpp.s

CMakeFiles/MyProject.dir/src/main.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/main.cpp.o: /home/egor/repoes/final_project_cpp/src/main.cpp
CMakeFiles/MyProject.dir/src/main.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/egor/repoes/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MyProject.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/src/main.cpp.o -MF CMakeFiles/MyProject.dir/src/main.cpp.o.d -o CMakeFiles/MyProject.dir/src/main.cpp.o -c /home/egor/repoes/final_project_cpp/src/main.cpp

CMakeFiles/MyProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egor/repoes/final_project_cpp/src/main.cpp > CMakeFiles/MyProject.dir/src/main.cpp.i

CMakeFiles/MyProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egor/repoes/final_project_cpp/src/main.cpp -o CMakeFiles/MyProject.dir/src/main.cpp.s

CMakeFiles/MyProject.dir/src/view.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/view.cpp.o: /home/egor/repoes/final_project_cpp/src/view.cpp
CMakeFiles/MyProject.dir/src/view.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/egor/repoes/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MyProject.dir/src/view.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/src/view.cpp.o -MF CMakeFiles/MyProject.dir/src/view.cpp.o.d -o CMakeFiles/MyProject.dir/src/view.cpp.o -c /home/egor/repoes/final_project_cpp/src/view.cpp

CMakeFiles/MyProject.dir/src/view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/view.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/egor/repoes/final_project_cpp/src/view.cpp > CMakeFiles/MyProject.dir/src/view.cpp.i

CMakeFiles/MyProject.dir/src/view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/view.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/egor/repoes/final_project_cpp/src/view.cpp -o CMakeFiles/MyProject.dir/src/view.cpp.s

# Object files for target MyProject
MyProject_OBJECTS = \
"CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o" \
"CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o" \
"CMakeFiles/MyProject.dir/src/background.cpp.o" \
"CMakeFiles/MyProject.dir/src/main.cpp.o" \
"CMakeFiles/MyProject.dir/src/view.cpp.o"

# External object files for target MyProject
MyProject_EXTERNAL_OBJECTS =

MyProject: CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o
MyProject: CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/background.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/main.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/view.cpp.o
MyProject: CMakeFiles/MyProject.dir/build.make
MyProject: /usr/lib/libsfml-network.so.2.6.1
MyProject: /usr/lib/libsfml-graphics.so.2.6.1
MyProject: /usr/lib/libsfml-audio.so.2.6.1
MyProject: /usr/lib/libsfml-window.so.2.6.1
MyProject: /usr/lib/libsfml-system.so.2.6.1
MyProject: CMakeFiles/MyProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/egor/repoes/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable MyProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProject.dir/build: MyProject
.PHONY : CMakeFiles/MyProject.dir/build

CMakeFiles/MyProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProject.dir/clean

CMakeFiles/MyProject.dir/depend:
	cd /home/egor/repoes/final_project_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/egor/repoes/final_project_cpp /home/egor/repoes/final_project_cpp /home/egor/repoes/final_project_cpp/build /home/egor/repoes/final_project_cpp/build /home/egor/repoes/final_project_cpp/build/CMakeFiles/MyProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MyProject.dir/depend

