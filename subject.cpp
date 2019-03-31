#include "subject.h"

Subject::Subject(int id, QString code, QString title, int numAssts) :
    id(id), code(code), title(title), numAssts(numAssts), finalScore(0.0) {
//    assignmentsList = new QVector<Assignment>;
}

Subject::~Subject() {
//    delete assignmentsList;
}

void Subject::setFinalScore(double finalScore) {
    this->finalScore = finalScore;
}

void Subject::addAssignment(Assignment newAsgt) {
//    assignmentsList->push_back(newAsgt);
}
