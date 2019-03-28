#include "plannermodel.h"

PlannerModel::PlannerModel(QObject *parent): QAbstractTableModel (parent) {

}

int PlannerModel::rowCount(const QModelIndex & /*parent*/) const {
   return 2;
}

int PlannerModel::columnCount(const QModelIndex & /*parent*/) const {
    return 3;
}

QVariant PlannerModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole)
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);

    return QVariant();
}
