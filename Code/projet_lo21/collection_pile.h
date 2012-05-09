#ifndef COLLECTION_PILE_H
#define COLLECTION_PILE_H

#include <vector>
#include "pile.h"
#include <QString>

class Collection_pile
{
    std::vector<Pile> collection;
    static Collection_pile * instance;


    Collection_pile (const Collection_pile&);
    ~Collection_pile(){}
    Collection_pile(){}
    Collection_pile operator =(const Collection_pile);
public:
    static Collection_pile& getInstance();
    static void releaseInstance();

};
#endif // COLLECTION_PILE_H
