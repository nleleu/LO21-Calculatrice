#include "gardien.h"
#include "pile.h"
#include <QDebug>

gardien::gardien()
{
    currentStack = -1;
}

void gardien::addMemento(Pile pile){
tabPile.push_back(pile.clone());
currentStack++;

}

Pile gardien::undo(){

    qDebug()<<tabPile.size();
    if(currentStack > 0 && currentStack < 10)
    {
     currentStack -= 1;
     return tabPile.at(currentStack);
    }


    //qDebug()<<tabPile[0].isEmpty();
    //qDebug()<<tabPile[1].isEmpty();
    //qDebug()<<tabPile[0].top()->toQString();
    //qDebug()<<tabPile[1].top()->toQString();
}

Pile gardien::redo(){
    if(currentStack >= 0 && currentStack < 10)
    {
     currentStack += 1;
     return tabPile.at(currentStack);
    }

    else
        qDebug()<<"vide";
}
