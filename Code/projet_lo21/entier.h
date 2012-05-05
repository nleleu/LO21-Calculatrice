#ifndef ENTIER_H
#define ENTIER_H

#include "type.h"
#include <sstream>

class entier:public type
{
    int data;
public:
    entier(int val=0):data(val){}
    entier(const std::string &s){
    std::istringstream iss1(s);//pour convertir une string en int
    iss1 >> data;
    }
    type& operator +(type & t);
    type& operator /(type & t);
    int getData(){return data;}
    type& operator/(int & i);
    type& operator/(double & i);
    std::string toString();


};

#endif // ENTIER_H
