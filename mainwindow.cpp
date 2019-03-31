#include "mainwindow.h"
#include "h1spinitdb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initDB(SPDBFILE);
    ui->plannerTableView->setModel(&plannerModel);

    for (int i=0; i<plannerModel.columnCount(); ++i) {
        ui->plannerTableView->setColumnWidth(i, 10);
    }

    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionSemesters, &QAction::triggered, this, &MainWindow::showSemesters);
    connect(ui->actionSubjects, &QAction::triggered, this, &MainWindow::showSubjects);
    connect(ui->actionAssignments, &QAction::triggered, this, &MainWindow::showAssignments);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About H1 Student Planner"),
            tr("<p> About H1 Student Planner"));
}

void MainWindow::showSemesters() {
    auto semesters = new Semesters();
    semesters->show();
}

void MainWindow::showSubjects() {
    auto subjects = new Subjects();
    subjects->show();
}

void MainWindow::showAssignments() {
    auto assignments = new Assignments();
    assignments->show();
}
