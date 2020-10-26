#include "VentanaPrincipal.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>

VentanaPrincipal::VentanaPrincipal(QWidget *parent):QMainWindow(parent){
    
    editorCentral = new QTextEdit(this);
    setCentralWidget(editorCentral);

    QMenuBar *barra = new QMenuBar();
    QMenu * fileMenu = barra->addMenu(QString("File"));

    accionSalir = new QAction("Salir", this);
    fileMenu->addAction(accionSalir);

    setWindowIcon(QIcon("./images/icon.png"));

    

}