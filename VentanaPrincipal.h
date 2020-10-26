#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H
#include <QMainWindow>
#include <QTextEdit>

class VentanaPrincipal : public QMainWindow{
Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = 0);
    
private:
    QTextEdit * editorCentral;
    QAction * accionSalir;
};


#endif