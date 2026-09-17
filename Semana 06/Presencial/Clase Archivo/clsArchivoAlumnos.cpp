#include <iostream>
#include <cstring>
#include "clsArchivoAlumnos.h"

using namespace std;

ArchivoAlumnos::ArchivoAlumnos(const char *n){
    strcpy(nombre, n);
}

Alumno ArchivoAlumnos::leerRegistro(int pos){
    FILE *p=fopen(nombre ,"rb");
    Alumno obj;
    if(p == nullptr){
        obj.setLegajo(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoAlumnos::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Alumno);
}

bool ArchivoAlumnos::grabarRegistro(Alumno obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoAlumnos::buscarRegistro(int leg){
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Alumno obj = leerRegistro(i);
        if(obj.getLegajo() == leg) return i;
    }
    return -1;
}

void ArchivoAlumnos::listarRegistros(){
    int cantReg = contarRegistros();
    for(int i=0; i<cantReg; i++){
        Alumno obj = leerRegistro(i);
        obj.Mostrar();
        cout<<"======================="<<endl;
    }
}
