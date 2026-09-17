#include <iostream>
#include "MovimientosMenu.h"


using namespace std;

MovimientosMenu::MovimientosMenu()
: Menu(2)
{
    setItem(1, "Registrar Movimiento");
    setItem(2, "Listado de Movimientos");
}

void MovimientosMenu::run(){
    int opcion;

    do {
        dibujarMenu();
        opcion = obtenerRespuesta();

        switch(opcion){
            case 1: {
                _movimientoManager.registrarMovimiento();
                break;
            }
            case 2: {
                _movimientoManager.listarMovmientos();
                break;
            }
        }
    } while(opcion != 0);
}
