#ifndef ENTIER_H
#define ENTIER_H

#include "type.h"
#include <sstream>
#include <QString>

class entier:public type
{
    int data;
public:
    entier(int val=0):data(val){}
    entier(const std::string &s){
        std::istringstream iss1(s);//pour convertir une string en int
        iss1 >> data;
    }

    entier(const QString &s)//pour convertir une QString en int
        {data = s.toInt();}

    type& operator =(type & t);
    type& operator +(type & t);
    type& operator /(type & t);
    type& operator*(type& t);
    type& operator-(type& t);

    int getData(){return data;}
    //type& operator/(int & i);
    //type& operator/(double & i);
    QString toQString();

    static bool isEntier(const QString& s){return !(s.contains (",") || s.contains ("/") || s.contains ("i"));}
};

#endif // ENTIER_H
