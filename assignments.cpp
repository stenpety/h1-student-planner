#include "assignments.h"
#include "ui_assignments.h"

Assignments::Assignments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Assignments)
{
    ui->setupUi(this);
}

Assignments::~Assignments()
{
    delete ui;
}
