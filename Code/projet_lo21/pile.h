#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "type.h"
#include <QString>
#include <sstream>
#include <QStringList>
#include "type_factory.h"
#include <QDebug>
#include "gardien.h"

enum degUnit{DEGRE, RADIANT};

class Dom;
class Pile : public QStack <type *>
{
    int  nbElt;
    QString fileName;
    gardien* g;
public:
    ~Pile();
    Pile();
    void setFileName(QString name){fileName = name;}
    static degUnit selectedDegUnit;
    void sauvegarde();
    void charger();
    Pile& clone() const;
    Pile& duplique()const;
    void setGardien(gardien* _g){g=_g;}
    void setNbElt(int nb){nbElt=nb;}
    gardien* getGardien()const{return g;}


    //selection de l'unite des degres
    void on_degUnit_clicked();
    void on_radUnit_clicked();


    void swap(const unsigned int x, const unsigned int y);
    void sum(const unsigned int x);
    void mean(const unsigned int x);
    void dup(){if(!isEmpty()){push(top());}}
    void drop(){if(!isEmpty()){pop();}}
    void addition();
    void soustraction();
    void division();
    void multiplication();
    void parser(QString s);
    int getNb(){return nbElt;}
    void undo(){Pile *tmp=g->undo();if(tmp!=0)*this=*tmp;}
    void redo(){Pile *tmp=g->redo();if(tmp!=0)*this=*tmp;}

    void pow();
    void mod();

    void sign();

    void sinus();
    void cosinus();
    void tangente();
    void sinush();
    void cosinush();
    void tangenteh();

    void ln();
    void log();
    void inv();
    void sqrt();
    void sqr();
    void cube();
    void fact();
    void eval();


};

#endif // PILE_H
