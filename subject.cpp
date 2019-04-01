#include "subject.h"

Subject::Subject(int id, QString code, QString title, int numAssts, int semesterID) :
    id(id), code(code), title(title), numAssts(numAssts),
    finalScore(0.0), semesterID(semesterID) {
    assignmentsList = new QVector<Assignment>;
}

/* Default constructor */
Subject::Subject() {
    id = 0;
    code = "";
    title = "";
    numAssts = 0;
    finalScore = 0.0;
    assignmentsList = new QVector<Assignment>;
}

Subject::~Subject() {
    delete assignmentsList;
}

void Subject::setFinalScore(double finalScore) {
    this->finalScore = finalScore;
}

void Subject::addAssignment(const Assignment newAsgt) {
    assignmentsList->push_back(newAsgt);
}
