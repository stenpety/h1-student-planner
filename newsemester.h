#ifndef NEWSEMESTER_H
#define NEWSEMESTER_H

#include <QDialog>

namespace Ui {
class NewSemester;
}

class NewSemester : public QDialog
{
    Q_OBJECT

public:
    explicit NewSemester(QWidget *parent = nullptr);
    ~NewSemester();

private:
    Ui::NewSemester *ui;
};

#endif // NEWSEMESTER_H
