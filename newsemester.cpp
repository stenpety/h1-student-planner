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
