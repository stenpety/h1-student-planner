#include "semester.h"

Semester::Semester(int id, QString semesterID, QDate startDate, QDate endDate) :
    id(id), semesterID(semesterID), startDate(startDate), endDate(endDate) {
//    subjectList = new QVector<Subject>;
}

Semester::~Semester() {
//    delete subjectList;
}

void Semester::addSubject(Subject newSubject) {
//    subjectList->push_back(newSubject);
}
