#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "ui_mainwindow.h"
#include "plannermodel.h"
#include "semesters.h"
#include "subjects.h"
#include "assignments.h"

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
    void showSubjects();
    void showAssignments();

private:
    Ui::MainWindow *ui;
    PlannerModel plannerModel;

    // TODO: move to settings
    const QString DBPATH = QStandardPaths::locate(QStandardPaths::HomeLocation,
                                                  QString(), QStandardPaths::LocateDirectory);
    const QString SPDBFILE = DBPATH + "test/db/h1sp_db.sqlite";

};
#endif // MAINWINDOW_H
