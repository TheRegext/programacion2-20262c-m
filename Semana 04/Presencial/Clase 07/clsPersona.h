#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

#include "clsFecha.h"
#include "clsDomicilio.h"

class Persona{
    protected:
        char nombreApellido[50];
        int dni;
        Fecha fechaNacimiento;
        Domicilio domicilio;
    public:
        void Cargar();
        void Mostrar();
        void setNombreApellido(const char *nA);
        void setDni(int d);
        void setFechaNacimiento(Fecha fN);
        void setDomicilio(Domicilio d);
        const char *getNombreApellido();
        int getDni();
        Fecha getFechaNacimiento();
        Domicilio getDomicilio();
};

#endif // CLSPERSONA_H_INCLUDED
