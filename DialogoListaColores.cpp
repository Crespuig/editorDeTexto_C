#include "DialogoListaColores.h"
#include <QDebug>
#include <QColorDialog>
#include <QColor>
#include <QTextEdit>
#include <QPalette>

DialogoListaColores::DialogoListaColores(QTextEdit * punteroPasado, QWidget * parent) : QDialog(parent){
    setupUi(this);

    connect(ComboBoxListaColores, SIGNAL(clicked()),
          this, SLOT(slotComboBoxListaColores()));

    
}

void DialogoListaColores::slotComboBoxListaColores(){
       
    }


