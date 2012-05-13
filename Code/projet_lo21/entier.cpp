#include "entier.h"
#include <exception>
#include "reel.h"
#include "rationnel.h"
#include <QDebug>

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
}


/*type* entier::operator/(int & i)
{
    entier *res=new entier(data/i);
    return res;
}
*/
/*type& entier::operator/(double & i)
{

}*/



QString entier::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << data;
    return res;
}
