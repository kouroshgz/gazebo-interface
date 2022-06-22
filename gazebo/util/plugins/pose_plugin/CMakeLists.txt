cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(gazebo_pose_plugin)
find_package(Protobuf REQUIRED)
find_package(gazebo REQUIRED)
include_directories(
    SYSTEM ${GAZEBO_INCLUDE_DIRS}
    SYSTEM ${CMAKE_CURRENT_BINARY_DIR}/msgs
    )
link_directories(${GAZEBO_LIBRARY_DIRS} ${CMAKE_CURRENT_BINARY_DIR}/msgs)
add_subdirectory(msgs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")
add_library(pose_plugin SHARED 
            pose_plugin.cc
            pose_plugin.hh)
target_link_libraries(pose_plugin scenic_obj_info_msgs ${GAZEBO_LIBRARIES})
add_dependencies(pose_plugin scenic_obj_info_msgs)