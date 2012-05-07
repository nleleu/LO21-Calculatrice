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

    static bool isEntier(const std::string& s){return !(s.find(',') || s.find('/') || s.find('i'));}
    static bool isReel(const std::string& s){return s.find(',');}
    static bool isRationnel(const std::string& s){return s.find('/');}
    static bool isComplexe(const std::string& s){return s.find('i');}
};

#endif // TYPE_H
