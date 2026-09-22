#include <iostream>
#include "libro.h"
#include <cstring>

using namespace std;

void Libro::setIsbn(int isbn){
    _isbn=isbn;
}
int Libro::getIsbn(){
    return _isbn;
}
void Libro::setAutor(const char * autor){
    strcpy(_autor,autor);
}
const char * Libro::getAutor(){
    return _autor;
}
void Libro::setNombre(const char * nombre){
    strcpy(_nombre,nombre);
}
const char * Libro::getNombre(){
    return _nombre;
}
void Libro::setFechaPublicacion(Fecha fechaPublicacion){
    _fechaPublicacion=fechaPublicacion;
}
Fecha Libro::getFechaPublicacion(){
    return _fechaPublicacion;
}
void Libro::setCantEjemplares(int cantEjemplares){
    _cantEjemplares=cantEjemplares;
}
int Libro::getCantEjemplares(){
    return _cantEjemplares;
}
void Libro::cargar(){
    cout<<"ISBN ";
    cin>>_isbn;

    cout<<"NOMBRE ";
    cin>>_nombre;

    cout<<"AUTOR ";
    cin>>_autor;

    cout<<"FECHA DE PUBLICACION ";
    _fechaPublicacion.cargar();

    cout<<"CANTIDA DE EJEMPLARES ";
    cin>>_cantEjemplares;

    cout<<"*********************"<<endl;
}
void Libro::mostrar(){
    cout<<"ISBN "<<_isbn<<endl;

    cout<<"NOMBRE "<<_nombre<<endl;

    cout<<"AUTOR "<<_autor<<endl;

    cout<<"FECHA DE PUBLICACION ";
    _fechaPublicacion.mostrar();

    cout<<"CANTIDA DE EJEMPLARES "<<_cantEjemplares<<endl;

    cout<<"*********************"<<endl;
}
