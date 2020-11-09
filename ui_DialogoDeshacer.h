/********************************************************************************
** Form generated from reading UI file 'DialogoDeshacer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGODESHACER_H
#define UI_DIALOGODESHACER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogoDeshacer
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *botonDeshacer;
    QPushButton *botonRehacer;

    void setupUi(QDialog *DialogoDeshacer)
    {
        if (DialogoDeshacer->objectName().isEmpty())
            DialogoDeshacer->setObjectName(QString::fromUtf8("DialogoDeshacer"));
        DialogoDeshacer->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoDeshacer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        botonDeshacer = new QPushButton(DialogoDeshacer);
        botonDeshacer->setObjectName(QString::fromUtf8("botonDeshacer"));
        botonDeshacer->setGeometry(QRect(30, 50, 89, 25));
        botonRehacer = new QPushButton(DialogoDeshacer);
        botonRehacer->setObjectName(QString::fromUtf8("botonRehacer"));
        botonRehacer->setGeometry(QRect(190, 50, 89, 25));

        retranslateUi(DialogoDeshacer);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoDeshacer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoDeshacer, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoDeshacer);
    } // setupUi

    void retranslateUi(QDialog *DialogoDeshacer)
    {
        DialogoDeshacer->setWindowTitle(QApplication::translate("DialogoDeshacer", "Dialog", nullptr));
        botonDeshacer->setText(QApplication::translate("DialogoDeshacer", "Deshacer", nullptr));
        botonRehacer->setText(QApplication::translate("DialogoDeshacer", "Rehacer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogoDeshacer: public Ui_DialogoDeshacer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGODESHACER_H
