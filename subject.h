#ifndef SUBJECT_H
#define SUBJECT_H

#include <QString>
#include <QVector>
#include "assignment.h"

class Subject {
public:
    explicit Subject(int, QString, QString, int);
    Subject();
    ~Subject();

    void setFinalScore(double);
    void addAssignment(const Assignment);

    /* Properties */
    /* id INTEGER PRIMARY KEY, code VARCHAR, title VARCHAR, numAssts INTEGER, finalScore DOUBLE */
private:
    int id;
    QString code;
    QString title;
    int numAssts;
    double finalScore;
    QVector<Assignment> *assignmentsList;
};

#endif // SUBJECT_H
