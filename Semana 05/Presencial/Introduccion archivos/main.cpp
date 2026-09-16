#include <iostream>
#include "clsAlumno.h"

using namespace std;

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
//    fwrite(&obj, sizeof obj, 1, p);
    obj.setNombreApellido("PISO EL NOMBRE");
    while(fread(&obj, sizeof obj, 1, p)==1){
        obj.Mostrar();
        cout<<"====================="<<endl;
    }
    /**
    Primer argumento: la dirección de memoria donde está la información que quiero copiar en mi archivo.
    Segundo argumento: la cantidad de bytes que quiero copiar a mi archivo.
    Tercer argumento: la cantidad de registros que quiero copiar en mi archivo.
    Cuarto argumento: el vínculo con mi archivo (puntero FILE).
    */
    ///CIERRO EL VINCULO CON MI ARCHIVO
    fclose(p);
    return 0;
}
