#include "complexe.h"


type* complexe::operator =(type & t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       re=tmp.re;
       im=tmp.im;
       return this;
    }
    catch(std::exception &e){}
}

type* complexe::operator +(type & t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= re + tmp.re;
       res->im= im + tmp.im;

       return res;
    }
    catch(std::exception &e){}
}

type* complexe::operator /(type & t)
{
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= (re*tmp.re+im*tmp.im)/(re*re+im*im);
       res->im= (re*tmp.im-im*tmp.re)/(re*re+im*im);
       return res;
    }
    catch(std::exception &e){}
}

type* complexe::operator*(type& t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= re*tmp.re - im*tmp.im;
       res->im= im*tmp.re + re*tmp.im;
       return res;
    }
    catch(std::exception &e){}
}

type* complexe::operator-(type& t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= re - tmp.re;
       res->im= im - tmp.im;

       return res;
    }
    catch(std::exception &e){}
}

QString complexe::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << re <<'$'<< im;
    return res;
}
