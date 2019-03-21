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
    auto newSemester = new NewSemester();
    if (newSemester->exec()) {
        QMessageBox::about(this, tr("Success"),
                tr("<p> Success"));
    }
}
