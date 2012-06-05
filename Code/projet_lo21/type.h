#ifndef TYPE_H
#define TYPE_H

#include <sstream>
#include <QString>
#include <QTextStream>
#include "typeexception.h"


class type
{

public:
    type();
    //virtual type& operator=(type & t)=0;
    virtual type* operator+(type & t)=0;
    virtual type* operator/(type & t)=0;
    virtual type* operator*(type & t)=0;
    virtual type* operator-(type & t)=0;

    virtual type* pow(type & t)=0;
    virtual type* mod(type & t);
    virtual type* sign()=0;

    virtual type* sinus()=0;
    virtual type* cosinus()=0;
    virtual type* tangente()=0;
    virtual type* sinush()=0;
    virtual type* cosinush()=0;
    virtual type* tangenteh()=0;

    virtual type* ln()=0;
    virtual type* log()=0;
    virtual type* inv()=0;
    virtual type* sqrt()=0;
    virtual type* sqr()=0;
    virtual type* cube()=0;
    virtual type* fact()=0;
    virtual type* eval()=0;


    //virtual type& operator/(int & i)=0;
    //virtual type& operator/(double & i)=0;


    virtual QString toQString()=0;
};

#endif // TYPE_H
