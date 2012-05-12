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

std::string reel::toString(){
    std::stringstream ss;
    ss << data ;
    return ss.str();
}

QString reel::toQString(){
    QTextStream ss;
    ss << data;
    return ss.readAll();
}


