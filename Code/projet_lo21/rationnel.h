#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "type.h"
#include <iostream>
#include <sstream>
#include <QString>
#include <qDebug>
#include "nocomplex.h"
#include "typeexception.h"
#include <QRegExp>


int pgcd(int a, int b);

class rationnel:public nocomplex
{
    int num;/*!<  Numerateur*/
    int denum;/*!< Denominateur*/
public:
    rationnel(int _num=0,int _denum=1):num(_num),denum(_denum){if (denum==0) throw typeException("Division par 0"); simplifie();}
    rationnel(const std::string &s){
        int pos;
        pos=s.find('/'); //caractere separateur
        int n,d;
        std::string res1,res2;
        res1=s.substr(0,pos);
        res2=s.substr(pos+1);
        std::istringstream iss1(res1);//pour convertir une string en int
        std::istringstream iss2(res2);
        iss1 >> n;
        iss2 >> d;

        num=n;
        denum=d;
        if (denum==0) throw typeException("Division par 0");
    }

    rationnel(const QString &s)//pour convertir une QString en rationnel
    {
        QString copie(s);

        num=(copie.section('/', 0,0)).toInt();
        denum=(copie.section('/', 1,1)).toInt();
         if (denum==0) throw typeException("Division par 0");
        simplifie();

    }

    type* operator +(type & t);
    type* operator /(type & t);
    type* operator*(type& t);
    type* operator-(type& t);

    type* pow(type & t);
    type* sign();

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
    type* eval(){}


    void simplifie();
    int pgcd(int, int ) const;
    QString toQString();

    int getNum(){return num;}
    int getDenum(){return denum;}

    static bool isRationnel(const QString& s){QRegExp rx("^-?\\d*/-?\\d*$");if (s.contains (rx)) qDebug() << "ratio";  return s.contains (rx);}
};

#endif // RATIONNEL_H
