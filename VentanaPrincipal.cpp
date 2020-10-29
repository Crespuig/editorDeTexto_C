#include "VentanaPrincipal.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QToolBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

VentanaPrincipal::VentanaPrincipal(QWidget *parent):QMainWindow(parent){
    
    editorCentral = new QTextEdit(this);
    setCentralWidget(editorCentral);

    creaAcciones();
    creaMenus();      

    setWindowIcon(QIcon("./images/icon.jpg"));
    
    //Ancho y alto de la ventana
    resize(800, 600);
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
    accionAbrir->setStatusTip("Abrir documento");
    connect(accionAbrir, SIGNAL(triggered()), 
            this, SLOT(slotAbrir()));

    accionGuardarComo = new QAction("Guardar como", this);
    accionGuardarComo->setIcon(QIcon("./images/guardarComo.png"));
    accionGuardarComo->setShortcut(QKeySequence(tr("Ctrl+d")));
    accionGuardarComo->setStatusTip("Guardar como");
    connect(accionGuardarComo, SIGNAL(triggered()), 
            this, SLOT(slotGuardarComo()));

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

void VentanaPrincipal::abrirArchivo(QString ruta){
        
        QFile archivo(ruta);
        if(!archivo.open(QIODevice::ReadOnly)){
                QMessageBox::warning(this, "Editos error", 
                                        QString("No he podido abrir el archivo\n"), 
                                        QMessageBox::Yes);
        }
        
        editorCentral->document()->clear();
        QTextStream stream(&archivo);

        while (!stream.atEnd()){
                editorCentral->append(stream.readLine());
        }
        


}

void VentanaPrincipal::guardarComo(QString ruta){
        QFile archivo(ruta);
        if(!archivo.open(QIODevice::WriteOnly)){
                QMessageBox::warning(this, "Editor error", 
                                        QString("No he podido guardar el archivo\n"), 
                                        QMessageBox::Yes);
        }
        
        QTextStream stream(&archivo);

        stream << editorCentral->document()->toPlainText();
        archivo.close();
        
}

void VentanaPrincipal::slotNuevo(){
        QMessageBox::StandardButton botonPulsado;

        botonPulsado = QMessageBox::warning(this, 
                                        "Editor", 
                                        "Vas a borrar",
                                        QMessageBox::Yes | QMessageBox::No);

        if (botonPulsado == QMessageBox::Yes){
                editorCentral->clear();
        }
        
}

void VentanaPrincipal::slotAbrir(){
        QString ruta = QFileDialog::getOpenFileName(this, 
                                                QString("Editor. Abrir"), 
                                                tr("Textos (*.doc *.txt *.sh)"));

        QMessageBox::information(this, "Editor", 
                                QString("Vas a abrir:\n") + ruta + 
                                QString("\n¿Lo tienes claro?"), QMessageBox::Yes);

        if(!ruta.isEmpty()){
                abrirArchivo(ruta);
        }
}

void VentanaPrincipal::slotGuardarComo(){
        QString ruta = QFileDialog::getSaveFileName(this, 
                                                QString("Editor. Abrir"), 
                                                tr("archivo"));

        QMessageBox::information(this, "Editor", 
                                QString("Vas a guardar:\n") + ruta + 
                                QString("\n¿Lo tienes claro?"), QMessageBox::Yes);

        if(!ruta.isEmpty()){
                guardarComo(ruta);
        }
}