#include <iostream>
#include <cstring>
#include "cargarCadena.h"
#include "clsPersona.h"

using namespace std;

void Persona::Cargar(){
    cout<<"INGRESE EL NOMBRE Y APELLIDO: ";
    cargarCadena(nombreApellido, 50);
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<"INGRESE LA FECHA DE NACIMIENTO: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"INGRESE EL DOMICILIO: "<<endl;
    domicilio.Cargar();
}
void Persona::Mostrar(){
    cout<<"NOMBRE Y APELLIDO: "<<nombreApellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    fechaNacimiento.Mostrar();
    cout<<endl;
    cout<<"DOMICILIO: "<<endl;
    domicilio.Mostrar();
}
void Persona::setNombreApellido(const char *nA){
    strcpy(nombreApellido, nA);
}
void Persona::setDni(int d){
    dni = d;
}
void Persona::setFechaNacimiento(Fecha fN){
    fechaNacimiento = fN;
}
void Persona::setDomicilio(Domicilio d){
    domicilio = d;
}
const char *Persona::getNombreApellido(){
    return nombreApellido;
}
int Persona::getDni(){
    return dni;
}
Fecha Persona::getFechaNacimiento(){
    return fechaNacimiento;
}
Domicilio Persona::getDomicilio(){
    return domicilio;
}
