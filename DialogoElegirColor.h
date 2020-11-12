#ifndef _DIALOGOELEGIRCOLOR_H
#define _DIALOGOELEGIRCOLOR_H

#include "ui_DialogoElegirColor.h"
#include <QColorDialog>
#include <QTextEdit>
#include <QColor>





class DialogoElegirColor : public QDialog, public Ui::DialogoElegirColor{
    Q_OBJECT

    public:
        DialogoElegirColor(QTextEdit *, QWidget * parent = 0);

        QTextEdit * punteroATextEdit;
        QColor color;
        

    private slots:
        void slotBotonElegirColor();
        void slotBotonProbarColor();

};

#endif