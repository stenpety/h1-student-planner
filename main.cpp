#include "mainwindow.h"
#include <QApplication>
#include "h1spinitdb.h"

int main(int argc, char *argv[]) {

    // TODO: move to settings
    const QString DBPATH = QStandardPaths::locate(QStandardPaths::HomeLocation,
                                                  QString(), QStandardPaths::LocateDirectory);
    const QString SPDBFILE = DBPATH + "test/db/h1sp_db.sqlite";
    initDB(SPDBFILE);

    QApplication plannerApp(argc, argv);
    plannerApp.setApplicationDisplayName("H1 Student Planner");
    auto *mainWindow = new MainWindow();
    mainWindow->show();

    return plannerApp.exec();
}
