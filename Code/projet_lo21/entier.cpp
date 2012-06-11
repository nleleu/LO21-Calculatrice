#include <exception>
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "typeexception.h"
#include <QDebug>
#include <cmath>
#include "mainwindow.h"



/*type& entier::operator =(type &t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       data=tmp.data;
       return *this;
    }
    catch(std::exception &e){}
}
*/
type* entier::operator +(type & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data+tmp.getData());
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
       rationnel r(data,1);
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

type* entier::operator /(type & t)
{
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel *res=new rationnel(data,tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data/tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(data*tmp.getDenum(), tmp.getNum());
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

type* entier::operator*(type& t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data*tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data*tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(data*tmp.getNum(), tmp.getDenum());
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

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       type * res;
       res=conv*tmp;
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur entier");
}

type* entier::operator-(type& t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data-tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data-tmp.getData());
       return res;
    }
    catch(std::exception &e){}

    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       type* res;
       rationnel r(data,1);
       res=r-tmp;
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

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       type * res;
       res=conv-tmp;
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur entier");
}


type* entier::pow(type & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(std::pow(data,tmp.getData()));
       return res;
    }
    catch(std::exception &e){}

    try{

       reel &tmp=dynamic_cast<reel&>(t);
       entier *res=new entier(std::pow(data,tmp.getData()));
       return res;
    }
    catch(std::exception &e){}
    throw typeException("erreur entier");
}

type* entier::mod(type & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data % tmp.getData());
       return res;
    }
    catch(std::exception &e){}
    throw typeException("erreur entier");
}



QString entier::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << data;
    return res;
}

type* entier::sign(){
    double tmp(-data);
    type* t= new entier(tmp);
    return t;
}

type* entier::sinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::cosinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::tangente(bool degre){
    double tmp(data);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::sinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::cosinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::tangenteh(bool degre){
    double tmp(data);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    type* t= new reel(tmp);
    return t;
}



type* entier::ln(){
    double tmp(data);
    tmp=std::log(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::log(){
    double tmp(data);
    tmp=log10(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::inv(){
    double tmp(data);
    tmp=1/tmp;
    type* t= new reel(tmp);
    return t;
}

type* entier::sqrt(){
    double tmp(data);
    tmp=std::sqrt(tmp);
    type* t= new reel(tmp);
    return t;
}

type* entier::sqr(){
    double tmp(data);
    tmp=std::pow(tmp,2);
    type* t= new reel(tmp);
    return t;
}

type* entier::cube(){
    double tmp(data);
    tmp=std::pow(tmp,3);
    type* t= new reel(tmp);
    return t;
}

type* entier::fact(){
    int tmp(1);

    for(int i=1; i<=data; i++)
        tmp*=i;

    type* t= new reel(tmp);
    return t;
}

