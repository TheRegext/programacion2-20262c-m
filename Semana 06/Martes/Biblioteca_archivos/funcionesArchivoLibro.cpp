# include<iostream>


using namespace std;
#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "funcionesArchivoLibro.h"

///MODO DE APERTURA DE ARCHIVOS EN fopen:
    ///     wb (write)->crea un archivo nuevo VACIO. Si existe lo destruye
    ///     rb (read)-> abre un archivo sólo para leerlo. Si no existe el archivo falla
    ///     ab (append)->abre un archivo para agregar registros. Si no existe lo crea

bool agregarRegistroLibro(){
    ///CARGAR EL REGISTRO EN LA MEMORIA
    Libro reg;
    reg.cargar();
    ///APERTURA DEL ARCHIVO
    FILE *pLibro;
    pLibro=fopen("libros.dat","ab");
    ///COMPROBACION DE LA APERTURA
    if(pLibro==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///ESCRITURA DEL REGISTRO EN EL ARCHIVO
    int escribio=fwrite(&reg,sizeof reg,1,pLibro);
    ///CIERRE DEL ARCHIVO
    fclose(pLibro);
    return escribio;
}

bool mostrarRegistrosLibro(){
    ///DECLARAR LA VARIABLE DONDE SE QUIERE ESCRIBIR LO QUE TIENE EL DISCO
    Libro reg;
    ///APERTURA DEL ARCHIVO
    FILE *pLibro;
    pLibro=fopen("libros.dat","rb");
    ///COMPROBACION DE LA APERTURA
    if(pLibro==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///LECTURA DEL REGISTRO EN EL ARCHIVO Y MUESTRA DE LOS REGISTROS
    while(fread(&reg,sizeof reg,1,pLibro)==1){
        reg.mostrar();
    }

    /*leyo=fread(&reg,sizeof reg,1,pLibro);
    cout<<"QUE DEVUELVE fread()"<<leyo<<endl<<endl;
    ///MOSTRAR EL REGISTRO LEIDO
    reg.mostrar();
    leyo=fread(&reg,sizeof reg,1,pLibro);
    cout<<"QUE DEVUELVE fread()CUANDO NO HAY MAS REGISTROS"<<leyo<<endl<<endl;
*/
    ///CIERRE DEL ARCHIVO

    fclose(pLibro);

    return true;
}
