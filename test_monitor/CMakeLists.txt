
set(SOURCES
   src/utils/main.cpp
   src/monitor/cpu_loadavg_monitor.cpp
   src/monitor/cpu_softirqs_monitor.cpp
   src/monitor/cpu_stat_monitor.cpp
   src/monitor/mem_monitor.cpp
   src/monitor/net_monitor.cpp
   src/monitor/parsing_log.cpp
   src/utils/read_cmd.cpp
   src/utils/read_log.cpp
)

add_executable(monitor ${SOURCES})

target_include_directories(monitor PUBLIC
  ${PROJECT_SOURCE_DIR}/test_monitor/include
  ${PROJECT_SOURCE_DIR}/grpc_manager
)

target_link_libraries(monitor
    PUBLIC
    monitor_proto
    client
    boost_system
    boost_chrono
)

