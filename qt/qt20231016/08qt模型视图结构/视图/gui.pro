#-------------------------------------------------
#
# Project created by QtCreator 2023-10-21T09:20:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
    printsupport  \
    svg

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    histogramview.cpp

HEADERS  += \
    mainwindow.h \
    histogramview.h

FORMS +=

OTHER_FILES += \
    histogram.txt
