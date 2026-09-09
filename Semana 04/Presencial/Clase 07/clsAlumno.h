#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

#include "clsFecha.h"
#include "clsDomicilio.h"
#include "clsPersona.h"

class Alumno : public Persona{
    private:
        int legajo;
    public:
        Alumno(int l=1, const char *nA="S/N", int d=0, Fecha fN=Fecha(3,3,1989), Domicilio dom=Domicilio());
        void Cargar();
        void Mostrar();
        void setLegajo(int l);
        int getLegajo();
        bool operator==(int l);
        bool operator==(Fecha fN);
        bool operator<(int l);
        ~Alumno();
};

#endif // CLSALUMNO_H_INCLUDED
