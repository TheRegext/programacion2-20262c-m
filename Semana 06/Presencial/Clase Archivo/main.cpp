#include <iostream>
#include "clsArchivoAlumnos.h"

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

void menuPrincipal();
void agregarAlumno();
void listarAlumnos();
void listarPorLegajo();

int main(){
    menuPrincipal();
    return 0;
}

void menuPrincipal(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR ALUMNO"<<endl;
        cout<<"2 - LISTAR ALUMNOS"<<endl;
        cout<<"3 - BUSCAR ALUMNO"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                //agregarAlumno();
                break;
            case 2:
                listarAlumnos();
                break;
            case 3:
                listarPorLegajo();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

void listarPorLegajo(){
    cout<<"INGRESE EL LEGAJO A BUSCAR: ";
    int legajo;
    cin>>legajo;
    ArchivoAlumnos arcAlumnos;
    int pos = arcAlumnos.buscarRegistro(legajo);
    if(pos < 0){
        cout<<"EL LEGAJO INGRESADO NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    Alumno obj = arcAlumnos.leerRegistro(pos);
    obj.Mostrar();
}

void listarAlumnos(){
    ArchivoAlumnos arcAlumnos;
    arcAlumnos.listarRegistros();
}

void agregarAlumno(){
    Alumno obj;
    obj.Cargar();
    ///VALIDAR LOS DATOS
    ///if(datosValidos){
    ArchivoAlumnos arcAlumnos;
    arcAlumnos.grabarRegistro(obj);
    ///}
}
