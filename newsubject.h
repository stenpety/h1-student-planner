#ifndef NEWSUBJECT_H
#define NEWSUBJECT_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class NewSubject;
}

class NewSubject : public QDialog
{
    Q_OBJECT

public:
    explicit NewSubject(QWidget *parent = nullptr);
    ~NewSubject();
    QString getSubjectCode();
    QString getTitle();
    int getNumAsst();
    int getSemester();

private:

public:

public slots:

private slots:
    void activateSubmitButton();

private:
    Ui::NewSubject *ui;
};

#endif // NEWSUBJECT_H
