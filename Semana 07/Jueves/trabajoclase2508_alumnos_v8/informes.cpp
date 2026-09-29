# include<iostream>

using namespace std;
# include "libro.h"
# include "archivoLibros.h"
# include "informes.h"


void Informes::punto1(){
    int cantLibros=0, cantEjemplares;
    cout<<"INGRESAR LA CANTIDAD DE EJEMPLARES A BUSCAR ";
    cin>>cantEjemplares;

    ArchivoLibros archi;
    int cantReg=archi.cantidadRegistros();

    Libro regLibro;
    for(int i=0;i<cantReg;i++){
        regLibro=archi.leerRegistro(i);
        if(regLibro.getEstado()==true){
            if(regLibro.getCantEjemplares()==cantEjemplares) cantLibros++;
        }

    }
    cout<<"CANTIDAD DE LIBROS CON "<<cantEjemplares<<" EJEMPLARES DISPONIBLES "<<cantLibros<<endl;
}

void Informes::punto5(){
    ArchivoLibros archi;
    int cantReg=archi.cantidadRegistros();///???que hacemos con los borrados

    Libro regLibro, *vLibros;

    vLibros=new Libro[cantReg];
    if(vLibros==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }
    for(int i=0;i<cantReg;i++){
        regLibro=archi.leerRegistro(i);
        vLibros[i]=regLibro;
    }

    ///falta ordenar alfabéticamente por nombre de libro
    for(int i=0;i<cantReg;i++){
        if(vLibros[i].getEstado()){
                vLibros[i].mostrar();
                cout<<endl;
        }
    }


    delete []vLibros;
}


void Informes::punto7(){
    int vLibrosMes[12]={0};

    ArchivoLibros archi;
    int cantReg=archi.cantidadRegistros();

    Libro regLibro;
    for(int i=0;i<cantReg;i++){
        regLibro=archi.leerRegistro(i);
        if(regLibro.getEstado()==true){
            vLibrosMes[regLibro.getFechaPublicacion().getMes()-1]++;
        }

    }
    cout<<"CANTIDAD DE LIBROS PUBLICADOS POR MES "<<endl;
    for(int i=0;i<12;i++){
        cout<<"MES "<<i+1<<" CANTIDAD "<<vLibrosMes[i]<<endl;
    }
}
