#include <memory>
#include <thread>
#include <vector>

#include "client/include/grpc_client.h"
#include "monitor/cpu_loadavg_monitor.h"
#include "monitor/cpu_softirqs_monitor.h"
#include "monitor/cpu_stat_monitor.h"
#include "monitor/mem_monitor.h"
#include "monitor/monitor_interface.h"
#include "monitor/net_monitor.h"
#include "monitor/parsing_log.h"

#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

int main() {
  std::vector<std::shared_ptr<monitor::MonitorInter>> runners_;
  runners_.emplace_back(new monitor::CpuSoftIrqsMonitor());
  runners_.emplace_back(new monitor::CpuLoadMonitor());
  runners_.emplace_back(new monitor::CpuStatMonitor());
  runners_.emplace_back(new monitor::MemMonitor());
  runners_.emplace_back(new monitor::NetMonitor());
  runners_.emplace_back(new monitor::ParsingLog());

  monitor::RpcClient rpc_client_;
  char *name = getenv("USER");
  std::unique_ptr<std::thread> thread_ = nullptr;
  thread_ = std::make_unique<std::thread>([&]() {
    while (true) {
      monitor::proto::MonitorInfo monitor_info;
      monitor_info.set_name(std::string(name));
      for (auto& runner : runners_) {
        runner->UpdateOnce(&monitor_info);
      }

      rpc_client_.SetMonitorInfo(monitor_info);
      std::this_thread::sleep_for(std::chrono::seconds(3));
    }
  });

  thread_->join();
  return 0;
}
