#pragma once
#include <string>
#include "FechaHora.h"

enum class TipoMovimiento{
    Ingreso,
    Egreso
};

class Movimiento
{
    public:
        Movimiento();
        Movimiento(int id, float monto, FechaHora fecha, std::string descripcion, TipoMovimiento tipo);

        int getId();
        float getMonto();
        FechaHora getFecha();
        std::string getDescripcion();
        TipoMovimiento getTipo();

        void setId(int id);
        void setMonto(float monto);
        void setFecha(FechaHora fecha);
        void setDescripcion(std::string descripcion);
        void setTipo(TipoMovimiento tipo);

    protected:

    private:

       int _id;
        float _monto;
        FechaHora _fecha;
        char _descripcion[100];
        TipoMovimiento _tipo;
};
