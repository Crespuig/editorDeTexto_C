#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>

class VentanaPrincipal : public QMainWindow{
Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0);
    
private:
    QTextEdit * editorCentral;

    //QActions
    QAction * accionSalir; 
    QAction * accionNuevo; 
    QAction * accionGuardar; 
    QAction * accionAbrir; 
    QAction * accionGuardarComo;

    //Menus
    QMenu *menuArchivo;
    QMenu *menuEditar;

    QLabel *textoEstado;

    void creaAcciones();
    void creaMenus();
    void abrirArchivo(QString);
    void guardarComo(QString);

public slots:
    void slotNuevo();
    void slotAbrir();
    void slotGuardarComo();

};


#endif