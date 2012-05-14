#ifndef REGLAGES_H
#define REGLAGES_H

#include <QDialog>

namespace Ui {
class reglages;
}

class reglages : public QDialog
{
    Q_OBJECT
    
public:
    explicit reglages(QWidget *parent = 0);
    ~reglages();
    
private:
    Ui::reglages *ui;
};

#endif // REGLAGES_H
