#-------------------------------------------------
#
# Project created by QtCreator 2017-11-13T14:48:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = L4_Queue
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modeling.cpp \
    processor.cpp

HEADERS  += mainwindow.h \
    baserandom.h \
    uniformrandom.h \
    exprandom.h \
    modeling.h \
    generator.h \
    processor.h

FORMS    += mainwindow.ui
