#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "pile.h"
#include "type.h"
#include <QString>
#include "collection_pile.h"
#include <QFileDialog>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Pile &pile, QWidget *parent);
    ~MainWindow();

signals:
    void pushStack_signal(const QString&);
    void cleanList_signal();
    void refresh_signal();

private slots:

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


    //Annuler/répéter
    void on_undo_clicked();
    void on_redo_clicked();

    //Ouvrir interface charger/sauvegarder
    void on_charger_triggered();
    void on_sauvegarder_triggered();

    //Créer un onglet à partir de la pile courante
    void createOnglet();

    void on_soustraction_clicked();
    void on_multiplication_clicked();
    void on_division_clicked();
    void on_espace_clicked();
    void on_actionParametre_triggered();
    void on_quote_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_actionNouvel_onglet_triggered();
    void on_actionNouvel_onglet_2_triggered();
    void on_actionAnnuler_triggered();
    void on_actionR_tablir_triggered();
    void on_tabWidget_destroyed();
    void on_tabWidget_tabCloseRequested(int index);

    void on_pow_clicked();
    void on_mod_clicked();
    void on_sign_clicked();

    void on_sin_clicked();
    void on_cos_clicked();
    void on_tan_clicked();
    void on_sinh_clicked();
    void on_cosh_clicked();
    void on_tanh_clicked();

    void on_ln_clicked();
    void on_log_clicked();
    void on_inv_clicked();
    void on_sqrt_clicked();
    void on_sqr_clicked();
    void on_cube_clicked();
    void on_fact_clicked();
    void on_eval_clicked();

    void on_actionR_glage_triggered();


    void on_nbelt_textChanged(const QString &arg1);

    void on_nbelt_textEdited(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_NbAffiche_valueChanged(int arg1);

    void on_degUnit_clicked();

    void on_radUnit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

