#ifndef REEL_H
#define REEL_H

#include "type.h"
#include <sstream>

class reel:public type
{
    double data;
public:
    reel(double val):data(val){}
    reel(const std::string &s){
        std::istringstream iss1(s);//pour convertir une string en int
        iss1 >> data;
    }
    type& operator +(type & t){}
    type& operator /(type & t){}
    double getData(){return data;}
    type& operator/(int & i){}
    type& operator/(double & i){}
    std::string toString();


};

#endif // REEL_H
