set(CMAKE_PREFIX_PATH "/usr/local/protobuf")
# 查找并加载protobuf库
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(c-ares CONFIG)

set(PROTO_FILES
    cpu_load.proto
    cpu_softirqs.proto
    cpu_stat.proto
    mem_info.proto
    monitor_info.proto
    net_info.proto
    parsing_log.proto
)
# 生成protobuf库
add_library(monitor_proto ${PROTO_FILES})

# 链接protobuf库
target_link_libraries(monitor_proto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
 )

# 设置protobuf库的头文件路径和当前构建目录的路径。
 target_include_directories(monitor_proto 
    PUBLIC
        ${PROTOBUF_INCLUDE_DIRS} 
        ${CMAKE_CURRENT_BINARY_DIR}
)


 get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
 protobuf_generate(TARGET monitor_proto LANGUAGE cpp)
 protobuf_generate(TARGET monitor_proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
 