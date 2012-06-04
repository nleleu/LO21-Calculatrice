#include "pile.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "mainwindow.h"
#include <QDebug>
#include "dom.h"
#include <cmath>

#define PI 3.14159265

using namespace std;

Pile::Pile():nbElt(5){
    g=new gardien;
}

void Pile::sauvegarder(){
    Dom xml(*this);
    xml.ecrire(fileName);
}

void Pile::charger(){
    Dom xml(*this);
    xml.lire(fileName);
}

/*Pile::Pile(const Pile &p)
{

    nbElt=p.nbElt;


}*/

Pile::~Pile(){
//bug si delete sur tous les pointeurs de la pile, à revoir

}

//Selection de l'unite des degres
void Pile::on_degUnit_clicked(){
    Pile::selectedDegUnit=DEGRE;
}
void Pile::on_radUnit_clicked(){
    Pile::selectedDegUnit=RADIANT;
}

Pile& Pile::clone() const{
    Pile *p=new Pile();
    for(int i=size()-1; i>=0; i--){
        p->push(type_factory::getInstance().getType(at(i)->toQString()));
    }
    p->setGardien(getGardien());
    return *p;
}


Pile& Pile::duplique() const{
    Pile *p=new Pile();
    for(int i=size()-1; i>=0; i--){
        p->push(type_factory::getInstance().getType(at(i)->toQString()));
    }
    p->setGardien(new gardien);
    return *p;
}


void Pile::swap(const unsigned int x, const unsigned int y){
    if (x < this->size() && y < this->size()){
        type * tmp = at(size()-1-x);
        replace(size()-1-x, at(size()-1-y));
        replace(size()-1-y, tmp);
    }
}

void Pile::sum(const unsigned int x){
    if(!isEmpty()){

        type* sumVect;

        for(iterator it=begin(); it!=end(); it++){
            sumVect=*sumVect+*(*it);
        }

        push(sumVect);
    }
}

void Pile::mean(const unsigned int x){

    if(!isEmpty()){

            type* sumVect;

            for(iterator it=begin(); it!=end(); it++){
                sumVect=*sumVect+*(*it);
            }

            entier taille(size());
            sumVect=*sumVect/taille;
            push(sumVect);
    }

}

void Pile::addition()
{
    if(this->size() > 1){
        g->addMemento(*this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        res=*op2+(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(*this);
        }
}

void Pile::soustraction()
{
    if(this->size() > 1){
        g->addMemento(*this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        res=*op2-(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(*this);
    }
}


void Pile::multiplication()
{
    if(this->size() > 1){
        g->addMemento(*this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        res=*op2*(*op1);
        delete op1;
        delete op2;
        push(res);

        g->addMemento(*this);
    }
}



void Pile::division()
{
    if(this->size() > 1){
        g->addMemento(*this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        res=*op2/(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(*this);
    }
}

void Pile::pow()
{
    if(this->size() > 1){
        g->addMemento(*this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        res=op2->pow(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(*this);
        }
}

void Pile::mod()
{
    if(this->size() > 1){
        g->addMemento(*this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        res=op2->mod(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(*this);
        }
}

void Pile::parser(QString s)
{
    if(!Expression::isExpression(s)){
        type* test=0;
        QStringList t=(s.split(' '));
        for(int i=0; i<t.size();i++)
        {
            if (t[i]=="+")
                    addition();
            else if (t[i]=="-")
                    soustraction();
            else if (t[i]=="/")
                    division();
            else if (t[i]=="*")
                    multiplication();
            else if (t[i]=="pow")
                    pow();
            else if (t[i]=="mod")
                    mod();
            else if (t[i]=="sign")
                    sign();
            else if (t[i]=="sin")
                    sinus();
            else if (t[i]=="cos")
                    cosinus();
            else if (t[i]=="tan")
                    tangente();
            else if (t[i]=="sinh")
                    sinush();
            else if (t[i]=="cosh")
                    cosinush();
            else if (t[i]=="tanh")
                    tangenteh();
            else if (t[i]=="ln")
                    ln();
            else if (t[i]=="log")
                    log();
            else if (t[i]=="inv")
                    inv();
            else if (t[i]=="sqrt")
                    sqrt();
            else if (t[i]=="sqr")
                    sqr();
            else if (t[i]=="cube")
                    cube();
            else if (t[i]=="!")
                    fact();
            else
            {
                test=type_factory::getInstance().getType(t[i]);
                push(test);
             }
        }
    }

    else
    {
        QStringList t=(s.split("'"));
        for(int i=0; i<t.size();i++)
            qDebug() << t[i];
            //parser(t[i]);
        push(new Expression(s));
    }


}

void Pile::sign(){

    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->sign();
       push(op);
       g->addMemento(*this);
       return;
     }
}


void Pile::sinus(){

    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->sinus();
       push(op);
       g->addMemento(*this);
       return;
     }
}



void Pile::cosinus(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->cosinus();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::tangente(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->tangente();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::sinush(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->sinush();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::cosinush(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->cosinush();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::tangenteh(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->tangenteh();
       push(op);
       g->addMemento(*this);
       return;
     }
}



void Pile::ln(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->ln();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::log(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->log();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::inv(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->inv();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::sqrt(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->sqrt();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::sqr(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->sqr();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::cube(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->cube();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::fact(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->fact();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void Pile::eval(){
    if(this->size() > 0){

       g->addMemento(*this);
       type *op = pop();
       op=op->eval();
       push(op);
       g->addMemento(*this);
       return;
     }
}

void sauvegarde(){

}


