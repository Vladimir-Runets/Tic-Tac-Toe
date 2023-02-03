/********************************************************************************
** Form generated from reading UI file 'anotherwindow1.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANOTHERWINDOW1_H
#define UI_ANOTHERWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnotherWindow1
{
public:

    void setupUi(QWidget *AnotherWindow1)
    {
        if (AnotherWindow1->objectName().isEmpty())
            AnotherWindow1->setObjectName(QString::fromUtf8("AnotherWindow1"));
        AnotherWindow1->resize(1019, 566);

        retranslateUi(AnotherWindow1);

        QMetaObject::connectSlotsByName(AnotherWindow1);
    } // setupUi

    void retranslateUi(QWidget *AnotherWindow1)
    {
        AnotherWindow1->setWindowTitle(QCoreApplication::translate("AnotherWindow1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnotherWindow1: public Ui_AnotherWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTHERWINDOW1_H
