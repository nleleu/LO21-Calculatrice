#-------------------------------------------------
#
# Project created by QtCreator 2012-04-29T01:56:37
#
#-------------------------------------------------

QT       += core gui

TARGET = projet_lo21
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pile.cpp \
    type.cpp \
    entier.cpp \
    reel.cpp \
    collection_pile.cpp \
    rationnel.cpp \
    complexe.cpp \
    nocomplex.cpp \
    constante.cpp \
    expression.cpp \
    type_factory.cpp \
    dom.cpp \
    memento.cpp \
    gardien.cpp \
    typeexception.cpp

HEADERS  += mainwindow.h \
    pile.h \
    type.h \
    entier.h \
    reel.h \
    collection_pile.h \
    rationnel.h \
    complexe.h \
    nocomplex.h \
    constante.h \
    expression.h \
    type_factory.h \
    dom.h \
    memento.h \
    gardien.h \
    typeexception.h

FORMS    += mainwindow.ui

QT += xml
