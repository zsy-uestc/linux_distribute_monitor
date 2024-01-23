#include "cpu_stat_model.h"

namespace monitor {
CpuStatModel::CpuStatModel(QObject* parent) : MonitorInterModel(parent) {
  header_ << tr("name");
  header_ << tr("cpu_percent");
  header_ << tr("user");
  header_ << tr("system");
<<<<<<< HEAD
  header_ << tr("idle");
  header_ << tr("io_wait");
  header_ << tr("irq");
  header_ << tr("soft_irq");
=======
>>>>>>> 72ec158588310452e6cec479692c184e37016bf8
}

int CpuStatModel::rowCount(const QModelIndex& parent) const {
  return monitor_data_.size();
}

int CpuStatModel::columnCount(const QModelIndex& parent) const {
  return COLUMN_MAX;
}

QVariant CpuStatModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const {
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
    return header_[section];
  }

  return MonitorInterModel::headerData(section, orientation, role);
}

QVariant CpuStatModel::data(const QModelIndex& index, int role) const {
  if (index.column() < 0 || index.column() >= COLUMN_MAX) {
    return QVariant();
  }

  if (role == Qt::DisplayRole) {
    if (index.row() < monitor_data_.size() && index.column() < COLUMN_MAX)
<<<<<<< HEAD
      return monitor_data_[index.row()][index.column()].toString();
=======
      return monitor_data_[index.row()][index.column()];
>>>>>>> 72ec158588310452e6cec479692c184e37016bf8
  }
  return QVariant();
}

void CpuStatModel::UpdateMonitorInfo(
    const monitor::proto::MonitorInfo& monitor_info) {
  beginResetModel();
  monitor_data_.clear();

  for (int i = 0; i < monitor_info.cpu_stat_size(); i++) {
    // std::cout <<monitor_info.cpu_stat(i).cpu_name()<<std::endl;
    monitor_data_.push_back(insert_one_cpu_stat(monitor_info.cpu_stat(i)));
  }
  // QModelIndex leftTop = createIndex(0, 0);
  // QModelIndex rightBottom = createIndex(monitor_data_.size(), COLUMN_MAX);
  // emit dataChanged(leftTop, rightBottom, {});

  endResetModel();

  return;
}

std::vector<QVariant> CpuStatModel::insert_one_cpu_stat(
    const monitor::proto::CpuStat& cpu_stat) {
     
  std::vector<QVariant> cpu_stat_list;
  QString per = "%";
  for (int i = CpuStat::CPU_NAME; i < COLUMN_MAX; i++) {
    switch (i) {
      case CpuStat::CPU_NAME:
        cpu_stat_list.push_back(QString::fromStdString(cpu_stat.cpu_name()));
        break;
      case CpuStat::CPU_PERCENT:
        cpu_stat_list.push_back(QString::number(QVariant(cpu_stat.cpu_percent()).toDouble(), 'f', 2).append(per));
        break;
      case CpuStat::CPU_USER_PERCENT:
        cpu_stat_list.push_back(QString::number(QVariant(cpu_stat.usr_percent()).toDouble(), 'f', 2).append(per));
        break;
      case CpuStat::CPU_SYSTEM_PERCENT:
        cpu_stat_list.push_back(QString::number(QVariant(cpu_stat.system_percent()).toDouble(), 'f', 2).append(per));
        break;
       // 后面四个新增
      case CpuStat::CPU_IDLE_PERCENT:
        cpu_stat_list.push_back(QString::number(QVariant(cpu_stat.idle_percent()).toDouble(), 'f', 2).append(per));
        break;
      case CpuStat::CPU_IOWAIT_PERCENT:
        cpu_stat_list.push_back(QString::number(QVariant(cpu_stat.io_wait_percent()).toDouble(), 'f', 2).append(per));
        break;
      case CpuStat::CPU_IRQ_PERCENT:
        cpu_stat_list.push_back(QString::number(QVariant(cpu_stat.irq_percent()).toDouble(), 'f', 2).append(per));
        break;
      case CpuStat::CPU_SOFTIRQ_PERCENT:
        cpu_stat_list.push_back(QString::number(QVariant(cpu_stat.soft_irq_percent()).toDouble(), 'f', 2).append(per));
        break;
      default:
        break;
    }
  }
  return cpu_stat_list;
}
}  // namespace monitor
