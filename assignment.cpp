#include "assignment.h"

Assignment::Assignment(int id, QString title, QDate relDate, QDate dlDate, double score) :
    id(id), title(title), relDAte(relDate), dlDate(dlDate), maxScore(0.0), score(score), submitted(false) {

}

void Assignment::setScore(double score) {
    this->score = score;
}

void Assignment::submitAsgt() {
    submitted = true;
}
