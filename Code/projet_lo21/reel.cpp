#include "reel.h"


type& reel::operator =(type & t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       data=tmp.data;
       return *this;
    }
    catch(std::exception &e){}
}

type& reel::operator +(type & t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data+tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}

type& reel::operator /(type & t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data/tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}

type& reel::operator*(type& t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data*tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}

type& reel::operator-(type& t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *res=new reel(data-tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}


QString reel::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << data;
    return res;
}


