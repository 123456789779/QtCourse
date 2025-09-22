/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutwindow
{
public:
    QLabel *label;

    void setupUi(QWidget *aboutwindow)
    {
        if (aboutwindow->objectName().isEmpty())
            aboutwindow->setObjectName(QString::fromUtf8("aboutwindow"));
        aboutwindow->resize(615, 410);
        label = new QLabel(aboutwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 120, 291, 131));

        retranslateUi(aboutwindow);

        QMetaObject::connectSlotsByName(aboutwindow);
    } // setupUi

    void retranslateUi(QWidget *aboutwindow)
    {
        aboutwindow->setWindowTitle(QApplication::translate("aboutwindow", "Form", nullptr));
        label->setText(QApplication::translate("aboutwindow", "\345\247\223\345\220\215\357\274\232\345\224\220\344\274\237\344\270\232\n"
"\345\255\246\345\217\267\357\274\2322023414290128", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutwindow: public Ui_aboutwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
