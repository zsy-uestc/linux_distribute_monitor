cmake_minimum_required(VERSION 3.10.2)
PROJECT(linux_distribute_monitor LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(proto)
add_subdirectory(test_monitor)
add_subdirectory(display_monitor)
add_subdirectory(grpc_manager)