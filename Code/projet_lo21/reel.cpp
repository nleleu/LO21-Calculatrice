#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "typeexception.h"
#include <QDebug>
#include <cmath>

#define PI 3.14159265
/*
type& reel::operator =(type & t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       data=tmp.data;
       return *this;
    }
    catch(std::exception &e){}
}*/

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

    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       type* res;
       rationnel r(data*10*getDecimales(),10*getDecimales());
       res=tmp+r;
       return res;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new Expression(e);
    }
    catch(std::exception &e){}

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       type * res;
       res=conv+tmp;
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur entier");


}

type* reel::operator /(type & t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       rationnel r1(tmp.getData()*10*tmp.getDecimales(),10*tmp.getDecimales());
       return r/r1;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       rationnel r1(tmp.getData(),1);
       return r/r1;
    }
    catch(std::exception &e){}

    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       type* res;
       rationnel r(data*10*getDecimales(),10*getDecimales());
       res=tmp+r;
       return res;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
       return new Expression(e);
    }
    catch(std::exception &e){}

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       type * res;
       res=conv/tmp;
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur entier");
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


    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       return r*tmp;
    }
    catch(std::exception &e){}

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       type * res;
       res=conv*tmp;
       return res;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() +" "+ tmp.toQString().remove("'") + " *'";
       return new Expression(e);
    }
    catch(std::exception &e){}

    throw typeException("erreur reel");
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


    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       return r-tmp;
    }
    catch(std::exception &e){}

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       type * res;
       res=conv-tmp;
       return res;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " -'";
       return new Expression(e);
    }
    catch(std::exception &e){}

    throw typeException("erreur reel");
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
    throw typeException("erreur reel");
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
