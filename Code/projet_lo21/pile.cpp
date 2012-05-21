#include "pile.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "mainwindow.h"
#include <QDebug>
#include "dom.h"

using namespace std;

Pile::Pile():nbElt(5){
    Dom xml(*this);

    xml.lire();
}

Pile::~Pile(){
    int i(1);
    Dom xml(*this);
    xml.newfic();
    while(!isEmpty()){
        QString str;
        xml.demande_ajout(str.setNum(i), (pop()->toQString()));
        i++;
    }
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
type * res;
type *op1 = pop();
type *op2 = pop();
res=*op2+(*op1);
delete op1;
delete op2;
push(res);

}

void Pile::soustraction()
{
type * res;
type *op1 = pop();
type *op2 = pop();
res=*op2-(*op1);
delete op1;
delete op2;
push(res);

}


void Pile::multiplication()
{
type * res;
type *op1 = pop();
type *op2 = pop();
res=*op2*(*op1);
delete op1;
delete op2;
push(res);

}



void Pile::division()
{
type * res;
type *op1 = pop();
type *op2 = pop();
res=*op2/(*op1);
delete op1;
delete op2;
push(res);

}

void Pile::parser(QString s)
{
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
//if(complexe::isComplexe(ui->lineEdit->text()))
    //*test=new complexe(ui->lineEdit->text().toStdString());
        }
}



}
