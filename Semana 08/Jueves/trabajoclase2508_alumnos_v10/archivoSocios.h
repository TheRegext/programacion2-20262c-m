#ifndef ARCHIVOSOCIOS_H_INCLUDED
#define ARCHIVOSOCIOS_H_INCLUDED

#include "socio.h"

class ArchivoSocios{
private:
    char _nombreArchivo[15];
public:
    ArchivoSocios(const char *nombreArchivo="socios.dat");
    bool agregarRegistro();
    bool mostrarRegistro(int estado = 0);
    int buscarRegistro(int id);
    Socio leerRegistro(int pos);
    bool sobreEscribirRegistro(Socio reg,int pos);
    int cantidadRegistros();
    ///modificarRegistroLibros()
};


#endif // ARCHIVOSOCIOS_H_INCLUDED
