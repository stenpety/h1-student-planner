#include "semesters.h"
#include "ui_semesters.h"

Semesters::Semesters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Semesters) {
    ui->setupUi(this);

    connect(ui->newSemesterButton, &QPushButton::pressed, this, &Semesters::showNewSemesterForm);
}

Semesters::~Semesters() {
    delete ui;
}

void Semesters::showNewSemesterForm() {
    auto newSemesterForm = new NewSemesterForm;
    newSemesterForm->show();
}
