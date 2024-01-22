#ifndef MONITOR_INTERFACE_H
#define MONITOR_INTERFACE_H

#include <string>
#include "monitor_info.pb.h"
#include "monitor_info.grpc.pb.h"

namespace monitor {
class MonitorInter {
 public:
  MonitorInter() {}
  virtual ~MonitorInter() {}
  virtual void UpdateOnce(monitor::proto::MonitorInfo* monitor_info) = 0; //单次刷新
  virtual void Stop() = 0;
};
}  // MONITOR_INTERFACE_H 

#endif