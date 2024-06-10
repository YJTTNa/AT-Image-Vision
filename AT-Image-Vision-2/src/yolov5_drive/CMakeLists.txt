cmake_minimum_required(VERSION 3.0.2)
project(yolov5_drive)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  yolov5_ros_msgs
  cv_bridge
  sensor_msgs
  image_transport
)

# 这里的opencv都没有找包
# find_package(OpenCV 4.9 REQUIRED)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

catkin_package(
 CATKIN_DEPENDS 
 roscpp 
 rospy 
 std_msgs 
 yolov5_ros_msgs
 cv_bridge
 sensor_msgs
 image_transport
)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  /home/yami/AT-Image-Vision-2/src/yolov5_drive/include/
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/yolov5_test.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(red_or_blue src/red_or_blue.cpp)
add_executable(descion src/descion)
add_dependencies(red_or_blue yolov5_ros_msgs_generate_messages_cpp)
add_dependencies(descion yolov5_ros_msgs_generate_messages_cpp)
## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies( ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(red_or_blue
  ${catkin_LIBRARIES}
)
target_link_libraries(descion 
  ${catkin_LIBRARIES}
)
# target_link_libraries(cam_5 ${OpenCV_LIBS})
# target_include_directories(cam_5 PRIVATE ${OpenCV_INCLUDE_DIRS})

catkin_install_python(PROGRAMS
  scripts/key_conl_mode.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

