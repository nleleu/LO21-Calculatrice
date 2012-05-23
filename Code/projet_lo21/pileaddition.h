#ifndef PILEADDITION_H
#define PILEADDITION_H

#include "type.h"
#include "pile.h"
#include "operation.h"


class PileAddition : public Operation
{
    Pile& _pile;
public:
    PileAddition(Pile& pile): _pile(pile){}
    virtual void execute();
};

#endif // PILEADDITION_H
