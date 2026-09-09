#include <iostream>
#include "menus.h"
using namespace std;

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
        cout<<"1 - ALUMNOS"<<endl;
        cout<<"2 - MATERIAS"<<endl;
        cout<<"3 - INGRESOS"<<endl;
        cout<<"4 - DOCENTES"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"==================="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuAlumnos(vAlumnos, cantAlumnos);
                break;
            case 2:
                //menuMaterias(vMaterias, cantMaterias);
                break;
            case 3:
                //menuInscripciones(vInscripciones, cantInscripciones)
                break;
            case 4:
               // menuDocentes(vDocentes, cantDocentes);
                break;
            case 0:
                delete[] vAlumnos;
                return;
        }
    }
}

void menuAlumnos(Alumno *vAlumnos, int cantAlumnos){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ALUMNOS"<<endl;
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
