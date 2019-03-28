#ifndef PLANNERMODEL_H
#define PLANNERMODEL_H

#include <QObject>
#include <QAbstractTableModel>

class PlannerModel : public QAbstractTableModel
{
public:
    PlannerModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


};

#endif // PLANNERMODEL_H
