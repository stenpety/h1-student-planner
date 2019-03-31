#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <QString>
#include <QDate>

class Assignment {
public:
    Assignment(int, QString, QDate, QDate, double);

    void setScore(double);
    void submitAsgt();

    /* Properties */
    /* id INTEGER PRIMARY KEY, title VARCHAR, relDate DATE, dlDate DATE, maxScore DOUBLE, score DOUBLE, submitted BOOLEAN */
private:
    int id;
    QString title;
    QDate relDAte;
    QDate dlDate;
    double maxScore;
    double score;
    bool submitted;
};

#endif // ASSIGNMENT_H
