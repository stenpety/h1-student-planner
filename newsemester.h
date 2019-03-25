#ifndef NEWSEMESTER_H
#define NEWSEMESTER_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class NewSemester;
}

class NewSemester : public QDialog
{
    Q_OBJECT

public:
    explicit NewSemester(QWidget *parent = nullptr);
    ~NewSemester();

    QString getSemesterLineEditText();
    QDate getStartDate();
    QDate getEndDate();

private:


signals:

public slots:

private slots:
    void activateSubmitButton();

public:

private:
    Ui::NewSemester *ui;
};




#endif // NEWSEMESTER_H
