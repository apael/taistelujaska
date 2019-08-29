#-------------------------------------------------
#
# Project created by QtCreator 2016-01-06T20:50:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taistelujaska
TEMPLATE = app

RESOURCES     = \
    taistelujaska.qrc

SOURCES += main.cpp\
        mainwindow.cpp \
    areena.cpp \
    hahmo.cpp \
    item.cpp \
    funktiot.cpp \
    levelup.cpp \
    skilltree.cpp \
    newwindow.cpp \
    item_btn_class.cpp \
    save.cpp

HEADERS  += mainwindow.h \
    areena.h \
    hahmo.h \
    item.h \
    levelup.h \
    funktiot.h \
    skilltree.h \
    newwindow.h \
    item_btn_class.h \
    save.h

FORMS    += mainwindow.ui \
    areena.ui \
    levelup.ui \
    skilltree.ui \
    newwindow.ui \
    save.ui

DISTFILES +=
