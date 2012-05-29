#ifndef COLLECTION_PILE_H
#define COLLECTION_PILE_H

#include <vector>
#include "pile.h"
#include <QString>

class Collection_pile :public std::vector<Pile *>
{
    static Collection_pile * instance;
    int actif;


    Collection_pile (const Collection_pile&);

    ~Collection_pile(){}
    Collection_pile(){}
    Collection_pile operator =(const Collection_pile);
public:
    static Collection_pile& getInstance();
    static void releaseInstance();
    void addPile (Pile * _pile);
    void setActif (int a){actif=a;}
    int getActif (){return actif;}

};
#endif // COLLECTION_PILE_H
