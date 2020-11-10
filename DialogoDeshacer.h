#ifndef _DIALOGODESHACER_H
#define _DIALOGODESHACER_H

#include "ui_DialogoDeshacer.h"
#include <QTextEdit>


class DialogoDeshacer : public QDialog, public Ui::DialogoDeshacer{
    Q_OBJECT

    public:
        DialogoDeshacer(QTextEdit *, QWidget * parent = 0);

        QTextEdit * punteroATextEdit;

    private slots:
        void slotBotonDeshacer();
        void slotBotonRehacer();

};

#endif