#ifndef SUBJECTS_H
#define SUBJECTS_H

#include <QDialog>

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
    Ui::Subjects *ui;
};

#endif // SUBJECTS_H
