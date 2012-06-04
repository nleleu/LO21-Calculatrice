#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QStack>
#include "pile.h"
#include "entier.h"
#include <iostream>
#include "rationnel.h"
#include "reel.h"
#include <QDebug>
#include "Invoker.h"
#include "gardien.h"

degUnit Pile::selectedDegUnit=DEGRE;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile;
   // Invoker invoker(pile);
    //MainWindow w(pile, invoker, 0);
    MainWindow w(pile, 0);
    w.show();


    return a.exec();
}
