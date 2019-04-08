#ifndef PLANNERMODEL_H
#define PLANNERMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QtSql>
#include "semester.h"
#include "subject.h"
#include "assignment.h"

class PlannerModel : public QAbstractTableModel {

public:
    PlannerModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void updateData();

private:
    // TODO: move to settings, remove Duplicates
    const QString DBPATH = QStandardPaths::locate(QStandardPaths::HomeLocation,
                                                  QString(), QStandardPaths::LocateDirectory);
    const QString SPDBFILE = DBPATH + "test/db/h1sp_db.sqlite";
};

#endif // PLANNERMODEL_H
