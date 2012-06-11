#ifndef TYPEEXCEPTION_H
#define TYPEEXCEPTION_H

#include <stdexcept>
#include <string>
#include <QString>

class typeException :public std::exception
{
    std::string info;
public:
    typeException(const char * s):info(s){}
    const char* what() const throw(){return info.c_str();}
    ~typeException() throw(){}
};

#endif // TYPEEXCEPTION_H
