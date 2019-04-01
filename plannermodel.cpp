#include "plannermodel.h"

PlannerModel::PlannerModel(QObject *parent): QAbstractTableModel (parent) {

    updateData();
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

void PlannerModel::updateData() {
    QSqlQuery query;

    /* semesters */
    /* (id INTEGER PRIMARY KEY, semesterID VARCHAR, startDate DATE, endDate DATE) */
    query.exec("SELECT id, semesterID, startDate, endDate FROM assignments");
    while(query.next()) {
        int id = query.value(0).toInt();
        QString semesterID = query.value(1).toString();
        QDate startDate = query.value(2).toDate();
        QDate endDate = query.value(3).toDate();

        qDebug() << semesterID << " " << startDate;
    }

    /* subjects */
    /* (id INTEGER PRIMARY KEY, code VARCHAR, title VARCHAR, numAssts INTEGER, finalScore DOUBLE, semester INTEGER) */
    query.exec("SELECT id, code, title, numAssts, finalScore, semester FROM assignments");
    while(query.next()) {
        int id = query.value(0).toInt();
        QString code = query.value(1).toString();
        QString title = query.value(2).toString();
        int numAssts = query.value(3).toInt();
        double finalScore = query.value(4).toDouble();
        int semesterID = query.value(5).toInt();

        qDebug() << title << " " << code;
    }

    /* assignments */
    /* (id INTEGER PRIMARY KEY, title VARCHAR, relDate DATE, dlDate DATE, maxScore DOUBLE,
     * score DOUBLE, submitted BOOLEAN, subject INTEGER) */
    query.exec("SELECT id, title, relDate, dlDate, maxScore, score, submitted, subject FROM assignments");
    while(query.next()) {
        int id = query.value(0).toInt();
        QString title = query.value(1).toString();
        QDate relDate = query.value(2).toDate();
        QDate dlDate = query.value(3).toDate();
        double maxScore = query.value(4).toDouble();
        double score = query.value(5).toDouble();
        bool submitted = query.value(6).toBool();
        int subject = query.value(7).toInt();

        qDebug() << title << " " << relDate;
    }

}
