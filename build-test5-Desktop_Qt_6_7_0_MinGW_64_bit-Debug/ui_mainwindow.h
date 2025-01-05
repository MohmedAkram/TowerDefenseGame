/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *TitleLabel;
    QPushButton *Startbutton;
    QPushButton *Exitbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(606, 455);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        TitleLabel = new QLabel(centralwidget);
        TitleLabel->setObjectName("TitleLabel");
        TitleLabel->setGeometry(QRect(210, 120, 191, 20));
        Startbutton = new QPushButton(centralwidget);
        Startbutton->setObjectName("Startbutton");
        Startbutton->setGeometry(QRect(260, 180, 83, 29));
        Exitbutton = new QPushButton(centralwidget);
        Exitbutton->setObjectName("Exitbutton");
        Exitbutton->setGeometry(QRect(260, 240, 83, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 606, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TitleLabel->setText(QCoreApplication::translate("MainWindow", "Welcome to a tower defense game", nullptr));
        Startbutton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        Exitbutton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
