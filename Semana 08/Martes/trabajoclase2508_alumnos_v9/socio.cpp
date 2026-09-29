#include <iostream>
#include <cstring>
#include "socio.h"

void Socio::setDni(int dni){
    _dni=dni;
}
int Socio::getDni(){
    return _dni;
}
void Socio::setApellido(const char *apellido){
    strcpy(_apellido,apellido);
}
const char *Socio::getApellido(){
    return _apellido;
}
void Socio::setNumTelefono(int numTelefono){
    _numTelefono=numTelefono;
}
int Socio::getNumTelefono(){
    return _numTelefono;
}
void Socio::setNombre(const char *nombre){
    strcpy(_nombre,nombre);
}

const char* Socio::getNombre(){
    return _nombre;
}
void Socio::setEmail(const char *email){
    strcpy(_email,email);
}
const char *Socio::getEmail(){
    return _email;
}
void Socio::setFechaNacimiento(Fecha fechaNacimiento){
    _fechaNacimiento=fechaNacimiento;
}
Fecha Socio::getFechaNacimiento(){
    return _fechaNacimiento;
}

void Socio::setId(int id){
    _id=id;
}
int Socio::getId(){
    return _id;
}
void Socio::cargar(int id){
    ///DEBEN IMPLEMENTAR ALUMNOS
}
void Socio::mostrar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
    cout<<"DNI "<<_dni<<endl;
    cout<<"ID "<<_id<<endl;
    cout<<"NOMBRE "<<_nombre<<endl;
    cout<<"APELLIDO "<<_apellido<<endl;
    _fechaNacimiento.mostrar();
    cout<<"*******************"<<endl;
}

void Socio::setDiaNacimiento(int d){
    _fechaNacimiento.setDia(d);
}

int Socio::getMesNacimiento(){
   int mes= _fechaNacimiento.getMes();
   return mes;
}

bool Socio::getEstado(){return _estado;}

void Socio::setEstado(bool estado){
    _estado=estado;
}
