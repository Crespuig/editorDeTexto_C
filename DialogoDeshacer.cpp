#include "DialogoDeshacer.h"
#include <QDebug>
#include <QTextEdit>


DialogoDeshacer::DialogoDeshacer(QTextEdit * punteroPasado, QWidget * parent) : QDialog(parent){
    setupUi(this);

    punteroATextEdit = punteroPasado;

    connect(botonDeshacer, SIGNAL(clicked()),
          this, SLOT(slotBotonDeshacer()));

    connect(botonRehacer, SIGNAL(clicked()),
          this, SLOT(slotBotonRehacer()));

    
}
void DialogoDeshacer::slotBotonDeshacer(){
        //qDebug()<< "Deshacer"<<endl;
        punteroATextEdit->undo();
        punteroATextEdit->undo();
    }

void DialogoDeshacer::slotBotonRehacer(){
        //qDebug()<< "Rehacer"<<endl;
        punteroATextEdit->redo();
        punteroATextEdit->redo();
    }