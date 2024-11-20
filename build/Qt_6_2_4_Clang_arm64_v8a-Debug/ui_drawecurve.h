/********************************************************************************
** Form generated from reading UI file 'drawecurve.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWECURVE_H
#define UI_DRAWECURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DraweCurve
{
public:

    void setupUi(QWidget *DraweCurve)
    {
        if (DraweCurve->objectName().isEmpty())
            DraweCurve->setObjectName(QString::fromUtf8("DraweCurve"));
        DraweCurve->resize(400, 300);

        retranslateUi(DraweCurve);

        QMetaObject::connectSlotsByName(DraweCurve);
    } // setupUi

    void retranslateUi(QWidget *DraweCurve)
    {
        DraweCurve->setWindowTitle(QCoreApplication::translate("DraweCurve", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DraweCurve: public Ui_DraweCurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWECURVE_H
