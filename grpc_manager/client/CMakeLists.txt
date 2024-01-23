
set(SOURCES
    # main.cpp
    src/grpc_client.cpp
)

#
# add_executable(client ${SOURCES})
add_library(client  ${SOURCES})
message("client = PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

target_include_directories(client PUBLIC
  ${PROJECT_SOURCE_DIR}/grpc_manager/client/include
)

target_link_libraries(client
    PUBLIC
    monitor_proto
)

