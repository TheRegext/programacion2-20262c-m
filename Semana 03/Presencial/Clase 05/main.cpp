#include <iostream>
#include <cstring>
#include "clsAlumno.h"

using namespace std;

/**
Crear una clase Alumno que almacene los siguientes datos:
-Legajo (int).
-Nombre y apellido (vector char).
-DNI.
-Dia, mes y año de nacimiento (3 int).
-Dia, mes y año de inscripcion (3 int)
-Domicilio (vector char).

El programa deberá solicitar la cantidad de alumnos que se van a cargar al momento de iniciarse la carga.

Extra: Crear además una clase Inscripcion que permita cargar las inscripciones del alumno a una materia que se identifica con un número de materia del 1 al 20.
PIENSENLO COMO UN TOTAL DE INSCRIPCIONES, NO POR MATERIA.

-ID de inscripcion.
-Numero de materia.
-Legajo del alumno.

Crear una clase Materia para almacenar los datos de las materias. Las materias se identifican con:
-Numero de materia.
-Nombre de materia.
-Cuatrimestre al que pertenece.
*/

/**
Agregar una opcion al menu que me pida una posicion y me muestre al alumno que ocupa esa posicion en el vector.

EXTRA: Agregar una funcion que me pida un legajo y me devuelva la posicion del alumno que tiene ese legajo en el vector. Si no existe el legajo, devuelve -1.
*/

/**
Utilizando el mecanismo de la composicion, agregar a la clase alumno una propiedad para la fecha de inscripcion y crear una clase Domicilio para almacenar la informacion del domicilio del alumno (calle, altura, localidad, provincia, codigo postal).

Hacer una funcion me pida un legajo y me muestre al alumno con ese legajo.

Validar que no se permitan legajos repetidos en mi vector.

Agregar al menu la opcion para listar un alumno por legajo.
*/

/**
Con los extras del punto 1, modificar el menu principal para que tenga como opciones los siguientes submenues:
1 - ALUMNOS.
2 - MATERIAS.
3 - INSCRIPCIONES.

Cada submenu debe tener un cargar y un mostrar.
*/

void menuPrincipal();
//void submenuAlumno(Alumno *, int);
void cargarAlumnos(Alumno *, int);
void mostrarAlumnos(Alumno *, int);

int main()
{
    menuPrincipal();
    return 0;
}

void menuPrincipal(){
    int opc;
    Alumno *vAlumnos=nullptr;
    int cantAlumnos;
    cout<<"INGRESE LA CANTIDAD DE ALUMNOS A CARGAR: ";
    cin>>cantAlumnos;
    if(cantAlumnos <= 0){
        cout<<"LA CANTIDAD INGRESADA NO ES VALIDA."<<endl;
        return;
    }
    vAlumnos = new Alumno[cantAlumnos];
    if(vAlumnos == nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return;
    }
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"==================="<<endl;
        cout<<"1 - CARGAR ALUMNOS"<<endl;
        cout<<"2 - MOSTRAR ALUMNOS"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"==================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cargarAlumnos(vAlumnos, cantAlumnos);
                break;
            case 2:
                mostrarAlumnos(vAlumnos, cantAlumnos);
                break;
            case 0:
                delete[] vAlumnos;
                return;
        }
        system("pause");
    }
}


void cargarAlumnos(Alumno *vec, int tam){
    for(int i=0; i<tam; i++){
        vec[i].Cargar();
    }
}
void mostrarAlumnos(Alumno *vec, int tam){
    for(int i=0; i<tam; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
}
