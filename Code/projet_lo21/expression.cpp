#include "expression.h"
#include "type_factory.h"
#include <QDebug>
#include "typeexception.h"

Expression::Expression(QString& exp1): exp(exp1)
{
}

type* Expression::operator +(type & t){

    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "+'";
    return new Expression(exp);
}

type* Expression::operator -(type & t){
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "-'";
    return new Expression(exp);
}


type* Expression::operator *(type & t){
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "*'";
    return new Expression(exp);
}


type* Expression::operator /(type & t){
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "/'";
    return new Expression(exp);
}

QString Expression::eval(){
    return exp.remove("'");
}



