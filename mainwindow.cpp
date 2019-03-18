#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionSemesters, &QAction::triggered, this, &MainWindow::showNewSemesterForm);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About H1 Student Planner"),
            tr("<p> About H1 Student Planner"));
}

void MainWindow::showNewSemesterForm() {
    auto newSemesterForm = new NewSemesterForm;
    newSemesterForm->show();
}
