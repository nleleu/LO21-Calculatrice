#include "rationnel.h"
#include "complexe.h"
#include <QDataStream>
#include <cmath>

#include "reel.h"
#include "entier.h"
#include "expression.h"



/*type* rationnel::operator =(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       num=tmp.num;
       denum=tmp.denum;

       this->simplifie();
       return this;
    }
    catch(std::exception &e){}
}
*/
type* rationnel::operator +(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(num*tmp.denum+tmp.num*denum,denum*tmp.denum);
       return res;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       return tmp+*this;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       return tmp+*this;
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

    try{
       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new Expression(e);
    }
    catch(std::exception &e){}



    throw typeException("erreur entier");
}

type* rationnel::operator -(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(num*tmp.denum-tmp.num*denum,denum*tmp.denum);
       return res;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r=rationnel(tmp.getData(),1);
       return tmp-r;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       rationnel r=rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp-r;
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


    throw typeException("erreur rationnel");
}

type* rationnel::operator /(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel r(tmp.denum,tmp.num);
       return *this*r;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r=rationnel(tmp.getData(),1);
       return tmp/r;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       rationnel r=rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp/r;
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

    try{
       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
       return new Expression(e);
    }
    catch(std::exception &e){}


    throw typeException("erreur rationnel");
}


type* rationnel::operator*(type& t)
{
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(num*tmp.num,denum*tmp.denum);
       return res;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r=rationnel(tmp.getData(),1);
       return tmp*r;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       rationnel r=rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp*r;
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


    throw typeException("erreur rationnel");
}

type* rationnel::pow(type & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       rationnel *res=new rationnel(std::pow(num,tmp.getData()), std::pow(denum, tmp.getData()));
       return res;
    }
    catch(std::exception &e){}

    try{

       reel &tmp=dynamic_cast<reel&>(t);
       rationnel *res=new rationnel(std::pow(num,tmp.getData()), std::pow(denum, tmp.getData()));
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur rationnel");
}

int rationnel::pgcd(int a, int b) const {
    if (a==0||b==0) return 0;
    if (a<0) a=-a;
    if (b<0) b=-b;
    while(a!=b){
        if (a>b) a=a-b; else b=b-a;
    }
    return a;
}

void rationnel::simplifie(){
    if (num==0) { denum=1; return; }
    if (denum==0) return;
    int p=pgcd(num,denum);
    num/=p;
    denum/=p;
    if (denum<0) {
        denum=-denum;
        num=-num;
    }
}


QString rationnel::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << num;
    if (denum!=1)
        ss<<'/'<< denum;
    return res;
}

QString rationnel::eval(){
    QString res;
    QTextStream ss(&res);
    ss << (double)num/(double)denum;
    return res;
}

type* rationnel::sign(){
    double tmp(-num/denum);
    type* t= new rationnel(tmp);
    return t;
}


type* rationnel::sinus(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);

    type* t= new reel(tmp);
    return t;
}

type* rationnel::cosinus(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::tangente(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::sinush(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::cosinush(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::tangenteh(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    type* t= new reel(tmp);
    return t;
}


type* rationnel::ln(){
    double tmp(num/denum);
    tmp=std::log(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::log(){
    double tmp(num/denum);
    tmp=log10(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::inv(){
    double tmp(num/denum);
    tmp=1/tmp;
    type* t= new reel(tmp);
    return t;
}

type* rationnel::sqrt(){
    double tmp(num/denum);
    tmp=std::sqrt(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::sqr(){
    double tmp(num/denum);
    tmp=std::pow (tmp,2);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::cube(){
    double tmp(num/denum);
    tmp=std::pow (tmp,3);
    type* t= new reel(tmp);
    return t;
}
