cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(gazebo_world_pose_plugin)
find_package(Protobuf REQUIRED)
find_package(gazebo REQUIRED)
include_directories(
    SYSTEM ${GAZEBO_INCLUDE_DIRS}
    SYSTEM ${CMAKE_CURRENT_BINARY_DIR}/msgs
    )
link_directories(${GAZEBO_LIBRARY_DIRS} ${CMAKE_CURRENT_BINARY_DIR}/msgs)
add_subdirectory(msgs)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")
add_library(model_stats SHARED 
            model_stats.cc
            model_stats.hh)
target_link_libraries(model_stats scenic_obj_info_msgs ${GAZEBO_LIBRARIES})
add_dependencies(model_stats scenic_obj_info_msgs)