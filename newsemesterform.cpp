#include "newsemesterform.h"

NewSemesterForm::NewSemesterForm(QWidget *parent) :
    QWidget(parent), ui(new Ui::NewSemesterForm) {

    ui->setupUi(this);
}

NewSemesterForm::~NewSemesterForm() {
    delete ui;
}
