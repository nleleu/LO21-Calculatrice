#include "invoker.h"

Invoker::Invoker(Pile& pile): pileActuelle(pile)
{
    currentStack = 0;
    tabPile.push_back(pileActuelle);
}


void Invoker::placeOrder(Operation* op){
    //if(currentStack < 10)
        currentStack += 1;
    //tabPile.resize(currentStack);
    tabOperation.push_back(op);
    tabOperation.first()->execute();

    tabPile.push_back(pileActuelle);


    /*while(tabOperation.size()>10){
        tabOperation.pop_front();
    }*/
}

void Invoker::undo(){
    currentStack -= 1;
    //if(currentStack > 0 && currentStack < 10)
    //pileActuelle = tabPile[1];//.at(currentStack);
    qDebug()<<tabPile[0].isEmpty();
    qDebug()<<tabPile[1].isEmpty();
    //qDebug()<<tabPile[0].top()->toQString();
    qDebug()<<tabPile[1].top()->toQString();
}

void Invoker::redo(){
    currentStack += 1;
    //if(currentStack >= 0 && currentStack < 8)
        pileActuelle = tabPile.at(currentStack);
}
