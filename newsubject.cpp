#include "newsubject.h"
#include "ui_newsubject.h"

NewSubject::NewSubject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSubject)
{
    ui->setupUi(this);
}

NewSubject::~NewSubject() {
    delete ui;
}

QString NewSubject::getSubjectCode() {
    return ui->subjectCodeLineEdit->text();
}

QString NewSubject::getTitle() {
    return ui->titleLineEdit->text();
}

int NewSubject::getNumAsst() {
    return 1;
}

int NewSubject::getSemester() {
    return 1;
}

void NewSubject::activateSubmitButton() {

}
