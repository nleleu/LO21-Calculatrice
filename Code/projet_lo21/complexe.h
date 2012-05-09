#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "type.h"
#include <sstream>
#include <QString>

/*class complexe:public type
{
    int re;
    int im;
public:
    complexe(double val):data(val){}
    complexe(const std::string &s){
        std::istringstream iss1(s);//pour convertir une string en int
        iss1 >> data;
    }

    type& operator =(type & t){
        if(this!=&t){
            re=t.re;
            im=t.im;
        }
        return *this;
    }
    type& operator =(type & t);
    type& operator +(type & t){}
    type& operator /(type & t){}
    double getData(){return data;}
    type& operator/(int & i){}
    type& operator/(double & i){}
    std::string toString();

    static bool isComplexe(const QString& s){return s.contains ("i");}
};*/

#endif // COMPLEXE_H
