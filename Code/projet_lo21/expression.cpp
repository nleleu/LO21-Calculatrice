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


type* Expression::sinus(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sin'";
    return new Expression(exp);

}

type* Expression::pow(type & t)
{
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "pow'";
    return new Expression(exp);

}

type* Expression::sign()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sign'";
    return new Expression(exp);
}




type* Expression::cosinus(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "cos'";
    return new Expression(exp);
}



type* Expression::tangente(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "tan'";
    return new Expression(exp);
}

type* Expression::sinush(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sinh'";
    return new Expression(exp);
}


type* Expression::cosinush(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "cosh'";
    return new Expression(exp);
}

type* Expression::tangenteh(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "tanh'";
    return new Expression(exp);
}


type* Expression::ln()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "ln'";
    return new Expression(exp);
}


type* Expression::log()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "log'";
    return new Expression(exp);
}

type* Expression::inv()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "inv'";
    return new Expression(exp);
}


type* Expression::sqrt()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sqrt'";
    return new Expression(exp);
}


type* Expression::sqr()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sqr'";
    return new Expression(exp);
}

type* Expression::cube()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "cube'";
    return new Expression(exp);
}






QString Expression::eval(){
    return exp.remove("'");
}



