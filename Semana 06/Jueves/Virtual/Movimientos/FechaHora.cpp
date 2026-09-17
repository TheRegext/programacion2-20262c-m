#include "FechaHora.h"

FechaHora::FechaHora()
{
    _hora = 0;
    _minutos = 0;
}

FechaHora::FechaHora(int d, int m, int a, int h, int min)
: Fecha(d, m, a){
    setHora(h);
    setMinutos(min);
}

int FechaHora::getHora()
{
    return _hora;
}

int FechaHora::getMinutos()
{
    return _minutos;
}

void FechaHora::setHora(int hora)
{
    _hora = hora;
}

void FechaHora::setMinutos(int minutos)
{
    _minutos = minutos;
}
