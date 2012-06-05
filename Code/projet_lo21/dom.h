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
    void ecrire(QString);
    void lire(QString fileName);

private :
    QDomDocument doc;
    QDomElement sauvegarde;
    QDomElement racine;
    QFile file;
    QTextStream out;
    Pile& _pile;
};

#endif // DOM_H
