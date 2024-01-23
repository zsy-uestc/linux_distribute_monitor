#ifndef READ_CMD_H
#define READ_CMD_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace monitor {
class ReadFile {
 public:
  explicit ReadFile(const std::string& name) : ifs_(name) {}
  ~ReadFile() { ifs_.close(); }

  bool ReadLine(std::vector<std::string>* args);  //读取每一行的所有内容，空格作为分割

 private:
  std::ifstream ifs_;
};
}  // namespace monitor

#endif // READ_CMD_H