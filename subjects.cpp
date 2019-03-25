#include "subjects.h"
#include "ui_subjects.h"

Subjects::Subjects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Subjects)
{
    ui->setupUi(this);
}

Subjects::~Subjects()
{
    delete ui;
}
