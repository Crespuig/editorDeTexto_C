#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include "findDialog.h"
#include "DialogoDeshacer.h"
#include "DialogoElegirColor.h"
#include <QCloseEvent>


class VentanaPrincipal : public QMainWindow{
Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0);

    static const int MAX_FICHEROS_RECIENTES = 5;

    void closeEvent(QCloseEvent *event);
    
private:
    QTextEdit * editorCentral;

    //QActions
    QAction * accionSalir; 
    QAction * accionNuevo; 
    QAction * accionGuardar; 
    QAction * accionAbrir; 
    QAction * accionGuardarComo;
    QAction * accionBuscar;
    QAction * accionDeshacer;
    QAction * accionElegirColor;

    QAction * accionesFicherosRecientes[MAX_FICHEROS_RECIENTES];

    //Menus
    QMenu *menuArchivo;
    QMenu *menuEditar;
    QMenu *menuConfiguracion;
    QLabel *textoEstado;
    
    void creaAcciones();
    void creaMenus();
    void abrirArchivo(QString);
    void guardarComo(QString);
    void establecerFicheroActual(const QString & nuevaRuta);
    
    QString rutaArchivo;
    QStringList nomFichRec; //Nombres de ficheros recientes

    FindDialog * dialogoBuscar;
    DialogoDeshacer * dialogoDeshacer;
    DialogoElegirColor * dialogoElegirColor;

    

public slots:
    void slotNuevo();
    void slotAbrir();
    void slotGuardarComo();
    void slotGuardar();
    void slotFicherosRecientes();
    void slotDialogoBuscar();
    void slotBuscarSiguiente(const QString &str, Qt::CaseSensitivity cs);
    void slotDialogoDeshacer();
    void slotDialogoElegirColor();

};


#endif