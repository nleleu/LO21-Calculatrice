#include "expression.h"
#include "type_factory.h"
#include <QDebug>

Expression::Expression(QString& exp1): exp(exp1)
{
}

type* Expression::operator +(type & t){
    exp = exp + ' ' + t.toQString() + ' ' + "+'";
    qDebug() << exp;
    return new Expression(exp);
}

type* Expression::operator -(type & t){
    exp = exp + ' ' + t.toQString() + ' ' + "-";
}


type* Expression::operator *(type & t){
    exp = exp + ' ' + t.toQString() + ' ' + "*";
}


type* Expression::operator /(type & t){
    exp = exp + ' ' + t.toQString() + ' ' + "/";
}


