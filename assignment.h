#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <QString>
#include <QDate>

class Assignment {
public:
    explicit Assignment(int, QString, QDate, QDate, double, int);
    Assignment(const Assignment &);
    Assignment();
    ~Assignment();

    void setScore(double);
    void submitAsgt();

    /* Properties */
    /* id INTEGER PRIMARY KEY, title VARCHAR, relDate DATE, dlDate DATE, maxScore DOUBLE, score DOUBLE, submitted BOOLEAN */
private:
    int id;
    QString title;
    QDate relDate;
    QDate dlDate;
    double maxScore;
    double score;
    bool submitted;
    int subjectID;
};

#endif // ASSIGNMENT_H
