/********************************************************************************
** Form generated from reading UI file 'newgamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAMEWINDOW_H
#define UI_NEWGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newgamewindow
{
public:
    QLabel *label;
    QPushButton *Nextlevelbutton;
    QPushButton *Cancelbutton;

    void setupUi(QDialog *newgamewindow)
    {
        if (newgamewindow->objectName().isEmpty())
            newgamewindow->setObjectName("newgamewindow");
        newgamewindow->resize(400, 300);
        label = new QLabel(newgamewindow);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 60, 141, 41));
        Nextlevelbutton = new QPushButton(newgamewindow);
        Nextlevelbutton->setObjectName("Nextlevelbutton");
        Nextlevelbutton->setGeometry(QRect(240, 200, 83, 29));
        Cancelbutton = new QPushButton(newgamewindow);
        Cancelbutton->setObjectName("Cancelbutton");
        Cancelbutton->setGeometry(QRect(110, 200, 83, 29));

        retranslateUi(newgamewindow);

        QMetaObject::connectSlotsByName(newgamewindow);
    } // setupUi

    void retranslateUi(QDialog *newgamewindow)
    {
        newgamewindow->setWindowTitle(QCoreApplication::translate("newgamewindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("newgamewindow", "Next level?", nullptr));
        Nextlevelbutton->setText(QCoreApplication::translate("newgamewindow", "Next", nullptr));
        Cancelbutton->setText(QCoreApplication::translate("newgamewindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newgamewindow: public Ui_newgamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAMEWINDOW_H
