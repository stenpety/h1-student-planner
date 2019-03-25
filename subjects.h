#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include "newsubject.h"

namespace Ui {
class Subjects;
}

class Subjects : public QDialog
{
    Q_OBJECT

public:
    explicit Subjects(QWidget *parent = nullptr);
    ~Subjects();

private:
    void setupDbModel();
    void setupTable();
    void selectInSubjectsTable(const int);

public slots:

private slots:
    void showNewSubjectForm();
    void showEditSubjectForm();
    void deleteSubject();

private:
    Ui::Subjects *ui;

    QSqlRelationalTableModel *subjectsModel;
    QDataWidgetMapper *subjectsMapper;
    QSqlRelationalDelegate *subjectsDelegate;
};

#endif // SUBJECTS_H
