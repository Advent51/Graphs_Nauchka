#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T20:43:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Nauchka
TEMPLATE = app

RC_FILE = Kersach1MINGW.rc

CONFIG += static
QMAKE_LFLAGS += -static -static-libgcc
LIBS += -static-libgcc

SOURCES += main.cpp\
        mainwindow.cpp \
    edge.cpp \
    graphwidget.cpp \
    node.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    edge.h \
    graphwidget.h \
    node.h \
    form.h

FORMS    += mainwindow.ui \
    form.ui
