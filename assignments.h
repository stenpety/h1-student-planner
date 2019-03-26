#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include "newassignment.h"

namespace Ui {
class Assignments;
}

class Assignments : public QDialog
{
    Q_OBJECT

public:
    explicit Assignments(QWidget *parent = nullptr);
    ~Assignments();

private:
    void setupDbModel();
    void setupTable();
    void selectInAssignmentsTable(const int);

private slots:
    void showNewAssignmentForm();
    void deleteAssignment();

private:
    Ui::Assignments *ui;

    QSqlRelationalTableModel *assignmentsModel;
    QDataWidgetMapper *assignmentsMapper;
    QSqlRelationalDelegate *assignmentsDelegate;
};

#endif // ASSIGNMENTS_H
