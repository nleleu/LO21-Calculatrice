#include "gardien.h"
#include "pile.h"


gardien::gardien()
{
    currentStack = -1;
}


gardien::~gardien()
{
    for(int i=0; i<tabPile.size(); i++){
       delete tabPile.at(i);
    }
}



void gardien::addMemento(Pile *pile){

tabPile.push_back(&pile->clone());
currentStack++;



}

Pile* gardien::undo(){


    if(currentStack > 0)
    {
     currentStack -= 1;
     return &tabPile.at(currentStack)->clone();
    }
    return 0;

}

Pile* gardien::redo(){
    if(currentStack >= 0 && currentStack < tabPile.size()-1)
    {
     currentStack += 1;
     return &tabPile.at(currentStack)->clone();
    }
    return 0;
}
