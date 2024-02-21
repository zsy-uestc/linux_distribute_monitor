#include "mem_model.h"

namespace monitor {
MemModel::MemModel(QObject* parent) : MonitorInterModel(parent) {
  header_ << tr("UsedPercent");
  header_ << tr("MemTotal");
  header_ << tr("MemFree");
  header_ << tr("MemAvailable");
  header_ << tr("Buffers");
  header_ << tr("Cached");
  header_ << tr("SwapCached");
  header_ << tr("active");
  header_ << tr("Inactive");
  header_ << tr("Active(anon)");
  header_ << tr("Inactive(anon)");
  header_ << tr("Active(file)");
  header_ << tr("Inactive(file)");
  header_ << tr("Dirty");
  header_ << tr("Writeback");
  header_ << tr("AnonPages");
  header_ << tr("Mapped");
  header_ << tr("KReclaimable");
  header_ << tr("SReclaimable");
  header_ << tr("SUnreclaim");
}

int MemModel::rowCount(const QModelIndex& parent) const {
  return monitor_data_.size();
}

int MemModel::columnCount(const QModelIndex& parent) const {
  return COLUMN_MAX;
}

QVariant MemModel::headerData(int section, Qt::Orientation orientation,
                              int role) const {
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
    return header_[section];
  }

  return MonitorInterModel::headerData(section, orientation, role);
}

QVariant MemModel::data(const QModelIndex& index, int role) const {
  if (index.column() < 0 || index.column() >= COLUMN_MAX) {
    return QVariant();
  }

  if (role == Qt::DisplayRole) {
    if (index.row() < monitor_data_.size() && index.column() < COLUMN_MAX)
      return monitor_data_[index.row()][index.column()];
  }
  return QVariant();
}

void MemModel::UpdateMonitorInfo(
    const monitor::proto::MonitorInfo& monitor_info) {
  beginResetModel();
  monitor_data_.clear();

  monitor_data_.push_back(insert_one_mem_info(monitor_info.mem_info()));
  // QModelIndex leftTop = createIndex(0, 0);
  // QModelIndex rightBottom = createIndex(monitor_data_.size(), COLUMN_MAX);
  // emit dataChanged(leftTop, rightBottom, {});

  endResetModel();

  return;
}

std::vector<QVariant> MemModel::insert_one_mem_info(
    const monitor::proto::MemInfo& mem_info) {
  std::vector<QVariant> mem_info_list;
  QString per = "%";
  QString GB = "GB";
  for (int i = MemInfo::USED_PERCENT; i < COLUMN_MAX; i++) {
    switch (i) {
      case MemInfo::USED_PERCENT:
        mem_info_list.push_back(QString::number(QVariant(mem_info.used_percent()).toDouble(), 'f', 2).append(per));
        break;
      case MemInfo::TOTAL:
        mem_info_list.push_back(QString::number(QVariant(mem_info.total()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::FREE:
        mem_info_list.push_back(QString::number(QVariant(mem_info.free()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::AVAIL:
        mem_info_list.push_back(QString::number(QVariant(mem_info.avail()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::BUFFERS:
        mem_info_list.push_back(QString::number(QVariant(mem_info.buffers()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::CACHED:
        mem_info_list.push_back(QString::number(QVariant(mem_info.cached()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::SWAP_CACHED:
        mem_info_list.push_back(QString::number(QVariant(mem_info.swap_cached()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::ACTIVE:
        mem_info_list.push_back(QString::number(QVariant(mem_info.active()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::INACTIVE:
        mem_info_list.push_back(QString::number(QVariant(mem_info.inactive()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::ACTIVE_ANON:
        mem_info_list.push_back(QString::number(QVariant(mem_info.active_anon()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::INACTIVE_ANON:
        mem_info_list.push_back(QString::number(QVariant(mem_info.inactive_anon()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::DIRTY:
        mem_info_list.push_back(QString::number(QVariant(mem_info.dirty()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::WRITEBACK:
        mem_info_list.push_back(QString::number(QVariant(mem_info.writeback()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::ANON_PAGES:
        mem_info_list.push_back(QString::number(QVariant(mem_info.anon_pages()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::MAPPED:
        mem_info_list.push_back(QString::number(QVariant(mem_info.mapped()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::KRECLAIMABLE:
        mem_info_list.push_back(QString::number(QVariant(mem_info.kreclaimable()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::SRECLAIMABLE:
        mem_info_list.push_back(QString::number(QVariant(mem_info.sreclaimable()).toDouble(), 'f', 2).append(GB));
        break;
      case MemInfo::SUNRECLAIM:
        mem_info_list.push_back(QString::number(QVariant(mem_info.sunreclaim()).toDouble(), 'f', 2).append(GB));
        break;
      default:
        break;
    }
  }
  return mem_info_list;
}
}  // namespace monitor
