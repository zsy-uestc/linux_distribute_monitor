#ifndef CPU_LOADAVG_MONITOR_H
#define CPU_LOADAVG_MONITOR_H

#include <string>
#include "monitor/monitor_interface.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class CpuLoadMonitor : public MonitorInter {
 public:
  CpuLoadMonitor() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}

 private:
  float load_avg_1_;
  float load_avg_3_;
  float load_avg_15_;
};

}   // namespace monitor

#endif // CPU_LOADAVG_MONITOR_H