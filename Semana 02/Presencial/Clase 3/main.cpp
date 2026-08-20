#include <iostream>
#include <cstring>
#include "clsFecha.h"
#include "clsEjemplo.h"

using namespace std;

/**
Hacer una clase para representar a los alumnos de la FRGP. Los mismos deben tener la siguiente información:
-Legajo
-Nombre y apellido
-Direccion
-Telefono
-Dia, mes y año de nacimiento

Además debe tener los métodos necesarios para cargar y mostrar la información por consola.
Agregar los SETTERS y GETTERS para TODAS las propiedades.
*/

/**
Hacer una clase Contador que tenga el siguiente comportamiento:

-Incrementar.
-Decrementar.
-Reiniciar.
-Mostrar valor.

Pensar que propiedades necesita mi clase.
*/

int main()
{
    {
        Fecha obj(3, 3, 1989);
        obj.Mostrar();
        obj.setAnio(2000);
        cout<<endl;
    }
    system("pause");
    return 0;
//    Fecha vec[10];
//    for(int i=0; i<10; i++){
//        vec[i].Cargar();
//    }
//    for(int i=0; i<10; i++){
//        vec[i].Mostrar();
//        cout<<endl;
//    }
//    cout<<endl;
//    return 0;
}
