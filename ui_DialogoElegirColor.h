/********************************************************************************
** Form generated from reading UI file 'DialogoElegirColor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOELEGIRCOLOR_H
#define UI_DIALOGOELEGIRCOLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogoElegirColor
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *elegirColor;
    QPushButton *probar;

    void setupUi(QDialog *DialogoElegirColor)
    {
        if (DialogoElegirColor->objectName().isEmpty())
            DialogoElegirColor->setObjectName(QString::fromUtf8("DialogoElegirColor"));
        DialogoElegirColor->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoElegirColor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-60, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        elegirColor = new QPushButton(DialogoElegirColor);
        elegirColor->setObjectName(QString::fromUtf8("elegirColor"));
        elegirColor->setGeometry(QRect(140, 60, 89, 25));
        probar = new QPushButton(DialogoElegirColor);
        probar->setObjectName(QString::fromUtf8("probar"));
        probar->setGeometry(QRect(140, 140, 89, 25));

        retranslateUi(DialogoElegirColor);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoElegirColor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoElegirColor, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoElegirColor);
    } // setupUi

    void retranslateUi(QDialog *DialogoElegirColor)
    {
        DialogoElegirColor->setWindowTitle(QApplication::translate("DialogoElegirColor", "Dialog", nullptr));
        elegirColor->setText(QApplication::translate("DialogoElegirColor", "Elegir color", nullptr));
        probar->setText(QApplication::translate("DialogoElegirColor", "Probar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoElegirColor: public Ui_DialogoElegirColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOELEGIRCOLOR_H
