/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 2. May 01:29:22 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton1;
    QPushButton *pushButton4;
    QPushButton *pushButton7;
    QPushButton *pushButton2;
    QPushButton *pushButton8;
    QPushButton *pushButton5;
    QPushButton *pushButton9;
    QPushButton *pushButton3;
    QPushButton *pushButton6;
    QPushButton *pushButton0;
    QPushButton *stackButton;
    QGroupBox *groupBox;
    QPushButton *affichePile;
    QPushButton *swap;
    QPushButton *clear;
    QPushButton *sum;
    QPushButton *dup;
    QPushButton *mean;
    QPushButton *drop;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(753, 301);
        MainWindow->setAcceptDrops(false);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 231, 20));
        lineEdit->setReadOnly(true);
        pushButton1 = new QPushButton(centralWidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(30, 90, 75, 23));
        pushButton4 = new QPushButton(centralWidget);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));
        pushButton4->setGeometry(QRect(30, 120, 75, 23));
        pushButton7 = new QPushButton(centralWidget);
        pushButton7->setObjectName(QString::fromUtf8("pushButton7"));
        pushButton7->setGeometry(QRect(30, 150, 75, 23));
        pushButton2 = new QPushButton(centralWidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
        pushButton2->setGeometry(QRect(110, 90, 75, 23));
        pushButton8 = new QPushButton(centralWidget);
        pushButton8->setObjectName(QString::fromUtf8("pushButton8"));
        pushButton8->setGeometry(QRect(110, 150, 75, 23));
        pushButton5 = new QPushButton(centralWidget);
        pushButton5->setObjectName(QString::fromUtf8("pushButton5"));
        pushButton5->setGeometry(QRect(110, 120, 75, 23));
        pushButton9 = new QPushButton(centralWidget);
        pushButton9->setObjectName(QString::fromUtf8("pushButton9"));
        pushButton9->setGeometry(QRect(190, 150, 75, 23));
        pushButton3 = new QPushButton(centralWidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));
        pushButton3->setGeometry(QRect(190, 90, 75, 23));
        pushButton6 = new QPushButton(centralWidget);
        pushButton6->setObjectName(QString::fromUtf8("pushButton6"));
        pushButton6->setGeometry(QRect(190, 120, 75, 23));
        pushButton0 = new QPushButton(centralWidget);
        pushButton0->setObjectName(QString::fromUtf8("pushButton0"));
        pushButton0->setGeometry(QRect(30, 180, 75, 23));
        stackButton = new QPushButton(centralWidget);
        stackButton->setObjectName(QString::fromUtf8("stackButton"));
        stackButton->setGeometry(QRect(300, 170, 75, 61));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(430, 30, 281, 201));
        affichePile = new QPushButton(groupBox);
        affichePile->setObjectName(QString::fromUtf8("affichePile"));
        affichePile->setGeometry(QRect(10, 20, 75, 61));
        swap = new QPushButton(groupBox);
        swap->setObjectName(QString::fromUtf8("swap"));
        swap->setGeometry(QRect(110, 30, 41, 41));
        clear = new QPushButton(groupBox);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(110, 80, 41, 41));
        sum = new QPushButton(groupBox);
        sum->setObjectName(QString::fromUtf8("sum"));
        sum->setGeometry(QRect(170, 30, 41, 41));
        dup = new QPushButton(groupBox);
        dup->setObjectName(QString::fromUtf8("dup"));
        dup->setGeometry(QRect(170, 80, 41, 41));
        mean = new QPushButton(groupBox);
        mean->setObjectName(QString::fromUtf8("mean"));
        mean->setGeometry(QRect(220, 30, 41, 41));
        drop = new QPushButton(groupBox);
        drop->setObjectName(QString::fromUtf8("drop"));
        drop->setGeometry(QRect(220, 80, 41, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 753, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(menuBar, SIGNAL(triggered(QAction*)), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        pushButton1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        stackButton->setText(QApplication::translate("MainWindow", "Stack", 0, QApplication::UnicodeUTF8));
        stackButton->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Op\303\251rations sur la Pile", 0, QApplication::UnicodeUTF8));
        affichePile->setText(QApplication::translate("MainWindow", "Affiche Pile", 0, QApplication::UnicodeUTF8));
        affichePile->setShortcut(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
        swap->setText(QApplication::translate("MainWindow", "Swap", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        clear->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        sum->setText(QApplication::translate("MainWindow", "Sum", 0, QApplication::UnicodeUTF8));
        dup->setText(QApplication::translate("MainWindow", "Dup", 0, QApplication::UnicodeUTF8));
        mean->setText(QApplication::translate("MainWindow", "Mean", 0, QApplication::UnicodeUTF8));
        drop->setText(QApplication::translate("MainWindow", "Drop", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
