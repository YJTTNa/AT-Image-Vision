# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/yami/AT-Image-Vision/AT-Image-Vision-2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yami/AT-Image-Vision/AT-Image-Vision-2/build

# Include any dependencies generated for this target.
include yolov5_dection/CMakeFiles/dection_basket.dir/depend.make

# Include the progress variables for this target.
include yolov5_dection/CMakeFiles/dection_basket.dir/progress.make

# Include the compile flags for this target's objects.
include yolov5_dection/CMakeFiles/dection_basket.dir/flags.make

yolov5_dection/CMakeFiles/dection_basket.dir/src/dection_basket.cpp.o: yolov5_dection/CMakeFiles/dection_basket.dir/flags.make
yolov5_dection/CMakeFiles/dection_basket.dir/src/dection_basket.cpp.o: /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_dection/src/dection_basket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yami/AT-Image-Vision/AT-Image-Vision-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object yolov5_dection/CMakeFiles/dection_basket.dir/src/dection_basket.cpp.o"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_dection && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dection_basket.dir/src/dection_basket.cpp.o -c /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_dection/src/dection_basket.cpp

yolov5_dection/CMakeFiles/dection_basket.dir/src/dection_basket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dection_basket.dir/src/dection_basket.cpp.i"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_dection && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_dection/src/dection_basket.cpp > CMakeFiles/dection_basket.dir/src/dection_basket.cpp.i

yolov5_dection/CMakeFiles/dection_basket.dir/src/dection_basket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dection_basket.dir/src/dection_basket.cpp.s"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_dection && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_dection/src/dection_basket.cpp -o CMakeFiles/dection_basket.dir/src/dection_basket.cpp.s

# Object files for target dection_basket
dection_basket_OBJECTS = \
"CMakeFiles/dection_basket.dir/src/dection_basket.cpp.o"

# External object files for target dection_basket
dection_basket_EXTERNAL_OBJECTS =

/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: yolov5_dection/CMakeFiles/dection_basket.dir/src/dection_basket.cpp.o
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: yolov5_dection/CMakeFiles/dection_basket.dir/build.make
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/libroscpp.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/librosconsole.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/librostime.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /opt/ros/noetic/lib/libcpp_common.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket: yolov5_dection/CMakeFiles/dection_basket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yami/AT-Image-Vision/AT-Image-Vision-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_dection && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dection_basket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
yolov5_dection/CMakeFiles/dection_basket.dir/build: /home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_dection/dection_basket

.PHONY : yolov5_dection/CMakeFiles/dection_basket.dir/build

yolov5_dection/CMakeFiles/dection_basket.dir/clean:
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_dection && $(CMAKE_COMMAND) -P CMakeFiles/dection_basket.dir/cmake_clean.cmake
.PHONY : yolov5_dection/CMakeFiles/dection_basket.dir/clean

yolov5_dection/CMakeFiles/dection_basket.dir/depend:
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yami/AT-Image-Vision/AT-Image-Vision-2/src /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_dection /home/yami/AT-Image-Vision/AT-Image-Vision-2/build /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_dection /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_dection/CMakeFiles/dection_basket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : yolov5_dection/CMakeFiles/dection_basket.dir/depend

