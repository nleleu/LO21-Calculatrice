#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "type.h"
#include <QString>
#include <sstream>
#include <QStringList>
#include "type_factory.h"

class Pile : public QStack<type *>
{
    Pile (const Pile&);
    int  nbElt;
public:
    ~Pile(){}
    Pile():nbElt(5){}
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

};

#endif // PILE_H
