# include<iostream>
# include<cstring>
using namespace std;
# include "libro.h"
# include "archivoLibros.h"
# include "informes.h"
# include "socio.h"
# include "archivoSocios.h"
#include "prestamo.h"
# include "archivoPrestamos.h"

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
    int cantRegTot=archi.cantidadRegistros();
    int cantReg=archi.cantidadRegistros(1);///???que hacemos con los borrados
    ///por defecto 2, que cuenta todos los registros
    ///si le mandamos como parámetro un 0 me cuenta sólo los borrados
    ///si le mandamos un 1 me cuenta sólo los activos
   /* cout<<"CANTIDAD DE REGISTROS TOTALES "<<cantReg<<endl;
    cantReg=archi.cantidadRegistros(0);
    cout<<"CANTIDAD DE REGISTROS BORRADOS "<<cantReg<<endl;
    cantReg=archi.cantidadRegistros(1);
    cout<<"CANTIDAD DE REGISTROS ACTIVOS "<<cantReg<<endl;

    system("pause");
    return;*/
    Libro regLibro, *vLibros;

    vLibros=new Libro[cantReg];
    if(vLibros==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }
    int pos=0;
    for(int i=0;i<cantRegTot;i++){
        regLibro=archi.leerRegistro(i);
        if(regLibro.getEstado()){
          vLibros[pos]=regLibro;
          pos++;
        }
    }

    ///falta ordenar alfabéticamente por nombre de libro
    ordenarLibrosPorNombre(vLibros, cantReg);
    for(int i=0;i<cantReg;i++){
            vLibros[i].mostrar();
            cout<<endl;
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

void Informes::ordenarLibrosPorNombre(Libro *vL, int cantReg){
    /*int i, j, posMin;ORDENA POR CANTIDAD DE EJEMPLARES
    Libro aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(vL[j].getCantEjemplares()<vL[posMin].getCantEjemplares()){
                posMin=j;
            }
        }
        aux=vL[i];
        vL[i]=vL[posMin];
        vL[posMin]=aux;
    }*/
    int i, j, posMin;
    Libro aux;
    for(i=0;i<cantReg-1;i++){
        posMin=i;
        for(j=i+1;j<cantReg;j++){
            if(strcmp(vL[j].getNombre(),vL[posMin].getNombre())<0){
                posMin=j;
            }
        }
        aux=vL[i];
        vL[i]=vL[posMin];
        vL[posMin]=aux;
    }
}

void Informes::ordenarVectorEnteros(int *v, int cant){
    int i, j;
    int posMin, aux;
    for(i=0;i<cant-1;i++){
        posMin=i;
        for(j=i+1;j<cant;j++){
            if(v[j]<v[posMin]){
                posMin=j;
            }
        }
        ///se cuál es la posición del mínimo
        aux=v[i];
        v[i]=v[posMin];
        v[posMin]=aux;
    }
}

void Informes::mostrarVectorEnteros(int *v, int cant){
    int i;
    for(i=0;i<cant;i++){
        cout<<v[i]<<endl;
    }
}


/*void Informes::punto8(){///Socio con más préstamos
    ArchivoSocios arSocio;
    int cant=arSocio.cantidadRegistros();

    int *vIDSocios;
    vIDSocios=new int[cant];
    if(vIDSocios==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }

    int *vCant;
    vCant=new int[cant];
    if(vCant==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        delete []vIDSocios;
        return;
    }
    Socio aux;
    for(int i=0;i<cant;i++){
        aux=arSocio.leerRegistro(i);
        vIDSocios[i]=aux.getId();
        vCant[i]=0;
    }

    ArchivoPrestamos arPrestamo;
    Prestamo regPrestamo;
    int cantReg=arPrestamo.cantidadRegistros();
    for(int i=0;i<cantReg;i++){
        regPrestamo=arPrestamo.leerRegistro(i);
        int pos=buscarIDenVector(vIDSocios,regPrestamo.getIdSocio(),cant);
        vCant[pos]++;
    }

    int posMax=0;
    for(int i=1;i<cant;i++){
        if(vCant[i]>vCant[posMax]) posMax=i;
    }

    cout<<"SOCIO CON MAS PRESTAMOS "<<vIDSocios[posMax]<<endl;
    aux=arSocio.leerRegistro(posMax);
    aux.mostrar();

    delete []vIDSocios;
    delete []vCant;

}
*/

int Informes::buscarIDenVector(int *vIDSocios,int IdSocio,int cant){
    for(int i=0;i<cant;i++){
        if(vIDSocios[i]==IdSocio) return i;
    }
    return -1;
}

void Informes::punto8(){///Socio con más préstamos
    ArchivoSocios arSocio;
    int cant=arSocio.cantidadRegistros();

    int *vCant;
    vCant=new int[cant];
    if(vCant==nullptr){
        cout<<"ERROR DE MEMORIA "<<endl;
        return;
    }

    for(int i=0;i<cant;i++) vCant[i]=0;

    ArchivoPrestamos arPrestamo;
    Prestamo regPrestamo;
    int cantReg=arPrestamo.cantidadRegistros();
    for(int i=0;i<cantReg;i++){
        regPrestamo=arPrestamo.leerRegistro(i);
        int pos=arSocio.buscarRegistro(regPrestamo.getIdSocio());
        vCant[pos]++;
    }

    int posMax=0;
    for(int i=1;i<cant;i++){
        if(vCant[i]>vCant[posMax]) posMax=i;
    }

    cout<<"SOCIO CON MAS PRESTAMOS "<<endl;
    Socio aux=arSocio.leerRegistro(posMax);
    aux.mostrar();
    cout<<endl<<"CON "<<vCant[posMax]<<" LIBROS PEDIDOS"<<endl;

    delete []vCant;

}
