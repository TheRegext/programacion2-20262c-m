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
    cout<<"NOMBRE Y APELLIDO: "<<nombreApellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<endl;
    cout<<"DOMICILIO: "<<endl;
    domicilio.Mostrar();
}

void Alumno::setLegajo(int l){
    if(l>0){
        legajo = l;
    }else{
        legajo = 0;
    }
}

void Alumno::setNombreApellido(const char *nA){
    strcpy(nombreApellido, nA);
}

void Alumno::setFechaNacimiento(Fecha fN){
    fechaNacimiento = fN;
}

int Alumno::getLegajo(){
    return legajo;
}

const char *Alumno::getNombreApellido(){
    return nombreApellido;
}

Fecha Alumno::getFechaNacimiento(){
    return fechaNacimiento;
}

Alumno::~Alumno(){

}
