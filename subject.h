#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include <QVector>
#include "assignment.h"

class Subject {
public:
    explicit Subject(int, QString, QString, int, int);
    Subject();
    ~Subject();

    void setFinalScore(double);
    void addAssignment(const Assignment);

    /* Properties */
    /* id INTEGER PRIMARY KEY, code VARCHAR, title VARCHAR, numAssts INTEGER, finalScore DOUBLE, semester INTEGER */
private:
    int id;
    QString code;
    QString title;
    int numAssts;
    double finalScore;
    int semesterID;
    QVector<Assignment> *assignmentsList;
};

#endif // SUBJECT_H
