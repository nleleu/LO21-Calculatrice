#include "rationnel.h"


type& rationnel::operator =(type & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       num=tmp.num;
       denum=tmp.denum;
       return *this;
    }
    catch(std::exception &e){}
}

std::string rationnel::toString(){
    std::stringstream ss;
    ss << num << "/" << denum;
    return ss.str();
}
