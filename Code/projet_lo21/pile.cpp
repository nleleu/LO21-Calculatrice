#include "pile.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "mainwindow.h"
#include <QDebug>
#include "dom.h"

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
    /*int i(1);
    Dom xml(*this);
    xml.newfic();
    while(!isEmpty()){
        QString str;
        xml.demande_ajout(str.setNum(i), (pop()->toQString()));
        i++;
    }
    */
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

        //selection de l'utilisation des complexes
        switch(MainWindow::selectedComplexUse){
        case NO:
        {

            //reconnaissance du type de constante
            switch(MainWindow::selectedConstType){
                case ENTIER:
                {
                    type* sumVect= new entier;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }

                    push(sumVect);
                }
                    break;

                case REEL:
                {
                    type* sumVect= new reel;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }
                    push(sumVect);
                }
                    break;

                case RATIONNEL:
                {
                    type* sumVect=new rationnel;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }

                    push(sumVect);
                }
                    break;

                default:
                    qDebug()<<"probleme somme, constType non detecte";
                    break;
            }
        }
            break;

        case YES:
        {

            //reconnaissance du type de constante
            switch(MainWindow::selectedConstType){
                case ENTIER:
                {
                    type* sumVect= new complexe;


                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);

                    }

                    push(sumVect);
                }
                    break;

                case REEL:
                {
                    type* sumVect= new complexe;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }

                    push(sumVect);
                }
                    break;

                case RATIONNEL:
                {
                    type* sumVect= new complexe;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }

                    push(sumVect);
                }
                    break;

                default:
                    qDebug()<<"probleme somme, constType non detecte";
                    break;
            }
        }
             break;

        default:
            qDebug()<<"probleme somme, complexUse non detecte";
            break;
        }
    }
}

void Pile::mean(const unsigned int x){//A reviser: ne calcule qu'une seule fois la moyenne
    if(!isEmpty()){

        //selection de l'utilisation des complexes
        switch(MainWindow::selectedComplexUse){
        case NO:
        {
            type* sumVect;

            //reconnaissance du type de constante
            switch(MainWindow::selectedConstType){
                case ENTIER:
                {
                    sumVect=new entier;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }

                    entier taille(size());
                    sumVect=*sumVect/taille;
                    push(sumVect);
                }
                    break;

                case REEL:
                {
                    sumVect=new reel;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }

                    reel taille(size());
                    sumVect=*sumVect/taille;
                    push(sumVect);
                }
                    break;

                case RATIONNEL:
                {
                    sumVect=new rationnel;

                    for(iterator it=begin(); it!=end(); it++){
                        sumVect=*sumVect+*(*it);
                    }

                    rationnel taille(size());
                    sumVect=*sumVect/taille;
                    push(sumVect);
                }
                    break;

                default:
                    qDebug()<<"probleme mean, constType non detecte";
                    break;
            }
        }
        break;

        case YES:
        {
            //A implementer
            break;
        }

        default:
            qDebug()<<"probleme mean, complexUse non detecte";
            break;
        }
    }
}

void Pile::addition()
{
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

void Pile::soustraction()
{
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


void Pile::multiplication()
{
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



void Pile::division()
{
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
