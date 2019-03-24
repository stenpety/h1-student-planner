#include "newsemester.h"
#include "ui_newsemester.h"

NewSemester::NewSemester(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSemester)
{
    ui->setupUi(this);
    semesterLineEdit = ui->semesterLineEdit;
    startDateEdit = ui->startDateEdit;
    endDateEdit = ui->endDateEdit;
}

NewSemester::~NewSemester()
{
    delete ui;
}

QString NewSemester::getSemesterLineEditText() {
    return semesterLineEdit->text();
}

QDate NewSemester::getStartDate() {
    return startDateEdit->date();
}

QDate NewSemester::getEndDate() {
    return endDateEdit->date();
}

void NewSemester::activateSubmitButton() {

}
