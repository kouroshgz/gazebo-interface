find_package(Protobuf REQUIRED)
set(PROTOBUF_IMPORT_DIRS)
foreach(ITR ${GAZEBO_INCLUDE_DIRS})
  if(ITR MATCHES ".*gazebo-[0-9.]+$")
    set(PROTOBUF_IMPORT_DIRS "${ITR}/gazebo/msgs/proto")
  endif()
endforeach()

set (msgs 
    scenic_delete_models.proto
)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${msgs})
add_library(scenic_delete_models_msgs SHARED ${PROTO_SRCS})
target_link_libraries(scenic_delete_models_msgs ${PROTOBUF_LIBRARY})