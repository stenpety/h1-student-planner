#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "ui_mainwindow.h"
#include "semesters.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

private slots:
    void about();
    void showSemesters();

private:
    Ui::MainWindow *ui;

    // TODO: move to settings
    const QString DBPATH = QStandardPaths::locate(QStandardPaths::HomeLocation,
                                                  QString(), QStandardPaths::LocateDirectory);
    const QString SPDBFILE = DBPATH + "test/db/h1sp_db.sqlite";

};
#endif // MAINWINDOW_H
