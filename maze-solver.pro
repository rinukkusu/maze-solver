#-------------------------------------------------
#
# Project created by QtCreator 2015-08-24T12:41:42
#
#-------------------------------------------------

QT       += core

QT       += gui

TARGET = maze-solver
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    solver.cpp \
    mazetile.cpp

HEADERS += \
    solver.h \
    mazetile.h \
    misc.h
