#include <QtGui/QApplication>
#include "mainwindow.h"
#include "dialog.h"
#include <QStack>
#include "pile.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile;
    MainWindow w(pile, 0);
    w.show();

    Dialog d(pile, &w);
    d.show();

    return a.exec();
}
