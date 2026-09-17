#pragma once
#include <string>
#include "Movimiento.h"

class MovimientosArchivo
{
    public:
        MovimientosArchivo(std::string fileName = "movimientos.dat");
        void agrear(Movimiento mov);
        void leerTodos(Movimiento mov[], int cant);
        int getCantidadRegistros();

    protected:

    private:
        std::string _fileName;
};

