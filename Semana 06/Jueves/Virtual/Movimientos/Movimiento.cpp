#include <cstring>
#include "Movimiento.h"

Movimiento::Movimiento()
{
    _id = 0;
    _monto = 0.0f;
    _descripcion[0] = '\0';
    _tipo = TipoMovimiento::Ingreso;
}

Movimiento::Movimiento(int id, float monto, FechaHora fecha, std::string descripcion, TipoMovimiento tipo)
{
    setId(id);
    setMonto(monto);
    setFecha(fecha);
    setDescripcion(descripcion);
    setTipo(tipo);
}

int Movimiento::getId()
{
    return _id;
}

float Movimiento::getMonto()
{
    return _monto;
}

FechaHora Movimiento::getFecha()
{
    return _fecha;
}

std::string Movimiento::getDescripcion()
{
    return _descripcion;
}

TipoMovimiento Movimiento::getTipo()
{
    return _tipo;
}

void Movimiento::setId(int id)
{
    _id = id;
}

void Movimiento::setMonto(float monto)
{
    _monto = monto;
}

void Movimiento::setFecha(FechaHora fecha)
{
    _fecha = fecha;
}

void Movimiento::setDescripcion(std::string descripcion)
{
 if(descripcion.size() <= 99){
    strcpy(_descripcion, descripcion.c_str());
 }
 else{
    strcpy(_descripcion, descripcion.substr(0, 99).c_str());
 }
}

void Movimiento::setTipo(TipoMovimiento tipo)
{
    _tipo = tipo;
}
