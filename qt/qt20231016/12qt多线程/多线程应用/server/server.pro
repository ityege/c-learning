#-------------------------------------------------
#
# Project created by QtCreator 2023-11-04T07:45:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = server
TEMPLATE = app


SOURCES += main.cpp \
    dialog.cpp \
    timerthread.cpp \
    timeserver.cpp

HEADERS  += \
    dialog.h \
    timerthread.h \
    timeserver.h

FORMS    +=
