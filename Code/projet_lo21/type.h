#ifndef TYPE_H
#define TYPE_H

#include <sstream>
#include <QString>
#include <QTextStream>
#include "typeexception.h"
#include <QMessageBox>


class type
{

public:
    type();
    //virtual type& operator=(type & t)=0;
    virtual type* operator+(type & t)=0;
    virtual type* operator/(type & t)=0;
    virtual type* operator*(type & t)=0;
    virtual type* operator-(type & t)=0;

    virtual type* pow(type & t)=0;
    virtual type* mod(type & t);
    virtual type* sign()=0;

    virtual type* sinus()=0;
    virtual type* cosinus()=0;
    virtual type* tangente()=0;
    virtual type* sinush()=0;
    virtual type* cosinush()=0;
    virtual type* tangenteh()=0;

    virtual type* ln()=0;
    virtual type* log()=0;
    virtual type* inv()=0;
    virtual type* sqrt()=0;
    virtual type* sqr()=0;
    virtual type* cube()=0;
    virtual type* fact();
    virtual type* eval()=0;

    static bool isEntier(const QString& s){QRegExp rx("^\\d+$"); return s.contains (rx);}

    static bool isReel(const QString& s){
        QString copie(s);
        copie.replace(',', '.');
        QRegExp rx("^-?\\d*\\.?\\d*$");
        return copie.contains(rx);}

    static bool isRationnel(const QString& s){QRegExp rx("^-?\\d*/-?\\d*$");  return s.contains (rx);}

    static bool isExpression(const QString& s){return s.contains ('\'');}

    static bool isComplexe(const QString& s){QRegExp rx("^-?\\d*(/|\\.)?\\$-?\\d*/?.?$");return s.contains (rx);}

    virtual QString toQString()=0;
};

#endif // TYPE_H
