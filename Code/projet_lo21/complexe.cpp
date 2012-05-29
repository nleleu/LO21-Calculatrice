#include "complexe.h"




type* complexe::operator +(type & t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= dynamic_cast<nocomplex*> (*re + *tmp.re);
       res->im= dynamic_cast<nocomplex*>(*im + *tmp.im);

       return res;
    }
    catch(std::exception &e){}
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
