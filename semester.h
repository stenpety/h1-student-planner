#ifndef SEMESTER_H
#define SEMESTER_H

#include <QString>
#include <QDate>
#include <QVector>
#include "subject.h"

class Semester {

public:
    explicit Semester(int, QString, QDate, QDate);
    ~Semester();

    void addSubject(Subject);

private:

    /* Properties */
    /* id INTEGER PRIMARY KEY, semesterID VARCHAR, startDate DATE, endDate DATE */
private:
    int id;
    QString semesterID;
    QDate startDate;
    QDate endDate;
    QVector<Subject> *subjectList;
};

#endif // SEMESTER_H
