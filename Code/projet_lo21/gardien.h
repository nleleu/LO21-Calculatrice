#ifndef GARDIEN_H
#define GARDIEN_H

#include <QVector>
#include <QStack>
#include "type.h"


class Pile;

class gardien
{
    int currentStack;
    QVector <Pile> tabPile;

public:
    gardien();
    Pile* undo();
    Pile* redo();
    void addMemento(Pile pile);
};

#endif // GARDIEN_H
