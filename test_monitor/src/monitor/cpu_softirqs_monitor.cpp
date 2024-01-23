#include "monitor/cpu_softirqs_monitor.h"

#include "utils/read_cmd.h"
#include "utils/time_diff.h"
#include "monitor_info.grpc.pb.h"
#include "monitor_info.pb.h"

namespace monitor {
void CpuSoftIrqsMonitor::UpdateOnce(monitor::proto::MonitorInfo* monitor_info) {
  ReadFile softirqs_file(std::string("/proc/softirqs"));
  std::vector<std::string> softirq_line;          // 用于遍历每一行，读取每一行以空格作为分割的字符串
  std::vector<std::vector<std::string>> softirqs;  // 所有内容
  while (softirqs_file.ReadLine(&softirq_line)) {
    softirqs.push_back(softirq_line);
    softirq_line.clear();
  }

  for (int i = 0; i < softirqs[0].size() - 1; i++) {
    std::string name = softirqs[0][i];
    struct SoftIrqs info;
    info.cpu_name = name;
    info.hi = std::stoll(softirqs[1][i + 1]);
    info.timer = std::stoll(softirqs[2][i + 1]);
    info.net_tx = std::stoll(softirqs[3][i + 1]);
    info.net_rx = std::stoll(softirqs[4][i + 1]);
    info.block = std::stoll(softirqs[5][i + 1]);
    info.irq_poll = std::stoll(softirqs[6][i + 1]);
    info.tasklet = std::stoll(softirqs[7][i + 1]);
    info.sched = std::stoll(softirqs[8][i + 1]);
    info.hrtimer = std::stoll(softirqs[9][i + 1]);
    info.rcu = std::stoll(softirqs[10][i + 1]);
    info.timepoint = boost::chrono::steady_clock::now();


    auto iter = cpu_softirqs_.find(name);
    if (iter != cpu_softirqs_.end()) {
      struct SoftIrqs& old = (*iter).second;
      double period = TimeDiff::SteadyTimeSecond(info.timepoint, old.timepoint);
      auto one_softirq_msg = monitor_info->add_soft_irq();
      one_softirq_msg->set_cpu(info.cpu_name);
      one_softirq_msg->set_hi((info.hi - old.hi) / period);
      one_softirq_msg->set_timer((info.timer - old.timer) / period);
      one_softirq_msg->set_net_tx((info.net_tx - old.net_tx) / period);
      one_softirq_msg->set_net_rx((info.net_rx - old.net_rx) / period);
      one_softirq_msg->set_block((info.block - old.block) / period);
      one_softirq_msg->set_irq_poll((info.irq_poll - old.irq_poll) / period);
      one_softirq_msg->set_tasklet((info.tasklet - old.tasklet) / period);
      one_softirq_msg->set_sched((info.sched - old.sched) / period);
      one_softirq_msg->set_hrtimer((info.hrtimer - old.hrtimer) / period);
      one_softirq_msg->set_rcu((info.rcu - old.rcu) / period);
    }
    cpu_softirqs_[name] = info;
  }
  return;
}

}  // namespace monitor