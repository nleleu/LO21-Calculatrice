#include "pile.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include <QDebug>
#include "dom.h"
#include <cmath>
#include "typeexception.h"
#include <QRegExp>


using namespace std;

Pile::Pile():nbElt(5){
    g=new gardien;
    degre=true;
}

void Pile::sauvegarder(QString fileName){
    Dom xml(*this);
    xml.ecrire(fileName);
}

void Pile::charger(QString fileName){
    Dom xml(*this);
    xml.lire(fileName);
}


Pile::~Pile(){
    for(int i=0; i<size(); i++){
       delete at(i);
    }
    if(g)
    delete g;
}



Pile& Pile::clone() const{
    Pile *p=new Pile();
    for(int i=0; i<size(); i++){
        p->push(type_factory::getInstance().getType(at(i)->toQString()));
    }
    p->setGardien(getGardien());
    p->setDegre(getDegre());
    return *p;
}


Pile& Pile::duplique() const{
    Pile *p=new Pile();
    for(int i=0; i<size(); i++){
        p->push(type_factory::getInstance().getType(at(i)->toQString()));
    }
    p->setGardien(new gardien);
    p->setDegre(getDegre());
    return *p;
}


void Pile::swap(){
    if(this->size() > 1){
        unsigned int x,y;
        g->addMemento(this);
        type *op1 = pop();
        type *op2 = pop();
        try{

           entier &e1=dynamic_cast<entier&>(*op1);
           entier &e2=dynamic_cast<entier&>(*op2);
           x=(unsigned int)e1.getData();
           y=(unsigned int)e2.getData();
           if (x < (unsigned int)this->size() && y < (unsigned int)this->size()){
               type * tmp = at(size()-1-x);
               replace(size()-1-x, at(size()-1-y));
               replace(size()-1-y, tmp);
               g->addMemento(this);
           }
        }
        catch(std::exception &e){}

    }
}

void Pile::sum(){
    if(this->size() > 1){
        try{
            unsigned int x;
            type *op1 = pop();
           entier &e1=dynamic_cast<entier&>(*op1);
           x=(unsigned int)e1.getData();
        type* sumVect=new entier(0);
        type* tmp;
        unsigned int j=0;
        for(iterator it=end()-1; it>=begin()&& j<x; it--){
            tmp=sumVect;
            sumVect=*sumVect+*(*it);
            delete tmp;
            j++;
        }
        g->addMemento(this);
        push(sumVect);
        g->addMemento(this);
    }
      catch(std::exception &e){}
    }
}

void Pile::mean(){

   if(this->size() > 1){
       unsigned int x;
        try{
           type *op1 = pop();
           entier &e1=dynamic_cast<entier&>(*op1);
           x=(unsigned int)e1.getData();
            type* sumVect=new entier(0);
            type* tmp;
            unsigned int j=0;
            for(iterator it=end()-1; it>=begin()&& j<x; it--){
                tmp=sumVect;
                sumVect=*sumVect+*(*it);
                delete tmp;
                j++;
            }

            entier taille(j);
            tmp=sumVect;
            sumVect=*sumVect/taille;
            delete tmp;
            g->addMemento(this);
            push(sumVect);
            g->addMemento(this);
        }
          catch(std::exception &e){}
    }

}

void Pile::addition()
{
    if(this->size() > 1){
        g->addMemento(this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        try
        {
        res=*op2+(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(this);
        }
        catch (std::exception &e) {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}

void Pile::soustraction()
{
    if(this->size() > 1){
        g->addMemento(this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        try{
        res=*op2-(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(this);
        }
        catch (std::exception &e) {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}


void Pile::multiplication()
{
    if(this->size() > 1){
        g->addMemento(this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        try{
        res=*op2*(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(this);
        }
        catch (std::exception &e) {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}



void Pile::division()
{
    if(this->size() > 1){
        g->addMemento(this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        try{
        res=*op2/(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(this);
        }
        catch (std::exception &e) {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}

void Pile::pow()
{
    if(this->size() > 1){
        g->addMemento(this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        try{
        res=op2->pow(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(this);
        }
        catch (std::exception &e) {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}

void Pile::mod()
{
    if(this->size() > 1){
        g->addMemento(this);
        type * res;
        type *op1 = pop();
        type *op2 = pop();
        try
        {
        res=op2->mod(*op1);
        delete op1;
        delete op2;
        push(res);
        g->addMemento(this);
        }
        catch (std::exception &e) {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}

void Pile::parser(QString s)
{
    if(!Expression::isExpression(s)){
        type* test=0;

        QRegExp rx("\\s+");
        QStringList t=(s.split(rx));
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
                    sinus(degre);
            else if (t[i]=="cos")
                    cosinus(degre);
            else if (t[i]=="tan")
                    tangente(degre);
            else if (t[i]=="sinh")
                    sinush(degre);
            else if (t[i]=="cosh")
                    cosinush(degre);
            else if (t[i]=="tanh")
                    tangenteh(degre);
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
                if (test)
                    push(test);
                else
                {
                    QMessageBox msgBox;
                    msgBox.setText("Erreur de saisie, type non reconnu");
                     msgBox.exec();



                }
             }
        }
    }

    else
    {

        push(new Expression(s));
    }

}

void Pile::sign(){

    if(this->size() > 0){

       g->addMemento(this);
       type *op = pop();
       type *res;
       try{
       res=op->sign();
       delete op;
       push(res);
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
     msgBox.setText(e.what());
     msgBox.exec();
           push(op);
       }


     }
}


void Pile::sinus(bool degre){

    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->sinus(degre);
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
           push(op);
       }
    }
}



void Pile::cosinus(bool degre){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->cosinus(degre);
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::tangente(bool degre){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->tangente(degre);
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::sinush(bool degre){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->sinush(degre);
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::cosinush(bool degre){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->cosinush(degre);
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::tangenteh(bool degre){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->tangenteh(degre);
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}



void Pile::ln(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->ln();
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::log(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->log();
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::inv(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->inv();
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::sqrt(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->sqrt();
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::sqr(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->sqr();
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::cube(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->cube();
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::fact(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        type *res;
        try{
       res=op->fact();
       push(res);
       delete op;
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::eval(){
    if(this->size() > 0){
        g->addMemento(this);
        type *op = pop();
        QString res;
        try{
       res=op->eval();
       parser(res);
       g->addMemento(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
           push(op);
       }
    }
}


