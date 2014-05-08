#-------------------------------------------------
#
# Project created by QtCreator 2014-05-07T20:11:38
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = BlandxQt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += C:/Development/boost/boost_1_55_0/

LIBS += -LC:/Development/boost/boost_1_55_0/stage/lib

SOURCES += main.cpp

HEADERS += \
    BlandxFile.h \
    BlandxTraverse.h \
    MergeSort.h




