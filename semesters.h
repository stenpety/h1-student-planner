#ifndef SEMESTERS_H
#define SEMESTERS_H

#include <QDialog>
#include <QtWidgets>
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


private slots:
    void showNewSemesterForm();

public:

private:
    Ui::Semesters *ui;

};

#endif // SEMESTERS_H
