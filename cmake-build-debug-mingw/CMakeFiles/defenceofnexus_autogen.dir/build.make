# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\DefenceOfTheNexus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\DefenceOfTheNexus\cmake-build-debug-mingw

# Utility rule file for defenceofnexus_autogen.

# Include the progress variables for this target.
include CMakeFiles/defenceofnexus_autogen.dir/progress.make

CMakeFiles/defenceofnexus_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\DefenceOfTheNexus\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target defenceofnexus"
	"C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E cmake_autogen C:/DefenceOfTheNexus/cmake-build-debug-mingw/CMakeFiles/defenceofnexus_autogen.dir/AutogenInfo.cmake Debug

defenceofnexus_autogen: CMakeFiles/defenceofnexus_autogen
defenceofnexus_autogen: CMakeFiles/defenceofnexus_autogen.dir/build.make

.PHONY : defenceofnexus_autogen

# Rule to build all files generated by this target.
CMakeFiles/defenceofnexus_autogen.dir/build: defenceofnexus_autogen

.PHONY : CMakeFiles/defenceofnexus_autogen.dir/build

CMakeFiles/defenceofnexus_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\defenceofnexus_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/defenceofnexus_autogen.dir/clean

CMakeFiles/defenceofnexus_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\DefenceOfTheNexus C:\DefenceOfTheNexus C:\DefenceOfTheNexus\cmake-build-debug-mingw C:\DefenceOfTheNexus\cmake-build-debug-mingw C:\DefenceOfTheNexus\cmake-build-debug-mingw\CMakeFiles\defenceofnexus_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/defenceofnexus_autogen.dir/depend

