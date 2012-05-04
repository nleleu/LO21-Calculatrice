#include "collection_pile.h"

Collection_pile* Collection_pile::instance=0;

Collection_pile& Collection_pile::getInstance()
{
    if (instance==0)
        instance = new Collection_pile;
    return *instance;

}

void Collection_pile::releaseInstance()
{
    if (instance!=0)
        delete instance;

}
