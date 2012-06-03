#include "rationnel.h"
#include <QDataStream>
#include <math.h>
#include <qDebug>
#include "reel.h"

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
}

type* rationnel::operator -(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(num*tmp.denum-tmp.num*denum,denum*tmp.denum);
       return res;
    }
    catch(std::exception &e){}
}

type* rationnel::operator /(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel r(tmp.denum,tmp.num);
       return *this*r;
    }
    catch(std::exception &e){}
}


type* rationnel::operator*(type& t)
{
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(num*tmp.num,denum*tmp.denum);
       return res;
    }
    catch(std::exception &e){}
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
    ss << num <<'/'<< denum;
    return res;
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
    double tmp(data);
    tmp=log(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::log(){
    double tmp(data);
    tmp=log10(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::inv(){
    double tmp(data);
    tmp=1/tmp;
    type* t= new reel(tmp);
    return t;
}

type* rationnel::sqrt(){
    double tmp(data);
    tmp=sqrt(tmp);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::sqr(){
    double tmp(data);
    tmp=pow (tmp,2);
    type* t= new reel(tmp);
    return t;
}

type* rationnel::cube(){
    double tmp(data);
    tmp=pow (tmp,3);
    type* t= new reel(tmp);
    return t;
}
