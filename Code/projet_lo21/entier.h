#ifndef ENTIER_H
#define ENTIER_H

#include "type.h"

class entier:public type
{
    int data;
public:
    entier(int val=0):data(val){}
    type& operator +(type & t);
    type& operator /(type & t);
    int getData(){return data;}
    type& operator/(int & i);
    type& operator/(double & i);
    std::string toString();


};

#endif // ENTIER_H
