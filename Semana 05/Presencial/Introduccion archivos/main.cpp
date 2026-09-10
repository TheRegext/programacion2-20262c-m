#include <iostream>
#include "clsAlumno.h"

using namespace std;

int main()
{
    Alumno obj(12345, "Juan Manuel Fernandez", 44000333, 24, 4, 2002, "Calle falsa  123");
    obj.Mostrar();
    ///CREO UN PUNTERO FILE QUE VA A SER EL VINCULO CON MI ARCHIVO
    FILE *p;
    ///ABRO EL ARCHIVO
    p = fopen("alumnos.dat", "wb");
    ///MODOS DE APERTURA:
    ///LA b INDICA QUE ES UN ARCHIVO BINARIO
    ///r (read): ABRE EL ARCHIVO EN MODO LECTURA. SI NO EXISTE, NO LO CREA.
    ///a (append): ABRE EL ARCHIVO EN MODO ESCRITURA. SI NO EXISTE, LO CREA.
    ///w (write): ABRE EL ARCHIVO EN MODO ESCRITURA. SIEMPRE CREA UN ARCHIVO EN BLANCO.
    if(p == nullptr){
        cout<<"ERROR DE APERTURA DE ARCHIVO"<<endl;
        return -1;
    }
    ///GUARDO INFORMACION EN MI ARCHIVO
    fwrite(&obj, sizeof obj, 1, p);
    ///CIERRO EL VINCULO CON MI ARCHIVO
    fclose(p);
    return 0;
}
