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
#include "typeexception.h"
 #include <QRegExp>

#define M_PI  3.14159265

using namespace std;

Pile::Pile():nbElt(5){
    g=new gardien;
    degre=true;
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
                qDebug()  << t[i];
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


