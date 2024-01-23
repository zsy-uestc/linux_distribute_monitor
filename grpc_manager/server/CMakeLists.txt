
set(SOURCES
    src/main.cpp
    src/grpc_manager.cpp
)

add_executable(server ${SOURCES})

target_include_directories(server PUBLIC
  ${PROJECT_SOURCE_DIR}/grpc_manager/server/include
)

target_link_libraries(server
    PUBLIC
    monitor_proto
)
