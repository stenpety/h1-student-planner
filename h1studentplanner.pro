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
    newsemesterform.cpp

HEADERS += \
        mainwindow.h \
    h1spinitdb.h \
    newsemesterform.h

FORMS += \
    mainwindow.ui \
    newsemesterform.ui
