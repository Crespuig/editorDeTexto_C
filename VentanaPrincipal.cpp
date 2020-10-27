#include "VentanaPrincipal.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QToolBar>

VentanaPrincipal::VentanaPrincipal(QWidget *parent):QMainWindow(parent){
    
    editorCentral = new QTextEdit(this);
    setCentralWidget(editorCentral);

    creaAcciones();
    creaMenus();      

    setWindowIcon(QIcon("./images/icon.jpg"));
}

void VentanaPrincipal::creaAcciones(){
    accionSalir = new QAction("Salir", this);
    accionSalir->setIcon(QIcon("./images/salir.jpg"));
    accionSalir->setShortcut(QKeySequence(tr("Ctrl+q")));
    accionSalir->setStatusTip("Salir del editor");
    connect(accionSalir, SIGNAL(triggered()), 
            this, SLOT(close()));

    accionNuevo = new QAction("Nuevo", this);
    accionNuevo->setIcon(QIcon("./images/nuevo.png"));
    accionNuevo->setShortcut(QKeySequence(tr("Ctrl+n")));
    accionNuevo->setStatusTip("Nuevo");
    connect(accionNuevo, SIGNAL(triggered()), 
            this, SLOT(slotNuevo()));

    accionGuardar = new QAction("Guardar", this);
    accionGuardar->setIcon(QIcon("./images/guardar.png"));
    accionGuardar->setShortcut(QKeySequence(tr("Ctrl+s")));
    accionGuardar->setStatusTip("Guardar");
    connect(accionGuardar, SIGNAL(triggered()), 
            this, SLOT(close()));

    accionAbrir = new QAction("Abrir", this);
    accionAbrir->setIcon(QIcon("./images/abrir.jpg"));
    accionAbrir->setShortcut(QKeySequence(tr("Ctrl+a")));
    accionAbrir->setStatusTip("Abrir");
    connect(accionAbrir, SIGNAL(triggered()), 
            this, SLOT(close()));

    accionGuardarComo = new QAction("Guardar como", this);
    accionGuardarComo->setIcon(QIcon("./images/guardarComo.png"));
    accionGuardarComo->setShortcut(QKeySequence(tr("Ctrl+d")));
    accionGuardarComo->setStatusTip("Guardar como");
    connect(accionGuardarComo, SIGNAL(triggered()), 
            this, SLOT(close()));

}

void VentanaPrincipal::creaMenus(){
    QMenuBar *barra = menuBar();
    QMenu * fileMenu = barra->addMenu(QString("File"));

    fileMenu->addAction(accionSalir);
    fileMenu->addAction(accionNuevo);
    fileMenu->addAction(accionGuardar);
    fileMenu->addAction(accionAbrir);
    fileMenu->addAction(accionGuardarComo);

    //Menu contextual
    editorCentral->addAction(accionSalir);
    editorCentral->addAction(accionNuevo);
    editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);

    //Barra de herramientas
    QToolBar * barraArchivo = addToolBar("Archivo");
    QToolBar * barraSalir = addToolBar("Salir");

    barraArchivo->addAction(accionNuevo);
    barraArchivo->addAction(accionGuardar);

    barraSalir->addAction(accionSalir);

    //Barra de estado
    textoEstado = new QLabel("Aplicación lista para usted");
    statusBar()->addWidget(textoEstado);
}

void VentanaPrincipal::slotNuevo(){
    QMessageBox::warning(this, "Editor", "Vas a borrar",
                        QMessageBox::Yes | QMessageBox::No);
    editorCentral->clear();
}