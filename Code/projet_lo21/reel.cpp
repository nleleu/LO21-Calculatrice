#include "reel.h"
#include "entier.h"
#include <QDebug>
#include <cmath>

#define PI 3.14159265

type& reel::operator =(type & t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       data=tmp.data;
       return *this;
    }
    catch(std::exception &e){}
}

type* reel::operator +(type & t){

    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *res=new reel(data+tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{

       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data+tmp.getData());
       return res;
    }
    catch(std::exception &e){}


}

type* reel::operator /(type & t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data/tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *res=new reel(data/tmp.getData());
       return res;
    }
    catch(std::exception &e){}
}

type* reel::operator*(type& t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data*tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *res=new reel(data*tmp.getData());
       return res;
    }
    catch(std::exception &e){}
}

type* reel::operator-(type& t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data-tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *res=new reel(data-tmp.getData());
       return res;
    }
    catch(std::exception &e){}
}


type* reel::pow(type & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *res=new reel(std::pow(data,tmp.getData()));
       return res;
    }
    catch(std::exception &e){}

    try{

       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(std::pow(data,tmp.getData()));
       return res;
    }
    catch(std::exception &e){}
}

QString reel::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << data;
    return res;
}

type* reel::sign(){
    double tmp(-data);
    type* t= new reel(tmp);
    return t;
}

type* reel::sinus(){
    double tmp(data);
    tmp=sin(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* reel::cosinus(){
    double tmp(data);
    tmp=cos(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* reel::tangente(){
    double tmp(data);
    tmp=tan(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* reel::sinush(){
    double tmp(data);
    tmp=sinh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* reel::cosinush(){
    double tmp(data);
    tmp=cosh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* reel::tangenteh(){
    double tmp(data);
    tmp=tanh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}


type* reel::ln(){
    double tmp(data);
    tmp=std::log(tmp);
    type* t= new reel(tmp);
    return t;
}

type* reel::log(){
    double tmp(data);
    tmp=log10(tmp);
    type* t= new reel(tmp);
    return t;
}

type* reel::inv(){
    double tmp(data);
    tmp=1/tmp;
    type* t= new reel(tmp);
    return t;
}

type* reel::sqrt(){
    double tmp(data);
    tmp=std::sqrt(tmp);
    type* t= new reel(tmp);
    return t;
}

type* reel::sqr(){
    double tmp(data);
    tmp=std::pow(tmp,2);
    type* t= new reel(tmp);
    return t;
}

type* reel::cube(){
    double tmp(data);
    tmp=std::pow(tmp,3);
    type* t= new reel(tmp);
    return t;
}
