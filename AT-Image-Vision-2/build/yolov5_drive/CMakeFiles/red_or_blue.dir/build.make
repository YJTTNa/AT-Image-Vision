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
include yolov5_drive/CMakeFiles/red_or_blue.dir/depend.make

# Include the progress variables for this target.
include yolov5_drive/CMakeFiles/red_or_blue.dir/progress.make

# Include the compile flags for this target's objects.
include yolov5_drive/CMakeFiles/red_or_blue.dir/flags.make

yolov5_drive/CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.o: yolov5_drive/CMakeFiles/red_or_blue.dir/flags.make
yolov5_drive/CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.o: /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_drive/src/red_or_blue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yami/AT-Image-Vision/AT-Image-Vision-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object yolov5_drive/CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.o"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_drive && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.o -c /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_drive/src/red_or_blue.cpp

yolov5_drive/CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.i"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_drive && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_drive/src/red_or_blue.cpp > CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.i

yolov5_drive/CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.s"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_drive && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_drive/src/red_or_blue.cpp -o CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.s

# Object files for target red_or_blue
red_or_blue_OBJECTS = \
"CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.o"

# External object files for target red_or_blue
red_or_blue_EXTERNAL_OBJECTS =

/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: yolov5_drive/CMakeFiles/red_or_blue.dir/src/red_or_blue.cpp.o
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: yolov5_drive/CMakeFiles/red_or_blue.dir/build.make
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libcv_bridge.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_video.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_face.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_text.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_core.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.2.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libimage_transport.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libmessage_filters.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libclass_loader.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libPocoFoundation.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libdl.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libroscpp.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/librosconsole.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libroslib.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/librospack.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libpython3.8.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/librostime.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /opt/ros/noetic/lib/libcpp_common.so
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue: yolov5_drive/CMakeFiles/red_or_blue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yami/AT-Image-Vision/AT-Image-Vision-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue"
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_drive && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/red_or_blue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
yolov5_drive/CMakeFiles/red_or_blue.dir/build: /home/yami/AT-Image-Vision/AT-Image-Vision-2/devel/lib/yolov5_drive/red_or_blue

.PHONY : yolov5_drive/CMakeFiles/red_or_blue.dir/build

yolov5_drive/CMakeFiles/red_or_blue.dir/clean:
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_drive && $(CMAKE_COMMAND) -P CMakeFiles/red_or_blue.dir/cmake_clean.cmake
.PHONY : yolov5_drive/CMakeFiles/red_or_blue.dir/clean

yolov5_drive/CMakeFiles/red_or_blue.dir/depend:
	cd /home/yami/AT-Image-Vision/AT-Image-Vision-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yami/AT-Image-Vision/AT-Image-Vision-2/src /home/yami/AT-Image-Vision/AT-Image-Vision-2/src/yolov5_drive /home/yami/AT-Image-Vision/AT-Image-Vision-2/build /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_drive /home/yami/AT-Image-Vision/AT-Image-Vision-2/build/yolov5_drive/CMakeFiles/red_or_blue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : yolov5_drive/CMakeFiles/red_or_blue.dir/depend

