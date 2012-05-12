#ifndef REEL_H
#define REEL_H

#include "type.h"
#include <sstream>
#include <QString>


class reel:public type
{
    double data;
public:
    reel(double val=0):data(val){}
    /*reel(const std::string &s){
        std::istringstream iss1(s);//pour convertir une string en int
        iss1 >> data;
    }*/

    reel(const QString &s)//pour convertir une QString en double
    {
        QString copie(s);
        copie.replace(',', '.');
        data = copie.toDouble();
    }

    type& operator =(type & t);
    type& operator +(type & t);
    type& operator /(type & t);
    type& operator*(type& t);
    type& operator-(type& t);

    double getData(){return data;}
    std::string toString();
    QString toQString();

    static bool isReel(const QString& s){return s.contains (",");}
};

#endif // REEL_H
