/********************************************************************************
** Form generated from reading UI file 'newwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWINDOW_H
#define UI_NEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newwindow
{
public:

    void setupUi(QWidget *newwindow)
    {
        if (newwindow->objectName().isEmpty())
            newwindow->setObjectName(QString::fromUtf8("newwindow"));
        newwindow->resize(530, 273);

        retranslateUi(newwindow);

        QMetaObject::connectSlotsByName(newwindow);
    } // setupUi

    void retranslateUi(QWidget *newwindow)
    {
        newwindow->setWindowTitle(QApplication::translate("newwindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newwindow: public Ui_newwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWINDOW_H
