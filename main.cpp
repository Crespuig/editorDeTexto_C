#include <QApplication>
#include "VentanaPrincipal.h"

 int main(int argc, char *argv[])
 {
    QApplication app(argc, argv);
    
    VentanaPrincipal * ventana = new VentanaPrincipal();
    ventana->show();

    return app.exec();
 }
 