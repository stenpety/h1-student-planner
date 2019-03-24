#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication plannerApp(argc, argv);
    plannerApp.setApplicationDisplayName("H1 Student Planner");
    auto *mainWindow = new MainWindow();
    mainWindow->show();

    return plannerApp.exec();
}
