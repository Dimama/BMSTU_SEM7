#-------------------------------------------------
#
# Project created by QtCreator 2017-11-27T22:07:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS
TARGET = Station
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modeling.cpp \
    clients.cpp \
    computer.cpp \
    random.cpp

HEADERS  += mainwindow.h \
    modeling.h \
    clients.h \
    computer.h \
    random.h

FORMS    += mainwindow.ui
