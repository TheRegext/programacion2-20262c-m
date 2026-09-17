#pragma once
#include "MovimientosArchivo.h"

class MovimientosManager
{
    public:
        MovimientosManager();

        void registrarMovimiento();
        void listarMovmientos();

    protected:

    private:
        MovimientosArchivo _movimientoArchivo;
};
