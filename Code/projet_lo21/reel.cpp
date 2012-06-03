#include "reel.h"
#include "entier.h"
#include <QDebug>
#include <math.h>

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


QString reel::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << data;
    return res;
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
