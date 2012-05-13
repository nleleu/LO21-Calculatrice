#include "entier.h"
#include <exception>



type& entier::operator =(type &t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       data=tmp.data;
       return *this;
    }
    catch(std::exception &e){}
}

type& entier::operator +(type & t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data+tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}

type& entier::operator /(type & t)
{
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data/tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}

type& entier::operator*(type& t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data*tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}

type& entier::operator-(type& t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *res=new entier(data-tmp.getData());
       return *res;
    }
    catch(std::exception &e){}
}


/*type& entier::operator/(int & i)
{
    entier *res=new entier(data/i);
    return *res;
}

type& entier::operator/(double & i)
{

}*/



QString entier::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << data;
    return res;
}
