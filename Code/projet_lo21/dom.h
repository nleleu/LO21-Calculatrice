#ifndef DOM_H
#define DOM_H

#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "pile.h"


class Dom
{
public:
    Dom(Pile & p);
    ~Dom();
    void demande_ajout(QString,QString, QString);
    void lire(QString fileName);
    void newfic();

private :
    QDomDocument doc;
    QDomElement sauvegardes;
    QDomElement racine;
    QFile file;
    QTextStream out;
    Pile& _pile;
};

#endif // DOM_H
