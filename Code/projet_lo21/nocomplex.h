#ifndef NOCOMPLEX_H
#define NOCOMPLEX_H

#include "constante.h"

class nocomplex : public constante
{
public:
    nocomplex(){}
    virtual type* operator+(type & t)=0;
    virtual type* operator/(type & t)=0;
    virtual type* operator*(type & t)=0;
    virtual type* operator-(type & t)=0;

};

#endif // NOCOMPLEX_H
