#ifndef INVOKER_H
#define INVOKER_H

#include <QVector>
#include "pile.h"
#include <QString>
#include "operation.h"

class Invoker
{
    QVector<Operation*> tabOperation;
    int currentStack;
    QVector<Pile> tabPile;
    Pile& pileActuelle;

public:
    Invoker(Pile& pile);
    void undo();
    void redo();
    void placeOrder(Operation*);
};

#endif // INVOKER_H
