#ifndef READ_LOG_H
#define READ_LOG_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace monitor {
class ReadLog {
 public:
  explicit ReadLog(const std::string& name) : ifs_log_(name) {}
  bool parseLogLine(std::vector<std::string>* args);  //读取每一行的所有内容，自定义日志切割格式

 public:
  std::ifstream ifs_log_;
};
}  // namespace monitor

#endif // READ_LOG_H