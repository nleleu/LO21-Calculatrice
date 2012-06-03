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

    virtual type* sinus()=0;
    virtual type* cosinus()=0;
    virtual type* tangente()=0;
    virtual type* sinush()=0;
    virtual type* cosinush()=0;
    virtual type* tangenteh()=0;

    //virtual type& operator/(int & i)=0;
    //virtual type& operator/(double & i)=0;




    virtual QString toQString()=0;
};

#endif // TYPE_H
