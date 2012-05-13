#include "rationnel.h"
#include <QDataStream>

#include <qDebug>

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
       qDebug() << denum << num << tmp.num << tmp.denum;
       rationnel *res=new rationnel(num*tmp.denum+tmp.num*denum,denum*tmp.denum);
       return res;
    }
    catch(std::exception &e){}
}

type* rationnel::operator -(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(*this);
       res->num=res->num*tmp.denum - res->denum*tmp.num;
       res->denum=res->denum*tmp.denum;

       res->simplifie();
       return res;
    }
    catch(std::exception &e){}
}

type* rationnel::operator /(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(*this);
       res->num=res->num/tmp.num;
       res->denum=res->denum/tmp.denum;

       res->simplifie();
       return res;
    }
    catch(std::exception &e){}
}


type* rationnel::operator*(type& t)
{
    rationnel &tmp=dynamic_cast<rationnel&>(t);
    rationnel *res=new rationnel(*this);
    res->num *= tmp.num;
    res->denum *= tmp.denum;

    res->simplifie();
    return res;
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

