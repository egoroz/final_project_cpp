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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/MyProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProject.dir/flags.make

CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o: /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/level/TmxLevel.cpp
CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o -MF CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o.d -o CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o -c /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/level/TmxLevel.cpp

CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/level/TmxLevel.cpp > CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.i

CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/level/TmxLevel.cpp -o CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.s

CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o: /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/tinyxml2/tinyxml2.cpp
CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o -MF CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o.d -o CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o -c /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/tinyxml2/tinyxml2.cpp

CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/tinyxml2/tinyxml2.cpp > CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.i

CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/lib/tinyxml2/tinyxml2.cpp -o CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.s

CMakeFiles/MyProject.dir/src/background.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/background.cpp.o: /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/background.cpp
CMakeFiles/MyProject.dir/src/background.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MyProject.dir/src/background.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/src/background.cpp.o -MF CMakeFiles/MyProject.dir/src/background.cpp.o.d -o CMakeFiles/MyProject.dir/src/background.cpp.o -c /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/background.cpp

CMakeFiles/MyProject.dir/src/background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/background.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/background.cpp > CMakeFiles/MyProject.dir/src/background.cpp.i

CMakeFiles/MyProject.dir/src/background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/background.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/background.cpp -o CMakeFiles/MyProject.dir/src/background.cpp.s

CMakeFiles/MyProject.dir/src/gameplay.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/gameplay.cpp.o: /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/gameplay.cpp
CMakeFiles/MyProject.dir/src/gameplay.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MyProject.dir/src/gameplay.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/src/gameplay.cpp.o -MF CMakeFiles/MyProject.dir/src/gameplay.cpp.o.d -o CMakeFiles/MyProject.dir/src/gameplay.cpp.o -c /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/gameplay.cpp

CMakeFiles/MyProject.dir/src/gameplay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/gameplay.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/gameplay.cpp > CMakeFiles/MyProject.dir/src/gameplay.cpp.i

CMakeFiles/MyProject.dir/src/gameplay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/gameplay.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/gameplay.cpp -o CMakeFiles/MyProject.dir/src/gameplay.cpp.s

CMakeFiles/MyProject.dir/src/main.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/main.cpp.o: /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/main.cpp
CMakeFiles/MyProject.dir/src/main.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MyProject.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/src/main.cpp.o -MF CMakeFiles/MyProject.dir/src/main.cpp.o.d -o CMakeFiles/MyProject.dir/src/main.cpp.o -c /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/main.cpp

CMakeFiles/MyProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/main.cpp > CMakeFiles/MyProject.dir/src/main.cpp.i

CMakeFiles/MyProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/main.cpp -o CMakeFiles/MyProject.dir/src/main.cpp.s

CMakeFiles/MyProject.dir/src/view.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/view.cpp.o: /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/view.cpp
CMakeFiles/MyProject.dir/src/view.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MyProject.dir/src/view.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/src/view.cpp.o -MF CMakeFiles/MyProject.dir/src/view.cpp.o.d -o CMakeFiles/MyProject.dir/src/view.cpp.o -c /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/view.cpp

CMakeFiles/MyProject.dir/src/view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/view.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/view.cpp > CMakeFiles/MyProject.dir/src/view.cpp.i

CMakeFiles/MyProject.dir/src/view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/view.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/src/view.cpp -o CMakeFiles/MyProject.dir/src/view.cpp.s

# Object files for target MyProject
MyProject_OBJECTS = \
"CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o" \
"CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o" \
"CMakeFiles/MyProject.dir/src/background.cpp.o" \
"CMakeFiles/MyProject.dir/src/gameplay.cpp.o" \
"CMakeFiles/MyProject.dir/src/main.cpp.o" \
"CMakeFiles/MyProject.dir/src/view.cpp.o"

# External object files for target MyProject
MyProject_EXTERNAL_OBJECTS =

MyProject: CMakeFiles/MyProject.dir/lib/level/TmxLevel.cpp.o
MyProject: CMakeFiles/MyProject.dir/lib/tinyxml2/tinyxml2.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/background.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/gameplay.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/main.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/view.cpp.o
MyProject: CMakeFiles/MyProject.dir/build.make
MyProject: /Library/Frameworks/./sfml-network.framework/Versions/2.6.1/sfml-network
MyProject: /Library/Frameworks/./sfml-graphics.framework/Versions/2.6.1/sfml-graphics
MyProject: /Library/Frameworks/./sfml-audio.framework/Versions/2.6.1/sfml-audio
MyProject: /Library/Frameworks/./sfml-window.framework/Versions/2.6.1/sfml-window
MyProject: /Library/Frameworks/./sfml-system.framework/Versions/2.6.1/sfml-system
MyProject: CMakeFiles/MyProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable MyProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProject.dir/build: MyProject
.PHONY : CMakeFiles/MyProject.dir/build

CMakeFiles/MyProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProject.dir/clean

CMakeFiles/MyProject.dir/depend:
	cd /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build /Users/egorpatesman/Visual_Studio/Third_Semester/project/final_project_cpp/build/CMakeFiles/MyProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MyProject.dir/depend

