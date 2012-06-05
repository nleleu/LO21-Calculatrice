#include "complexe.h"
#include "entier.h"
#include "typeexception.h"



type* complexe::operator +(type & t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= dynamic_cast<nocomplex*> (*re + *tmp.re);
       res->im= dynamic_cast<nocomplex*>(*im + *tmp.im);

       return res;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv+*this;
       return res;
    }
    catch(std::exception &e){}
    throw typeException("erreur complexe");


}

type* complexe::operator /(type & t)
{
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= dynamic_cast<nocomplex*> (*re / *tmp.re);
       res->im= dynamic_cast<nocomplex*>(*im / *tmp.im);
       return res;
    }
    catch(std::exception &e){}
}

type* complexe::operator*(type& t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= dynamic_cast<nocomplex*> (*re * *tmp.re);
       res->im= dynamic_cast<nocomplex*>(*im * *tmp.im);
       return res;
    }
    catch(std::exception &e){}
}

type* complexe::operator-(type& t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= dynamic_cast<nocomplex*> (*re - *tmp.re);
       res->im= dynamic_cast<nocomplex*>(*im - *tmp.im);

       return res;
    }
    catch(std::exception &e){}
}

QString complexe::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << re->toQString() <<'$'<< im->toQString();
    return res;
}

type* complexe::sign(){
    re->sign();
    im->sign();
    type* t= new complexe(*this);
    return t;
}
