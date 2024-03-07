#include "monitor/cpu_loadavg_monitor.h"
#include "utils/read_cmd.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
void CpuLoadMonitor::UpdateOnce(monitor::proto::MonitorInfo* monitor_info) {
    ReadFile cpu_load_file(std::string("/proc/loadavg"));
    std::vector<std::string> cpu_load;

    cpu_load_file.ReadLine(&cpu_load);
    load_avg_1_ = std::stof(cpu_load[0]);
    load_avg_3_ = std::stof(cpu_load[1]);
    load_avg_15_ = std::stof(cpu_load[2]);
    std::cout<< "loadavg..."<<std::endl;
  auto cpu_load_msg = monitor_info->mutable_cpu_load();
  cpu_load_msg->set_load_avg_1(load_avg_1_);
  cpu_load_msg->set_load_avg_3(load_avg_3_);
  cpu_load_msg->set_load_avg_15(load_avg_15_);

  return;
}

}  // namespace monitor