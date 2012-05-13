#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "type.h"
#include <iostream>
#include <sstream>
#include <QString>


int pgcd(int a, int b);

class rationnel:public type
{
    int num;
    int denum;
public:
    rationnel(int _num=0,int _denum=1):num(_num),denum(_denum){}
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
    }

    rationnel(const QString &s)//pour convertir une QString en rationnel
    {
        QString copie(s);
        num=(copie.section('/', 0)).toInt();
        denum=(copie.section('/', 1)).toInt();
    }

    type* operator =(type & t);
    type* operator +(type & t);
    type* operator /(type & t);
    type* operator*(type& t);
    type* operator-(type& t);

    //type& operator/(int & i){}      //a implementer
    //type& operator/(double & i){}   //a implementer
    void simplifie();
    QString toQString();

    static bool isRationnel(const QString& s){return s.contains ("/");}
};

#endif // RATIONNEL_H
