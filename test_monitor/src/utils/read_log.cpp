#include "utils/read_log.h"
#include <limits>

namespace monitor {
bool ReadLog::parseLogLine(std::vector<std::string>* args) {
      
    std::string logLine;
    //std::ifstream ifs_log1_;
    //ifs_log1_.open("/linux_distribute_monitor/resource/log/yjh_control.log"); // 打开日志文件  

        std::cout<<"parseLogLine..."<<std::endl;
        if (std::getline(ifs_log_, logLine)) { 
            if (ifs_log_.eof() || logLine.empty()) {
                return false;
            } 
            std::cout<<"进来了"<<std::endl;
            std::istringstream iss(logLine);  
            std::string item;  
            std::vector<std::string> parsedItems;  
  
            // 解析日期时间  
            std::getline(iss, item, '[');  
            parsedItems.push_back(item);  
  
            // 解析类型  
            std::getline(iss, item, ']');  
            parsedItems.push_back(item);  
  
            // 忽略'['之前的空格  
            iss.ignore(std::numeric_limits<std::streamsize>::max(), '[');  
  
            // 解析节点  
            std::getline(iss, item, ']');  
            parsedItems.push_back(item);  
  
            // 忽略':'之前的空格  
            iss.ignore(std::numeric_limits<std::streamsize>::max(), ':');  
  
            // 解析函数信息  
            std::getline(iss, item, ']');  
            parsedItems.push_back(item);  
  
            // 解析消息  
            std::getline(iss, item);  
            parsedItems.push_back(item);  
  
            // 将解析的项和剩余的字符串添加到args向量中  
            args->insert(args->end(), parsedItems.begin(), parsedItems.end());  
            // 如果需要，可以在这里添加剩余的字符串，但由于getline会读取整行，剩下的应该是空字符串  
  
            return true; // 成功读取一行  
        } else {  
            // 文件结束或读取失败  
            std::cerr << "Failed to read line from file..." << std::endl; 
            return false;  
        }  

}

}  // namespace monitor