#include "rationnel.h"
#include "complexe.h"
#include <QDataStream>
#include <cmath>
#include <qDebug>
#include "reel.h"
#include "entier.h"

#define PI 3.14159265

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

type* rationnel::sign(){
    double tmp(-num/denum);
    type* t= new rationnel(tmp);
    return t;
}


type* rationnel::sinus(){
    double tmp(num/denum);
    tmp=sin(tmp*PI/180);

    type* t= new reel(tmp);
    return t;
}

type* rationnel::cosinus(){
    double tmp(num/denum);
    tmp=cos(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::tangente(){
    double tmp(num/denum);
    tmp=tan(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::sinush(){
    double tmp(num/denum);
    tmp=sinh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::cosinush(){
    double tmp(num/denum);
    tmp=cosh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::tangenteh(){
    double tmp(num/denum);
    tmp=tanh(tmp*PI/180);
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
