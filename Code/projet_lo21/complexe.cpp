#include "complexe.h"
#include "entier.h"
#include "reel.h"
#include "Expression.h"
#include "rationnel.h"
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

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv+*this;
       return res;
    }
    catch(std::exception &e){}

    try{
       Expression &tmp=dynamic_cast<Expression &>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv+*this;
       return res;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
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

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv/(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv/(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       Expression &tmp=dynamic_cast<Expression &>(t);
       /*complexe conv(tmp.toQString());
       type * res;
       res=conv/(*this);*/
       //return res;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv/(*this);
       return res;
    }
    catch(std::exception &e){}
    throw typeException("erreur complexe");
}

type* complexe::operator*(type& t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= dynamic_cast<nocomplex*> (*(*re * *tmp.re)-*(*im * *tmp.im));
       res->im= dynamic_cast<nocomplex*>(*(*re * *tmp.im)+*(*im * *tmp.re));
       return res;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv*(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv*(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       Expression &tmp=dynamic_cast<Expression &>(t);
       /*complexe conv(tmp.toQString());
       type * res;
       res=conv/(*this);*/
       //return res;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv*(*this);
       return res;
    }
    catch(std::exception &e){}
    throw typeException("erreur complexe");
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

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv-(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv-(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       Expression &tmp=dynamic_cast<Expression &>(t);
       /*complexe conv(tmp.toQString());
       type * res;
       res=conv/(*this);*/
       //return res;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       complexe conv(tmp.toQString());
       type * res;
       res=conv-(*this);
       return res;
    }
    catch(std::exception &e){}
    throw typeException("erreur complexe");
}

QString complexe::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << re->toQString() <<'$'<< im->toQString();
    return res;
}

type* complexe::sign(){
    nocomplex* res_re;
    nocomplex* res_im;
    res_re=dynamic_cast<nocomplex*>(re->sign());
    res_im=dynamic_cast<nocomplex*>(im->sign());
    type* t= new complexe(res_re,res_im);
    return t;
}
