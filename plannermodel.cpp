#include "plannermodel.h"

PlannerModel::PlannerModel(QObject *parent): QAbstractTableModel (parent) {

}

int PlannerModel::rowCount(const QModelIndex & /*parent*/) const {
   return 15;
}

int PlannerModel::columnCount(const QModelIndex & /*parent*/) const {
    return 90;
}

QVariant PlannerModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole)
       return QString("%1:%2")
                   .arg( (index.row() + 1)%10)
                   .arg( (index.column() +1)%10);

    return QVariant();
}
