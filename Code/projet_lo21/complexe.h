#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "type.h"
#include <sstream>
#include <QString>
#include "nocomplex.h"
#include "complex_abs.h"


class complexe:public complex_abs //A revoir, la classe complexe actuelle ne prend que des constantes entières
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

        /*re=(copie.section('$', 0,0)).toInt();
        im=(copie.section('$', 1,1)).toInt();*/
    }

    type* operator =(type & t);
    type* operator +(type & t);
    type* operator /(type & t);
    type* operator*(type& t);
    type* operator-(type& t);


    nocomplex* getRe(){return re;}
    nocomplex* getIm(){return im;}
    //type& operator/(int & i){}
    //type& operator/(double & i){}
    QString toQString();

    static bool isComplexe(const QString& s){return s.contains ("$");}
};

#endif // COMPLEXE_H
