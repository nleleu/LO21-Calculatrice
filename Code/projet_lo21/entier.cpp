#include "entier.h"
#include <exception>
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include <QDebug>
#include <math.h>

#define PI 3.14159265

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

}

type* entier::operator /(type & t)
{
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data/tmp.getData());
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
}



QString entier::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << data;
    return res;
}

type* entier::sinus(){
    double tmp(data);
    tmp=sin(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* entier::cosinus(){
    double tmp(data);
    tmp=cos(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* entier::tangente(){
    double tmp(data);
    tmp=tan(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* entier::sinush(){
    double tmp(data);
    tmp=sinh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* entier::cosinush(){
    double tmp(data);
    tmp=cosh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}

type* entier::tangenteh(){
    double tmp(data);
    tmp=tanh(tmp*PI/180);
    type* t= new reel(tmp);
    return t;
}
