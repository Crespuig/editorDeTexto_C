#include "DialogoDeshacer.h"
#include <QDebug>


DialogoDeshacer::DialogoDeshacer(QWidget * parent) : QDialog(parent){
    setupUi(this);

    connect(botonDeshacer, SIGNAL(clicked()),
          this, SLOT(slotBotonDeshacer()));

    connect(botonRehacer, SIGNAL(clicked()),
          this, SLOT(slotBotonRehacer()));

    
}
void DialogoDeshacer::slotBotonDeshacer(){
        qDebug()<< "Deshacer"<<endl;
    }

void DialogoDeshacer::slotBotonRehacer(){
        qDebug()<< "Rehacer"<<endl;
    }