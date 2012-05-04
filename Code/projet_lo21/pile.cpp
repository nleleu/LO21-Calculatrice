#include "pile.h"
#include "entier.h"


void Pile::swap(const unsigned int x, const unsigned int y){
    if (x < this->size() && y < this->size()){
        type * tmp = at(size()-1-x);
        replace(size()-1-x, at(size()-1-y));
        replace(size()-1-y, tmp);
    }
}

void Pile::sum(const unsigned int x){
    if(size()>0){
        type * tmp=new entier;
        for(int i=0; i<x && i<size(); i++)
            *tmp=*tmp+*pop();
        push(tmp);
    }
}

void Pile::mean(const unsigned int x){
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


