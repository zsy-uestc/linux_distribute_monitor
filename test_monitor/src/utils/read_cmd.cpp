#include "utils/read_cmd.h"

namespace monitor {
bool ReadFile::ReadLine(std::vector<std::string>* args) {
  std::string line;
  std::getline(ifs_, line);
  if (ifs_.eof() || line.empty()) {
    return false;
  }

  std::istringstream line_ss(line); //空格作为切割符
  while (!line_ss.eof()) {
    std::string word;
    line_ss >> word;
    args->push_back(word);          //每一组字符串保存在vector中
  }
  return true;
}


}  // namespace monitor