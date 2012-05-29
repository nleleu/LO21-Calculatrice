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
    reglages.cpp \
    nocomplex.cpp \
    constante.cpp \
    expression.cpp \
    type_factory.cpp \
    dom.cpp \
    invoker.cpp \
    pileaddition.cpp \
    operation.cpp \
    memento.cpp \
    gardien.cpp

HEADERS  += mainwindow.h \
    pile.h \
    type.h \
    entier.h \
    reel.h \
    collection_pile.h \
    rationnel.h \
    complexe.h \
    reglages.h \
    nocomplex.h \
    constante.h \
    expression.h \
    type_factory.h \
    dom.h \
    invoker.h \
    pileaddition.h \
    operation.h \
    memento.h \
    gardien.h

FORMS    += mainwindow.ui \
    reglages.ui

QT += xml
