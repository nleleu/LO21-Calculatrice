#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QStack>
#include "pile.h"
#include "entier.h"
#include <iostream>
#include "rationnel.h"
#include "reel.h"

constType MainWindow::selectedConstType=ENTIER;
complexUse MainWindow::selectedComplexUse=NO;
degUnit MainWindow::selectedDegUnit=DEGRE;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile;
    int i=2;
    reel r("2.321");
    std::cout << r.toString();
    MainWindow w(pile, 0);
    w.show();


    return a.exec();
}
