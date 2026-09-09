#ifndef CLSDOCENTE_H_INCLUDED
#define CLSDOCENTE_H_INCLUDED

#include "clsDomicilio.h"
#include "clsFecha.h"

class Docente{
    private:
        int legajo;
        Fecha fechaContratacion;
        char email[50];
    public:
        void Cargar();
        void Mostrar();
        void setLegajo(int l);
        void setFechaContratacion(Fecha fC);
        void setEmail(const char *e);
        int getLegajo();
        Fecha getFechaContratacion();
        const char *getEmail();
};


#endif // CLSDOCENTE_H_INCLUDED
