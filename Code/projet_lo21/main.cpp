#include <QtGui/QApplication>
#include "mainwindow.h"
#include "dialog.h"
#include <QStack>
#include "pile.h"
#include "entier.h"
#include <iostream>
#include "rationnel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile;
    int i=2;
    rationnel r("4/2");
    std::cout << r.toString();
   MainWindow w(pile, 0);
   w.show();

    Dialog d(pile, &w);
    d.show();

    return a.exec();
}
