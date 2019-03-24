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

private:


signals:

public slots:

private slots:
    void activateSubmitButton();

public:

private:
    Ui::NewSemester *ui;
    QLineEdit *semesterLineEdit;

};




#endif // NEWSEMESTER_H
