#ifndef PARSING_LOG_H
#define PARSING_LOG_H

#include <string>
#include "monitor/monitor_interface.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
class ParsingLog : public MonitorInter {
 public:
  ParsingLog() {}
  void UpdateOnce(monitor::proto::MonitorInfo* monitor_info);
  void Stop() override {}
  
 public:
    struct LogEntry {  
      std::string allLog;     //整行日志
      std::string dateTime;   //时间戳
      std::string type;       // ?????? ERROR, WARNING, INFO  
      std::string node; // ?????? [ros.yjh_control]  
      std::string fun_info; // ????????? FunctionName:LineNumber  
      std::string message; // ???????  
    };
};

}   // namespace monitor

#endif // PARSING_LOG_H