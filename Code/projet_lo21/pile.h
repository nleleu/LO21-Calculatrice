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

class Dom;
class Pile : public QStack <type *>
{
    int  nbElt;
    gardien* g;
public:
    ~Pile();
    Pile();
    Pile& clone();
    Pile& duplique();
    void setGardien(gardien* _g){g=_g;}
    gardien* getGardien()const{return g;}
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
    void undo(){*this=g->undo();}
    void redo(){*this=g->redo();}

};

#endif // PILE_H
