#-------------------------------------------------
#
# Project created by QtCreator 2014-04-25T20:04:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = 04_vertexNum
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tree.cpp \
    treeStupidCounter.cpp \
    randomTree.cpp \
    treeThreadCounter.cpp

HEADERS += \
    tree.h \
    treeStupidCounter.h \
    randomTree.h \
    treeThreadCounter.h
