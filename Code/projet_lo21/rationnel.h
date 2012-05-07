#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "type.h"
#include <iostream>
#include <sstream>

class rationnel:public type
{
    int num;
    int denum;
public:
    rationnel(int _num=0,int _denum=1):num(_num),denum(_denum){std::cout << "test";}
    rationnel(const std::string &s){
        int pos;
        pos=s.find('/'); //caractere separateur
        int n,d;
        std::string res1,res2;
        res1=s.substr(0,pos);
        res2=s.substr(pos+1);
        std::istringstream iss1(res1);//pour convertir une string en int
        std::istringstream iss2(res2);
        iss1 >> n;
        iss2 >> d;
        num=n;
        denum=d;
    }

    type& operator +(type & t){}    //a implementer
    type& operator /(type & t){}    //a implementer
    type& operator/(int & i){}      //a implementer
    type& operator/(double & i){}   //a implementer
    std::string toString();
};

#endif // RATIONNEL_H
