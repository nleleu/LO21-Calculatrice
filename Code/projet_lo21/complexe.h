#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "type.h"
#include <sstream>
#include <QString>
#include "nocomplex.h"
#include "type_factory.h"

#include "constante.h"

class complexe:public constante
{
    nocomplex*  re;
    nocomplex* im;
public:
    complexe(nocomplex* _re=0,nocomplex* _im=0):re(_re), im(_im){}
    /*complexe(const std::string &s){
        std::istringstream iss1(s);//pour convertir une string en int
        iss1 >> data;
    }*/
    complexe(const QString &s)//pour convertir une QString en complexe
    {
        QString copie(s);

        re=dynamic_cast<nocomplex*>(type_factory::getInstance().getType((copie.section('$', 0,0))));
        im=dynamic_cast<nocomplex*>(type_factory::getInstance().getType((copie.section('$', 1,1))));
    }

    type* operator +(type & t);
    type* operator /(type & t);
    type* operator*(type& t);
    type* operator-(type& t);

    type* sinus(){}
    type* cosinus(){}
    type* tangente(){}
    type* sinush(){}
    type* cosinush(){}
    type* tangenteh(){}


    nocomplex* getRe(){return re;}
    nocomplex* getIm(){return im;}
    //type& operator/(int & i){}
    //type& operator/(double & i){}
    QString toQString();


    static bool isComplexe(const QString& s){return s.contains ("$");}
};

#endif // COMPLEXE_H
