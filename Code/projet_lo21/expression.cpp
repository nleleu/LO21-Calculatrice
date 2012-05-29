#include "expression.h"
#include "type_factory.h"
#include "mainwindow.h"

Expression::Expression(QString& exp1): exp(exp1)
{
}

type* Expression::operator +(type & t){
    exp = exp + ' ' + t.toQString() + ' ' + "+";
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


