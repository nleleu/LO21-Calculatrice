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


    if(currentStack > 0 && currentStack < 10)
    {
     currentStack -= 1;
     return tabPile.at(currentStack);
    }

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
