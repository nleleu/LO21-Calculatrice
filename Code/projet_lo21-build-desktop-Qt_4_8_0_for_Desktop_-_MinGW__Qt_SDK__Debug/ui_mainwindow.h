/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 30. Apr 12:08:20 2012
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
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 231, 20));
        lineEdit->setReadOnly(false);
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
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
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
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
