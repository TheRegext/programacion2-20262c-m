#include <iostream>
#include "clsArchivoAlumnos.h"

using namespace std;

/**
Modificar el menú principal para que tenga las siguientes opciones:
1 - ALUMNOS
2 - MATERIAS
0 - SALIR

Cada opción debe llamar a un submenú que permita agregar, listar todos y listar un registro en particular del archivo correspondiente.

Para ello deberán crear la clase Materia. Las materias tienen:
- Número.
- Nombre.
- Cuatrimestre al que pertenecen.
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
                agregarAlumno();
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
    int legajo;
    cout<<"INGRESE EL LEGAJO: ";
    cin>>legajo;
    if(legajo <= 0){
        cout<<"EL LEGAJO INGRESADO NO ES VALIDO"<<endl;
        return;
    }
    ArchivoAlumnos arcAlumnos;
    int pos = arcAlumnos.buscarRegistro(legajo);
    if(pos >= 0){
        cout<<"EL LEGAJO INGRESADO YA EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Cargar(legajo);
    ///VALIDAR LOS DATOS
    ///if(datosValidos){
    arcAlumnos.grabarRegistro(obj);
    ///}
}
