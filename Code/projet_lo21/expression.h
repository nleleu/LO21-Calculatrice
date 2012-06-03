#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QString>
#include "type.h"

class Expression : public type
{
    QString exp;
public:
    Expression(QString &exp1);
    type* evaluer();
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

    type* ln(){}
    type* log(){}
    type* inv(){}
    type* sqrt(){}
    type* sqr(){}
    type* cube(){}
    type* fact(){}
    type* eval(){}

    static bool isExpression(const QString& s){return s.contains ('\'');}
    QString toQString(){return exp;}
};

#endif // EXPRESSION_H
