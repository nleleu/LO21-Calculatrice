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
    type* operator /(type & t){}
    type* operator*(type& t){}
    type* operator-(type& t){}
    static bool isExpression(const QString& s){return s.contains ('\'');}
    QString toQString(){return exp;}
};

#endif // EXPRESSION_H
