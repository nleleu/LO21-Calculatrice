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
    Dom xml(*this);
    g=new gardien;
    xml.lire();
}

/*Pile::Pile(const Pile &p)
{

    nbElt=p.nbElt;


}*/

Pile::~Pile(){
//bug si delete sur tous les poiteurs de la pile, à revoir

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
            else
            {
                test=type_factory::getInstance().getType(t[i]);
                push(test);
             }
        }
    }

    else
        push(new Expression(s));


}


void Pile::sinus(){

    if(this->size() > 0){

        try{
           g->addMemento(*this);
           type * res;
           type *op = pop();
           entier &tmp=dynamic_cast<entier&>(*op);
           res=new reel(sin(tmp.getData()*PI/180));
           delete op;
           push(res);
           g->addMemento(*this);
           return;
        }
        catch(std::exception &e){}

        try{
           g->addMemento(*this);
           type * res;
           type *op = pop();
           reel &tmp=dynamic_cast<reel&>(*op);
           res=new reel(sin(tmp.getData()*PI/180));
           delete op;
           push(res);
           g->addMemento(*this);
           return;
        }
        catch(std::exception &e){}
        }
}


/*
void Pile::cos(){
    if(this->size() > 0){
        g->addMemento(*this);
        type * res;
        type *op = pop();
        res=cos(*op);
        delete op;
        push(res);
        g->addMemento(*this);
        }
}

void Pile::tan(){
    if(this->size() > 0){
        g->addMemento(*this);
        type * res;
        type *op = pop();
        res=tan(*op);
        delete op;
        push(res);
        g->addMemento(*this);
        }
}

void Pile::sinh(){
    if(this->size() > 0){
        g->addMemento(*this);
        type * res;
        type *op = pop();
        res=sinh(*op);
        delete op;
        push(res);
        g->addMemento(*this);
        }
}

void Pile::cosh(){
    if(this->size() > 0){
        g->addMemento(*this);
        type * res;
        type *op = pop();
        res=cosh(*op);
        delete op;
        push(res);
        g->addMemento(*this);
        }
}

void Pile::tanh(){
    if(this->size() > 0){
        g->addMemento(*this);
        type * res;
        type *op = pop();
        res=tanh(*op);
        delete op;
        push(res);
        g->addMemento(*this);
        }
}
*/
