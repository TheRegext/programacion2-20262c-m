#ifndef CLSARCHIVOALUMNOS_H_INCLUDED
#define CLSARCHIVOALUMNOS_H_INCLUDED

#include "clsAlumno.h"

class ArchivoAlumnos{
    private:
        char nombre[30];
    public:
        ArchivoAlumnos(const char *n="alumnos.dat");
        Alumno leerRegistro(int pos);
        int contarRegistros();
        bool grabarRegistro(Alumno obj);
        bool modificarRegistro(Alumno obj, int pos);
        int buscarRegistro(int leg);
        void listarRegistros();
};

#endif // CLSARCHIVOALUMNOS_H_INCLUDED
