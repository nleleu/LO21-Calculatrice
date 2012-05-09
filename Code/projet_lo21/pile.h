#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "type.h"
#include <QString>
#include <sstream>

class Pile : public QStack<type *>
{
    Pile (const Pile&);
    Pile operator =(const Pile);
public:
    ~Pile(){}
    Pile(){}
    void swap(const unsigned int x, const unsigned int y);
    void sum(const unsigned int x);
    void mean(const unsigned int x);
    void dup(){if(!isEmpty()){push(top());}}
    void drop(){if(!isEmpty()){pop();}}
};

#endif // PILE_H
