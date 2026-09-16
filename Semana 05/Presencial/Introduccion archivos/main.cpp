#include <iostream>
#include "clsAlumno.h"

using namespace std;

/**
Crear un programa con un menú con las siguientes opciones:
1-Agregar un registro al archivo.
2-Listar los registros del archivo.
EXTRA:
Hacer una opción que reciba una posición y liste el registro de esa posición (el primer registro de mi archivo ocupa la posición 0).

TAREA:
Agregar una opción al menú que me permita listar un alumno que tenga un legajo que se ingresa por teclado.

DIFICIL:
Listar a todos los alumnos que tengan una fecha de nacimiento anterior a una fecha que se ingresa por teclado.
*/


int main()
{
    Alumno obj;
//    obj.Mostrar();
    //obj.Cargar();
    ///CREO UN PUNTERO FILE QUE VA A SER EL VINCULO CON MI ARCHIVO
    FILE *p;
    ///ABRO EL ARCHIVO
    p = fopen("alumnos.dat", "rb");
    ///MODOS DE APERTURA:
    ///LA b INDICA QUE ES UN ARCHIVO BINARIO
    ///r (read): ABRE EL ARCHIVO EN MODO LECTURA. SI NO EXISTE, NO LO CREA.
    ///a (append): ABRE EL ARCHIVO EN MODO ESCRITURA. SI NO EXISTE, LO CREA. SIEMPRE ESCRIBE AL FINAL.
    ///w (write): ABRE EL ARCHIVO EN MODO ESCRITURA. SIEMPRE CREA UN ARCHIVO EN BLANCO.
    if(p == nullptr){
        cout<<"ERROR DE APERTURA DE ARCHIVO"<<endl;
        return -1;
    }
    ///GUARDO INFORMACION EN MI ARCHIVO
    obj.setNombreApellido("PISO EL NOMBRE");
    while(fread(&obj, sizeof obj, 1, p)==1){
        obj.Mostrar();
        cout<<"====================="<<endl;
    }
//    fwrite(&obj, sizeof obj, 1, p);
    /**
    Primer argumento: la dirección de memoria donde está la información que quiero copiar en mi archivo.
    Segundo argumento: la cantidad de bytes que quiero copiar a mi archivo.
    Tercer argumento: la cantidad de registros que quiero copiar en mi archivo.
    Cuarto argumento: el vínculo con mi archivo (puntero FILE).
    */
    //fread(&obj, sizeof obj, 1, p);
    /**
    Primer argumento: la dirección de memoria a donde quiero copiar la información de mi archivo.
    Segundo argumento: la cantidad de bytes que quiero leer de mi archivo.
    Tercer argumento: la cantidad de registros que quiero leer de mi archivo.
    Cuarto argumento: el vínculo con mi archivo (puntero FILE).
    */
    ///CIERRO EL VINCULO CON MI ARCHIVO
    fclose(p);
    return 0;
}
