#include "entier.h"
#include <exception>

type& entier::operator +(type & t)
{
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(this->data+tmp.getData());
       return *res;
    }
    catch(std::exception &e){}


}

type& entier::operator /(type & t)
{
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(this->data/tmp.getData());
       return *res;
    }
    catch(std::exception &e){}


}


type& entier::operator/(int & i)
{
    entier *res=new entier(this->data/i);
    return *res;
}

type& entier::operator/(double & i)
{

}

std::string entier::toString()
{
    std::stringstream ss;
    ss << data;
    return ss.str();
}
