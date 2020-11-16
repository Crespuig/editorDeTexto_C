#ifndef _DIALOGOLISTACOLORES_H
#define _DIALOGOLISTACOLORES_H

#include "ui_DialogoListaColores.h"
#include <QColorDialog>
#include <QTextEdit>
#include <QColor>
#include <QPalette>

class DialogoListaColores : public QDialog, public Ui::DialogoListaColores{
    Q_OBJECT

    public:
        DialogoListaColores(QTextEdit *, QWidget * parent = 0);
        QTextEdit * punteroATextEdit;
        

    private slots:
        void slotComboBoxListaColores();

};

#endif