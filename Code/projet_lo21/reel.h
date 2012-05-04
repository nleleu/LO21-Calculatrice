#ifndef REEL_H
#define REEL_H

#include "type.h"

class reel:public type
{
    double data;
public:
    reel(double val):data(val){}
    type& operator +(type & t);
    type& operator /(type & t);
    double getData(){return data;}
    type& operator/(int & i);
    type& operator/(double & i);
    std::string toString();


};

#endif // REEL_H
