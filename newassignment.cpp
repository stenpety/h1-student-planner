#include "newassignment.h"
#include "ui_newassignment.h"

NewAssignment::NewAssignment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewAssignment) {
    ui->setupUi(this);
}

NewAssignment::~NewAssignment() {
    delete ui;
}

QString NewAssignment::getTitle() {
    return ui->titleLineEdit->text();
}

QDate NewAssignment::getRelDate() {
    return  ui->relDateEdit->date();
}

QDate NewAssignment::getDlDate() {
    return ui->dlDateEdit->date();
}

double NewAssignment::getMaxScore() {
    bool ok;
    double maxScore = ui->maxScoreLineEdit->text().toDouble(&ok);
    return ok ? maxScore : 0.0;
}

double NewAssignment::getScore() {
    bool ok;
    double score = ui->scoreLineEdit->text().toDouble(&ok);
    return ok ? score : 0.0;
}

bool NewAssignment::getSubmitted() {
    return false;
}

int NewAssignment::getSubject() {
    // TODO: make a rel table for subject, return chosen subj from list
    return 1;
}
