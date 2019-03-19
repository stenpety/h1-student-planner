#ifndef SEMESTERS_H
#define SEMESTERS_H

#include <QDialog>
#include "newsemesterform.h"

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
    Ui::Semesters *ui;

private slots:
    void showNewSemesterForm();
};

#endif // SEMESTERS_H
