#ifndef CPU_SOFTIRQS_MONITOR_H
#define CPU_SOFTIRQS_MONITOR_H

#include <string>
#include "monitor/monitor_interface.h"
#include <boost/chrono.hpp>
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class CpuSoftIrqsMonitor : public MonitorInter {
 public:
  CpuSoftIrqsMonitor() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}

 private:
    struct SoftIrqs{
        std::string cpu_name;
        int64_t hi;
        int64_t timer;
        int64_t net_tx;
        int64_t net_rx;
        int64_t block;
        int64_t irq_poll;
        int64_t tasklet;
        int64_t sched;
        int64_t hrtimer;
        int64_t rcu;
        boost::chrono::steady_clock::time_point timepoint;
    };
    
    std::unordered_map<std::string, struct SoftIrqs> cpu_softirqs_;

};

}   // namespace monitor

#endif // CPU_SOFTIRQS_MONITOR_H