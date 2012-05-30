#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "pile.h"
#include "type.h"
#include <QString>
#include "reglages.h"
#include "collection_pile.h"

enum constType{ENTIER, REEL, RATIONNEL};
enum complexUse{YES, NO};
enum degUnit{DEGRE, RADIANT};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Pile &pile, QWidget *parent);
    ~MainWindow();
    static constType selectedConstType;
    static complexUse selectedComplexUse;
    static degUnit selectedDegUnit;


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


    //operations sur la pile
    void on_stackButton_clicked();
    void on_affichePile_clicked();
    void on_swap_clicked();
    void on_sum_clicked();
    void on_mean_clicked();
    void on_clear_clicked();
    void on_dup_clicked();
    void on_drop_clicked();


    void pushStack_slot(const QString& t);
    void on_addition_clicked();
    void cleanList_slot();
    void refresh_slot();
    void on_backspace_clicked();

    void on_complexeButton_clicked();
    void on_reelButton_clicked();
    void on_rationnelButton_clicked();

    //selection du type de constante utilise
    void on_intRadio_clicked();
    void on_doubleRadio_clicked();
    void on_rationalRadio_clicked();

    //selection de l'utilisation des complexes
    void on_yesComplex_clicked();
    void on_noComplex_clicked();

    //selection de l'unite des degres
    void on_degUnit_clicked();
    void on_radUnit_clicked();

    //Annuler/répéter
    void on_undo_clicked();
    void on_redo_clicked();

    //Créer un onglet à partir de la pile courante
    void createOnglet();

signals:
    void pushStack_signal(const QString&);
    void cleanList_signal();
    void refresh_signal();

private slots:
    void on_addition_2_clicked();

    void on_soustraction_clicked();

    void on_multiplication_clicked();

    void on_division_clicked();

    void on_espace_clicked();

    void on_soustraction_2_clicked();

    void on_multiplication_2_clicked();

    void on_division_2_clicked();

    void on_actionParametre_triggered();

    void on_quote_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_actionNouvel_onglet_triggered();

    void on_actionNouvel_onglet_2_triggered();

    void on_actionAnnuler_triggered();

    void on_actionR_tablir_triggered();

    void on_tabWidget_destroyed();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    reglages * r;
};
#endif // MAINWINDOW_H

