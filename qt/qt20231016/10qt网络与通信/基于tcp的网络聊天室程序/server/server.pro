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
    tcpserver.cpp \
    tcpclientsocket.cpp \
    server.cpp

HEADERS  += \
    tcpserver.h \
    tcpclientsocket.h \
    server.h

FORMS    +=
