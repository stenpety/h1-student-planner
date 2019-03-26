#ifndef NEWASSIGNMENT_H
#define NEWASSIGNMENT_H

#include <QDialog>

namespace Ui {
class NewAssignment;
}

class NewAssignment : public QDialog
{
    Q_OBJECT

public:
    explicit NewAssignment(QWidget *parent = nullptr);
    ~NewAssignment();

    /* Getters */
    /* title VARCHAR, relDate DATE, dlDate DATE, maxScore DOUBLE, score DOUBLE, submitted BOOLEAN, subject INTEGER) */
    QString getTitle();
    QDate getRelDate();
    QDate getDlDate();
    double getMaxScore();
    double getScore();
    bool getSubmitted();
    int getSubject();

private:
    Ui::NewAssignment *ui;
};

#endif // NEWASSIGNMENT_H
