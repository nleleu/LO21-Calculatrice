#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QStack>
#include "pile.h"
#include "entier.h"
#include <iostream>
#include "rationnel.h"
#include "reel.h"
#include <QDebug>
#include "gardien.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile;
    MainWindow w(pile, 0);
    w.show();


    return a.exec();
}
