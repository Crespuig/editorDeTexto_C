#include "VentanaPrincipal.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QToolBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QVariant>
#include <QCloseEvent>
#include <QPalette>
#include <QColor>
#include <QHideEvent>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) : QMainWindow(parent)
{

        editorCentral = new QTextEdit(this);
        setCentralWidget(editorCentral);
        rutaArchivo.clear();

        creaAcciones();
        creaMenus();

        setWindowIcon(QIcon("./images/icon.jpg"));

        //Inicializacion de dialogos
        dialogoBuscar = NULL;
        dialogoDeshacer = NULL;
        dialogoListaColores = NULL;

        //Ancho y alto de la ventana
        resize(800, 600);

        //cambiar color
        //QColor = QDialogoElegirColor::execute();

        /*QColor color = QColor(150, 246, 150);

        QPalette palette = editorCentral->palette();
        palette.setColor(QPalette::Base, color);
        palette.setColor(QPalette::Text, Qt::magenta);
        editorCentral->setPalette(palette);*/
}

/******************************************** CREAR ACCIONES ***************************************************/

void VentanaPrincipal::creaAcciones()
{
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
                this, SLOT(slotGuardar()));

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

        for (int i = 0; i < MAX_FICHEROS_RECIENTES ; i++){
                accionesFicherosRecientes[i] = new QAction("", this);
                accionesFicherosRecientes[i]->setVisible(false);
                connect(accionesFicherosRecientes[i], SIGNAL(triggered()),
                        this, SLOT(slotFicherosRecientes()));
        }

        accionBuscar = new QAction("Buscar", this);
        accionBuscar->setIcon(QIcon("./images/buscar.jpg"));
        accionBuscar->setShortcut(QKeySequence(tr("Ctrl+d")));
        accionBuscar->setStatusTip("Buscar en documento");
        accionBuscar->setToolTip("Buscar en documento");
        connect(accionBuscar, SIGNAL(triggered()),
                this, SLOT(slotDialogoBuscar()));

        accionDeshacer = new QAction("Deshacer", this);
        accionDeshacer->setIcon(QIcon("./images/deshacer.jpeg"));
        accionDeshacer->setShortcut(QKeySequence(tr("Ctrl+d")));
        accionDeshacer->setStatusTip("Deshacer");
        accionDeshacer->setToolTip("Deshacer");
        connect(accionDeshacer, SIGNAL(triggered()),
                this, SLOT(slotDialogoDeshacer()));

        accionElegirColor = new QAction("Elegir Color", this);
        accionElegirColor->setIcon(QIcon("./images/color.png"));
        accionElegirColor->setShortcut(QKeySequence(tr("Ctrl+d")));
        accionElegirColor->setStatusTip("Elegir Color");
        accionElegirColor->setToolTip("Elegir Color");
        connect(accionElegirColor, SIGNAL(triggered()),
                this, SLOT(slotDialogoElegirColor()));

        accionListaColores = new QAction("Lista colores", this);
        accionListaColores->setIcon(QIcon("./images/color.png"));
        accionListaColores->setShortcut(QKeySequence(tr("Ctrl+d")));
        accionListaColores->setStatusTip("Lista colores");
        accionListaColores->setToolTip("Lista colores");
        connect(accionListaColores, SIGNAL(triggered()),
                this, SLOT(slotDialogoListaColores()));
        
}

/************************************************************************************************************/

/******************************************** CREAR MENUS ***************************************************/

void VentanaPrincipal::creaMenus()
{
        QMenuBar *barra = menuBar();
        QMenu *fileMenu = barra->addMenu(QString("File"));

        fileMenu->addAction(accionSalir);
        fileMenu->addAction(accionNuevo);
        fileMenu->addAction(accionGuardar);
        fileMenu->addAction(accionAbrir);
        fileMenu->addAction(accionGuardarComo);
        fileMenu->addSeparator();

        for (int i = 0; i < MAX_FICHEROS_RECIENTES; i++){
                fileMenu->addAction(accionesFicherosRecientes[i]);
        }

        //Menu editar
        menuEditar = barra->addMenu(QString("Editar"));
        menuEditar->addAction(accionBuscar);
        menuEditar->addAction(accionDeshacer);

        //Menu configuracion
        menuConfiguracion = barra->addMenu(QString("Configuración"));
        menuConfiguracion->addAction(accionElegirColor);
        menuConfiguracion->addAction(accionListaColores);

        //Menu contextual
        editorCentral->addAction(accionSalir);
        editorCentral->addAction(accionNuevo);
        editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);

        //Barra de herramientas
        QToolBar *barraArchivo = addToolBar("Archivo");
        QToolBar *barraSalir = addToolBar("Salir");

        barraArchivo->addAction(accionNuevo);
        barraArchivo->addAction(accionGuardar);

        barraSalir->addAction(accionSalir);

        //Barra de estado
        textoEstado = new QLabel("Aplicación lista para usted");
        statusBar()->addWidget(textoEstado);
}

/********************************************************************************************************/

/******************************************** METODOS ***************************************************/

void VentanaPrincipal::abrirArchivo(QString ruta)
{

        QFile archivo(ruta);
        if (!archivo.open(QIODevice::ReadOnly))
        {
                QMessageBox::warning(this, "Editos error",
                                     QString("No he podido abrir el archivo\n"),
                                     QMessageBox::Yes);
        }

        editorCentral->document()->clear();
        QTextStream stream(&archivo);

        while (!stream.atEnd())
        {
                editorCentral->append(stream.readLine());

        }
        establecerFicheroActual(ruta);

}

void VentanaPrincipal::guardarComo(QString ruta)
{
        QFile archivo(ruta);
        if (!archivo.open(QIODevice::WriteOnly))
        {
                QMessageBox::warning(this, "Editor error",
                                     QString("No se ha podido guardar el archivo\n"),
                                     QMessageBox::Yes);
        }

        QTextStream stream(&archivo);

        stream << editorCentral->document()->toPlainText();
        establecerFicheroActual(ruta);
        archivo.close();
}

void VentanaPrincipal::establecerFicheroActual(const QString & nuevaRuta){

        nomFichRec.removeAll(nuevaRuta);
        nomFichRec.prepend(nuevaRuta);

        rutaArchivo = nuevaRuta;

        //QString nombreCorto = QFileInfo(nuevaRuta).fileName();
        for (int i = 0; i < MAX_FICHEROS_RECIENTES; i++){
                accionesFicherosRecientes[i]->setVisible(false);
        }

        for (int i = 0; i < nomFichRec.length() && i < MAX_FICHEROS_RECIENTES; i++){
                QString rutaMirada = nomFichRec[i];
                QString nombreCorto = QFileInfo(rutaMirada).fileName();
                accionesFicherosRecientes[i]->setText(nombreCorto);
                accionesFicherosRecientes[i]->setVisible(true);

                QVariant dato(rutaMirada);
                accionesFicherosRecientes[i]->setData(dato);
        }
        
        foreach(QString nombre, nomFichRec){
                qDebug() << "Nombre archivo: " << nombre;
        }
}

/***************************************************************************************************/

/******************************************** EVENTOS **********************************************/

void VentanaPrincipal::closeEvent(QCloseEvent *event){
        //qDebug()<<"hello"<<endl;
        QMessageBox::StandardButton botonSalir;

        botonSalir = QMessageBox::warning(this,
                                            "Salir",
                                            "¿Quieres guardar?",
                                            QMessageBox::Yes | QMessageBox::No);
        if (botonSalir==QMessageBox::Yes){
                slotGuardarComo();
        }
}


        


/***************************************************************************************************/



/******************************************** SLOTS ************************************************/
void VentanaPrincipal::slotNuevo()
{
        rutaArchivo.clear();

        QMessageBox::StandardButton botonPulsado;

        botonPulsado = QMessageBox::warning(this,
                                            "Editor",
                                            "Vas a borrar",
                                            QMessageBox::Yes | QMessageBox::No);

        if (botonPulsado == QMessageBox::Yes)
        {
                editorCentral->clear();
        }
}

void VentanaPrincipal::slotAbrir()
{
        QString ruta = QFileDialog::getOpenFileName(this,
                                                    QString("Editor. Abrir"),
                                                    tr("Textos (*.doc *.txt *.sh)"));

        QMessageBox::information(this, "Editor",
                                 QString("Vas a abrir:\n") + ruta +
                                     QString("\n¿Lo tienes claro?"),
                                 QMessageBox::Yes);

        if (!ruta.isEmpty())
        {
                abrirArchivo(ruta);
        }
}

void VentanaPrincipal::slotGuardarComo()
{
        QString ruta = QFileDialog::getSaveFileName(this,
                                                    QString("Editor. Guardar"),
                                                    tr("archivo.txt"));

        QMessageBox::information(this, "Editor",
                                 QString("Vas a guardar:\n") + ruta +
                                     QString("\n¿Lo tienes claro?"),
                                 QMessageBox::Yes);

        if (!ruta.isEmpty())
        {
                guardarComo(ruta);
        }
}

void VentanaPrincipal::slotGuardar()
{
        if (rutaArchivo.isEmpty())
        {
                rutaArchivo = QFileDialog::getSaveFileName(this,
                                                           QString("Editor. Guardar"),
                                                           tr("archivo.txt"));

                QMessageBox::information(this, "Editor",
                                         QString("Vas a guardar:\n") + rutaArchivo +
                                             QString("\n¿Lo tienes claro?"),
                                         QMessageBox::Yes);

                guardarComo(rutaArchivo);
        }
        else
        {
                guardarComo(rutaArchivo);
        }
}

void VentanaPrincipal::slotFicherosRecientes(){
        QObject * culpable = sender();
        QAction * accionCulpable = qobject_cast<QAction*>(culpable);
        qDebug() << "La entrada de menu que has pinchado es " << accionCulpable->text();

        QVariant dato = accionCulpable->data();
        QString rutaCompleta = dato.toString();
        abrirArchivo(rutaCompleta);
}

void VentanaPrincipal::slotDialogoBuscar(){
        //DIALOGO MODAL
        /*FindDialog dialogoOtro(this);
        dialogoOtro.exec();*/

        //DIALOGO NO MODAL
        if (dialogoBuscar == NULL){
                dialogoBuscar = new FindDialog(this);

                connect(dialogoBuscar, 
                SIGNAL(findNext(const QString &, Qt::CaseSensitivity)),
                this,
                SLOT(slotBuscarSiguiente(const QString &, Qt::CaseSensitivity)));
        }
        dialogoBuscar->show();
}

void VentanaPrincipal::slotBuscarSiguiente(const QString &str, Qt::CaseSensitivity cs){
        qDebug()<< "La cadena que me han pasado es " << str;
        
        if(!editorCentral->find(str)){
                editorCentral->moveCursor(QTextCursor::Start);
        }
}

void VentanaPrincipal::slotDialogoDeshacer(){
        if (dialogoBuscar == NULL){
                dialogoDeshacer = new DialogoDeshacer(editorCentral, this);     
        }
        dialogoDeshacer->show();
}

void VentanaPrincipal::slotDialogoElegirColor(){
        if (dialogoBuscar == NULL){
                dialogoElegirColor = new DialogoElegirColor(editorCentral, this);
        }
        dialogoElegirColor->show();
}

void VentanaPrincipal::slotDialogoListaColores(){
        if (dialogoBuscar == NULL){
                dialogoListaColores = new DialogoListaColores(editorCentral, this);
        }
        dialogoListaColores->show();
}


/********************************************************************************************************/