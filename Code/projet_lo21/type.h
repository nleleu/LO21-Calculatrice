#ifndef TYPE_H
#define TYPE_H

#include <sstream>
#include <QString>
#include <QTextStream>


class type
{

public:
    type();
    //virtual type& operator=(type & t)=0;
    virtual type* operator+(type & t)=0;
    virtual type* operator/(type & t)=0;
    virtual type* operator*(type & t)=0;
    virtual type* operator-(type & t)=0;
    //virtual type& operator/(int & i)=0;
    //virtual type& operator/(double & i)=0;


    //virtual type* sin(type & t)=0;

    /*virtual type* cos(type & t)=0;
    virtual type* tan(type & t)=0;
    virtual type* sinh(type & t)=0;
    virtual type* cosh(type & t)=0;
    virtual type* tanh(type & t)=0;*/


    virtual QString toQString()=0;
};

#endif // TYPE_H
