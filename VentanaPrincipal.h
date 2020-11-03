#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>

class VentanaPrincipal : public QMainWindow{
Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0);

    static const int MAX_FICHEROS_RECIENTES = 5;
    
private:
    QTextEdit * editorCentral;

    //QActions
    QAction * accionSalir; 
    QAction * accionNuevo; 
    QAction * accionGuardar; 
    QAction * accionAbrir; 
    QAction * accionGuardarComo;

    QAction * accionesFicherosRecientes[MAX_FICHEROS_RECIENTES];

    //Menus
    QMenu *menuArchivo;
    QMenu *menuEditar;
    QLabel *textoEstado;
    
    void creaAcciones();
    void creaMenus();
    void abrirArchivo(QString);
    void guardarComo(QString);
    void establecerFicheroActual(const QString & nuevaRuta);
    
    QString rutaArchivo;
    QStringList nomFichRec; //Nombres de ficheros recientes

    

public slots:
    void slotNuevo();
    void slotAbrir();
    void slotGuardarComo();
    void slotGuardar();
    void slotFicherosRecientes();

};


#endif