#ifndef SEMESTERS_H
#define SEMESTERS_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include "newsemester.h"

namespace Ui {
class Semesters;
}

class Semesters : public QDialog
{
    Q_OBJECT

public:
    explicit Semesters(QWidget *parent = nullptr);
    ~Semesters();

private:
    void setupDbModel();
    void setupTable();
    void selectInSemestersTable(const int);

private slots:
    void showNewSemesterForm();
    void deleteSemester();

public:

private:
    Ui::Semesters *ui;

    QSqlRelationalTableModel *semestersModel;
    QDataWidgetMapper *semestersMapper;
    QSqlRelationalDelegate *semestersDelegate;

};

#endif // SEMESTERS_H
