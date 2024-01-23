#pragma once
#include <QAbstractTableModel>
#include <QObject>

namespace monitor {

class MonitorInterModel : public QAbstractTableModel {
  Q_OBJECT

 public:
  explicit MonitorInterModel(QObject *parent = nullptr)
      : QAbstractTableModel(parent) {}
  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;   // 用于返回指定索引位置的数据
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const override;   //返回表格的表头数据
  virtual ~MonitorInterModel() {}
};

}  // namespace monitor