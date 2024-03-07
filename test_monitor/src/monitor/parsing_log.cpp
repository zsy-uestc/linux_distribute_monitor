#include "monitor/parsing_log.h"

#include "utils/read_cmd.h"
#include "utils/read_log.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
void ParsingLog::UpdateOnce(monitor::proto::MonitorInfo* monitor_info) {
  //****************** 可以单独运行的 *************************
  // std::ifstream ifs_log;
  //   ifs_log.open("/linux_distribute_monitor/resource/log/yjh_control.log");
  //   if (!ifs_log) {  
  //       std::cout << "这里 log_path open fail!" << std::endl;  
  //       //return false;  
  //   } else{
  //       std::cout<< "File opened successfully."<<std::endl;
  //   }
  //*********************************************************
  ReadLog parse_log(std::string("/linux_distribute_monitor/resource/log/yjh_control.log"));
  std::vector<std::string> log_line;          // 用于遍历每一行，读取每一行以空格作为分割的字符串
  std::vector<std::vector<std::string>> logs;  // 所有内容
  while (parse_log.parseLogLine(&log_line)) {
    logs.push_back(log_line);
   // std::cout << "log_line.size() = "<<logs.size() << std::endl;;
     //在清空 log_line 之前输出其内容  
	        for (const auto& entry : log_line) {  
	            std::cout << entry << " ";  
	        }  
	        std::cout << std::endl;  
    log_line.clear();
  }

  for (int i = 0; i < logs[0].size() - 1; i++) {
    struct LogEntry info;
    info.dateTime = logs[0][i];
    info.type = logs[1][i];
    info.node = logs[2][i];
    info.fun_info = logs[3][i];
    info.message = logs[4][i];
  
    auto log_msg = monitor_info->mutable_parsing_log();
    log_msg->set_datetime(info.dateTime);
    log_msg->set_type(info.type);
    log_msg->set_node(info.node);
    log_msg->set_fun_info(info.fun_info);
    log_msg->set_message(info.message);
  }
  return;
}

}  // namespace monitor