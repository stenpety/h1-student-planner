#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <QDialog>

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
    Ui::Assignments *ui;
};

#endif // ASSIGNMENTS_H
