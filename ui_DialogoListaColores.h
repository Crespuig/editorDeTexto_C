/********************************************************************************
** Form generated from reading UI file 'DialogoListaColores.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOLISTACOLORES_H
#define UI_DIALOGOLISTACOLORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DialogoListaColores
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *ComboBoxListaColores;

    void setupUi(QDialog *DialogoListaColores)
    {
        if (DialogoListaColores->objectName().isEmpty())
            DialogoListaColores->setObjectName(QString::fromUtf8("DialogoListaColores"));
        DialogoListaColores->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoListaColores);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ComboBoxListaColores = new QComboBox(DialogoListaColores);
        ComboBoxListaColores->setObjectName(QString::fromUtf8("ComboBoxListaColores"));
        ComboBoxListaColores->setGeometry(QRect(10, 90, 371, 25));

        retranslateUi(DialogoListaColores);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoListaColores, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoListaColores, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoListaColores);
    } // setupUi

    void retranslateUi(QDialog *DialogoListaColores)
    {
        DialogoListaColores->setWindowTitle(QApplication::translate("DialogoListaColores", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoListaColores: public Ui_DialogoListaColores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOLISTACOLORES_H
