#include "pile.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "mainwindow.h"
#include <QDebug>

using namespace std;

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

            type* sumVect;

            //reconnaissance du type de constante
            switch(MainWindow::selectedConstType){
                case ENTIER:
                {
                    sumVect=new entier;

                    for(iterator it=begin(); it!=end(); it++){
                        *sumVect=*sumVect+*(*it);
                    }

                    push(sumVect);
                }
                    break;

                case REEL:
                {
                    sumVect=new reel;

                    for(iterator it=begin(); it!=end(); it++){
                        *sumVect=*sumVect+*(*it);
                    }

                    push(sumVect);
                }
                    break;

                case RATIONNEL:
                {
                    sumVect=new rationnel;

                    for(iterator it=begin(); it!=end(); it++){
                        *sumVect=*sumVect+*(*it);
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
            //A implementer
            break;
        }

        default:
            qDebug()<<"probleme somme, complexUse non detecte";
            break;
        }
    }
}

void Pile::mean(const unsigned int x){  //A revoir
    if(size()>0){
        type *tmp(0),*res=new entier;
        int y=x;

        if(x>size())
            y=size();

        for(int i=0; i<y; i++)
            *tmp=*tmp+*pop();
        *res=*tmp/y;
        push(res);
    }
}


