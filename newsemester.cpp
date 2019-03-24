#include "newsemester.h"
#include "ui_newsemester.h"

NewSemester::NewSemester(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSemester)
{
    ui->setupUi(this);
    semesterLineEdit = ui->semesterLineEdit;
}

NewSemester::~NewSemester()
{
    delete ui;
}

QString NewSemester::getSemesterLineEditText() {
    return semesterLineEdit->text();
}

void NewSemester::activateSubmitButton() {

}
