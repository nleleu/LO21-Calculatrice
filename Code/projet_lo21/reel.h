#ifndef REEL_H
#define REEL_H

#include "type.h"
#include <sstream>
#include <QString>
#include <qDebug>
#include "nocomplex.h"

class reel:public nocomplex
{
    double data;
public:
    reel(double val=0):data(val){}
    /*reel(const std::string &s){
        std::istringstream iss1(s);//pour convertir une string en int
        iss1 >> data;
    }*/

    reel(const QString &s)//pour convertir une QString en double
    {
        QString copie(s);
        copie.replace(',', '.');
        data = copie.toDouble();
    }

    type& operator =(type & t);
    type* operator +(type & t);
    type* operator /(type & t);
    type* operator*(type& t);
    type* operator-(type& t);

    type* sinus();
    type* cosinus();
    type* tangente();
    type* sinush();
    type* cosinush();
    type* tangenteh();

    type* ln();
    type* log();
    type* inv();
    type* sqrt();
    type* sqr();
    type* cube();
    type* fact(){}
    type* eval(){}

    double getData(){return data;}
    QString toQString();

    static bool isReel(const QString& s){return s.contains (",");}
};

#endif // REEL_H
