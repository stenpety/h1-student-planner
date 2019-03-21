#-------------------------------------------------
#
# Project created by QtCreator 2018-07-04T14:24:11
#
#-------------------------------------------------

QT       += sql widgets core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = "H1 Student Planner"
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    semesters.cpp \
    newsemester.cpp

HEADERS += \
        mainwindow.h \
    h1spinitdb.h \
    semesters.h \
    newsemester.h

FORMS += \
    mainwindow.ui \
    semesters.ui \
    newsemester.ui
