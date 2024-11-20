/********************************************************************************
** Form generated from reading UI file 'my_weather.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_WEATHER_H
#define UI_MY_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_My_Weather
{
public:

    void setupUi(QWidget *My_Weather)
    {
        if (My_Weather->objectName().isEmpty())
            My_Weather->setObjectName(QString::fromUtf8("My_Weather"));
        My_Weather->resize(400, 300);

        retranslateUi(My_Weather);

        QMetaObject::connectSlotsByName(My_Weather);
    } // setupUi

    void retranslateUi(QWidget *My_Weather)
    {
        My_Weather->setWindowTitle(QCoreApplication::translate("My_Weather", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class My_Weather: public Ui_My_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_WEATHER_H
