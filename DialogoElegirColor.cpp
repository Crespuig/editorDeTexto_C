#include "DialogoElegirColor.h"
#include <QDebug>
#include <QColorDialog>
#include <QColor>
#include <QTextEdit>
#include <QPalette>



DialogoElegirColor::DialogoElegirColor(QTextEdit * punteroPasado, QWidget * parent) : QDialog(parent){
    setupUi(this);

    punteroATextEdit = punteroPasado;

    connect(elegirColor, SIGNAL(clicked()),
          this, SLOT(slotBotonElegirColor()));

    connect(probar, SIGNAL(clicked()),
          this, SLOT(slotBotonProbarColor()));

    
}
void DialogoElegirColor::slotBotonElegirColor(){
        QColorDialog colorDialog;

        color = colorDialog.getColor();
    }

void DialogoElegirColor::slotBotonProbarColor(){
        QPalette palette = punteroATextEdit->palette();
        palette.setColor(QPalette::Base, color);
        punteroATextEdit->setPalette(palette);
}

