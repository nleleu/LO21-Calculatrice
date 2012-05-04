#ifndef TYPE_H
#define TYPE_H

#include <sstream>
#include <string>

class type
{

public:
    type();
    virtual type& operator+(type & t)=0;
    virtual type& operator/(type & t)=0;
    virtual type& operator/(int & i)=0;
    virtual type& operator/(double & i)=0;
    virtual std::string toString()=0;
};

#endif // TYPE_H
