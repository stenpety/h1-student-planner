#include "newsemester.h"
#include "ui_newsemester.h"

NewSemester::NewSemester(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSemester)
{
    ui->setupUi(this);
}

NewSemester::~NewSemester()
{
    delete ui;
}

QString NewSemester::getSemesterLineEditText() {
    return ui->semesterLineEdit->text();
}

QDate NewSemester::getStartDate() {
    return ui->startDateEdit->date();
}

QDate NewSemester::getEndDate() {
    return ui->endDateEdit->date();
}

void NewSemester::activateSubmitButton() {

}
