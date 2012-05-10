#include "rationnel.h"
#include <QDataStream>


type& rationnel::operator =(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       num=tmp.num;
       denum=tmp.denum;

       this->simplifie();
       return *this;
    }
    catch(std::exception &e){}
}

type& rationnel::operator +(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(*this);
       res->num=res->num*tmp.denum + res->denum*tmp.num;
       res->denum=res->denum*tmp.denum;

       res->simplifie();
       return *res;
    }
    catch(std::exception &e){}
}

type& rationnel::operator -(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(*this);
       res->num=res->num*tmp.denum - res->denum*tmp.num;
       res->denum=res->denum*tmp.denum;

       res->simplifie();
       return *res;
    }
    catch(std::exception &e){}
}

type& rationnel::operator /(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *res=new rationnel(*this);
       res->num=res->num/tmp.num;
       res->denum=res->denum/tmp.denum;

       res->simplifie();
       return *res;
    }
    catch(std::exception &e){}
}


type& rationnel::operator*(type& t)
{
    rationnel &tmp=dynamic_cast<rationnel&>(t);
    rationnel *res=new rationnel(*this);
    res->num *= tmp.num;
    res->denum *= tmp.denum;

    res->simplifie();
    return *res;
}

void rationnel::simplifie()
{
    int nombre=pgcd(num, denum); //Calcul du pgcd

    num /= nombre;     //Et on simplifie
    denum /= nombre;
}

std::string rationnel::toString(){
    std::stringstream ss;
    ss << num << "/" << denum;
    return ss.str();
}

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}
