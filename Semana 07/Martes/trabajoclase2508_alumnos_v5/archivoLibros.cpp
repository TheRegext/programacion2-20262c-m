# include<iostream>
# include<cstring>

using namespace std;
# include "libro.h"
# include "archivoLibros.h"
# include "funcionesGlobales.h"


bool ArchivoLibros::agregarRegistroLibro(){
    ///declaración de variables
    FILE *pLibro;
    Libro reg;
    ///apertura del archivo
    pLibro=fopen(_nombreArchivo, "ab");
    ///chequear si se pudo abrir
    if(pLibro==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Cargar en memoria el registro de libro
    int isbn;
    cout<<"INGRESAR EL VALOR DE ISBN ";
    cin>>isbn;
    int pos=buscarRegistroLibro(isbn);
    ///pos debe ser ??? para aceptarlo como nuevo _isbn
    if(pos==-1){
            reg.cargar(isbn);
            ///Escribir en el disco el registro
            int escribio=fwrite(&reg,sizeof reg, 1, pLibro);///Si pudo escribir devuelve la cantidad de registros
            ///Cerrrar el archivo                           ///Si no pudo escribir devuelve 0
            fclose(pLibro);
            return escribio;
    }
    else{
        cout<<"YA EXISTE UN LIBRO CON ESE ISBN"<<endl<<endl;
    }
    return false;
}

bool ArchivoLibros::mostrarRegistroLibro(){
    ///declaración de variables
    FILE *pLibro;
    Libro reg;
    ///apertura del archivo
    pLibro=fopen(_nombreArchivo, "rb");
    ///chequear si se pudo abrir
    if(pLibro==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Leer del disco el/los registro/s mientras haya registros en el archivo
    while(fread(&reg,sizeof reg, 1, pLibro)==1){;///Si pudo leer devuelve la cantidad de registros
    ///mostrar el registro
        reg.mostrar();
    }

    fclose(pLibro);
    return true;
}

///Devuelve la posición que ocupa el libro con el _isbn igual a isbn
///Si no lo encuentra devuelve -1
///Si no pudo abrir el archivo devuelve -2

int ArchivoLibros::buscarRegistroLibro(int isbn){
    FILE *pLibro;
    Libro reg;
    int pos=0;
    pLibro=fopen(_nombreArchivo, "rb");
    if(pLibro==nullptr){
            return -2;
    }
    while(fread(&reg, sizeof reg, 1, pLibro)==1){
        if(reg.getIsbn()==isbn){
            fclose(pLibro);
            return pos;
        }
        pos++;
    }
    fclose(pLibro);
    return -1;
}

ArchivoLibros::ArchivoLibros(const char *nombreArchivo){
    strcpy(_nombreArchivo,nombreArchivo);
}

Libro ArchivoLibros::leerRegistro(int pos){
    FILE *pLibro;
    Libro reg;
    reg.setIsbn(-1);
    pLibro=fopen(_nombreArchivo, "rb");
    if(pLibro==nullptr){
            return reg;
    }
    fseek(pLibro,pos*sizeof(Libro),0);  ///SEEK_SET->0 DESDE EL PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL ///SEEK_END->2 DESDE EL FINAL
    fread(&reg,sizeof(Libro),1,pLibro);
    fclose(pLibro);
    return reg;
}


bool ArchivoLibros::sobreEscribirRegistro(Libro reg,int pos){
    FILE *pLibro;
    pLibro=fopen(_nombreArchivo, "rb+");///+ le agrega al modo lo que no tiene
    if(pLibro==nullptr){
            return false;
    }
    fseek(pLibro,pos*sizeof(Libro),0);  ///SEEK_SET->0 DESDE EL PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL ///SEEK_END->2 DESDE EL FINAL
    bool escribio=fwrite(&reg,sizeof(Libro),1,pLibro);
    fclose(pLibro);
    return escribio;
}
