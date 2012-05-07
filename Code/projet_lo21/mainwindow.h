#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "pile.h"
#include "type.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Pile &pile, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_pushButton0_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();


    void on_stackButton_clicked();
    void on_affichePile_clicked();
    void on_swap_clicked();
    void on_sum_clicked();
    void on_mean_clicked();
    void on_clear_clicked();
    void on_dup_clicked();
    void on_drop_clicked();

signals:
    void ajouterStack(const QString&);
    void nettoyerList();
    void refresh_signal();

private:
    Ui::MainWindow *ui;
    Pile &_pile;
};

#endif // MAINWINDOW_H
