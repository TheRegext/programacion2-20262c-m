#include <iostream>
#include <cstring>
#include "clsAlumno.h"

using namespace std;


Alumno::Alumno(int l, const char *nA, int d, Fecha fN, Domicilio dom){
    legajo = l;
    strcpy(nombreApellido, nA);
    dni = d;
    fechaNacimiento = fN;
    domicilio = dom;
}

void Alumno::Cargar(){
    cout<<"INGRESE EL LEGAJO: ";
    cin>>legajo;
//    Persona::Cargar();
    cout<<"INGRESE EL NOMBRE Y APELLIDO: ";
    cin.ignore();
    cin.getline(nombreApellido, 50);
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<"INGRESE LA FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"INGRESE EL DOMICILIO: "<<endl;
    domicilio.Cargar();
}

void Alumno::Mostrar(){
    cout<<"LEGAJO: "<<legajo<<endl;
    Persona::Mostrar();
//    cout<<"NOMBRE Y APELLIDO: "<<nombreApellido<<endl;
//    cout<<"DNI: "<<dni<<endl;
//    cout<<"FECHA DE NACIMIENTO: ";
//    fechaNacimiento.Mostrar();
//    cout<<endl;
//    cout<<"DOMICILIO: "<<endl;
//    domicilio.Mostrar();
}

void Alumno::setLegajo(int l){
    if(l>0){
        legajo = l;
    }else{
        legajo = 0;
    }
}

int Alumno::getLegajo(){
    return legajo;
}

bool Alumno::operator==(int l){
    if(legajo == l){
        return true;
    }
    return false;
}

bool Alumno::operator==(Fecha fN){
    return fechaNacimiento == fN;
}

bool Alumno::operator<(int l){
    return legajo < l;
}

Alumno::~Alumno(){

}
