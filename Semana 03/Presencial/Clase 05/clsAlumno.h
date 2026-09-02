#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

#include "clsFecha.h"
#include "clsDomicilio.h"

class Alumno{
    private:
        int legajo;
        char nombreApellido[50];
        int dni;
        Fecha fechaNacimiento;
        Domicilio domicilio;
    public:
        Alumno(int l=1, const char *nA="S/N", int d=0, Fecha fN=Fecha(3,3,1989), Domicilio dom=Domicilio());
        void Cargar();
        void Mostrar();
        void setLegajo(int l);
        void setNombreApellido(const char *nA);
        void setFechaNacimiento(Fecha fN);
        int getLegajo();
        const char *getNombreApellido();
        Fecha getFechaNacimiento();
        ~Alumno();
};

#endif // CLSALUMNO_H_INCLUDED
