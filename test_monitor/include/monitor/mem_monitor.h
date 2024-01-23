#ifndef MEM_MONITOR_H
#define MEM_MONITOR_H

#include <string>
#include <unordered_map>

#include "monitor/monitor_interface.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class MemMonitor : public MonitorInter {

 public:
  MemMonitor() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}

  private:
    struct MenInfo {
        int64_t total;
        int64_t free;
        int64_t avail;
        int64_t buffers;
        int64_t cached;
        int64_t swap_cached;
        int64_t active;
        int64_t in_active;
        int64_t active_anon;
        int64_t inactive_anon;
        int64_t active_file;
        int64_t inactive_file;
        int64_t dirty;
        int64_t writeback;
        int64_t anon_pages;
        int64_t mapped;
        int64_t kReclaimable;
        int64_t sReclaimable;
        int64_t sUnreclaim;
    };
};

}  // namespace monitor
#endif