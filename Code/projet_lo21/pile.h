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
    Pile& clone() const;
    Pile& duplique()const;
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
    void undo(){Pile *tmp=g->undo();if(tmp!=0)*this=*tmp;}
    void redo(){Pile *tmp=g->redo();if(tmp!=0)*this=*tmp;}

    void sinus();
    void cosinus();
    void tangente();
    void sinush();
    void cosinush();
    void tangenteh();

};

#endif // PILE_H
