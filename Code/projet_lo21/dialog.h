#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStack>
#include "pile.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(Pile &pile, QWidget *parent = 0);
    ~Dialog();

public slots:
    void stocke(const QString& t);
    void on_addition_clicked();
    void listNettoye();
    
private:
    Ui::Dialog *ui;
    Pile &_pile;
};

#endif // DIALOG_H
