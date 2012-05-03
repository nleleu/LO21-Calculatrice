#include <QtGui/QApplication>
#include "mainwindow.h"
#include "dialog.h"
#include <QStack>
#include "pile.h"
#include "entier.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile;
    int i=2;
    entier e(4);
    std::cout << e.toString();
   MainWindow w(pile, 0);
   w.show();

    Dialog d(pile, &w);
    d.show();

    return a.exec();
}
