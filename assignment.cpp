#include "assignment.h"

Assignment::Assignment(int id, QString title, QDate relDate, QDate dlDate, double maxScore, int subjectID) :
    id(id), title(title), relDate(relDate), dlDate(dlDate),
    maxScore(maxScore), score(0.0), submitted(false), subjectID(subjectID) {

}

Assignment::Assignment(const Assignment &asst) {
    this->id = asst.id;
    this->title = asst.title;
    this->relDate = asst.relDate;
    this->dlDate = asst.dlDate;
    this->maxScore = asst.maxScore;
    this->score = asst.score;
    this->submitted = asst.submitted;
    this->subjectID = asst.subjectID;
}

/* Default constructor */
Assignment::Assignment() {
    id = 0;
    title = "";
    relDate = QDate::currentDate();
    dlDate = QDate::currentDate();
    maxScore = 0.0;
    score = 0.0;
    submitted = false;
    subjectID = 0;
}

Assignment::~Assignment() {

}

void Assignment::setScore(double score) {
    this->score = score;
}

void Assignment::submitAsgt() {
    submitted = true;
}
