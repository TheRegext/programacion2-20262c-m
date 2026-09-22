#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;


#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "resolucion.h"
#include "funcionesArchivoLibro.h"

///Agregar al menú las siguientes opciones
        ///cout<<"3. AGREGAR REGISTROS ARCHIVO SOCIOS"<<endl;
        ///cout<<"4. MOSTRAR REGISTROS ARCHIVO SOCIOS"<<endl;
        ///cout<<"5. AGREGAR REGISTROS ARCHIVO PRESTAMOS"<<endl;
        ///cout<<"6. MOSTRAR REGISTROS ARCHIVO PRESTAMOS"<<endl;
///Agregar todos los .h y los .cpp que se consideren necesarios
///Modificar las clases existentes que así lo requieran(a excepción de Libro) para que puedan generarse registros en los archivos
///correspodientes

int main(){

    int opc;
    while(true){
        system("cls");
        cout<<"1. AGREGAR REGISTROS ARCHIVO LIBROS"<<endl;
        cout<<"2. MOSTRAR REGISTROS ARCHIVO LIBROS"<<endl;
        cout<<"0. SALIR DEL PROGRAMA "<<endl;
        /*cout<<"6. PRESTAMOS DE LIBROS POR SOCIO "<<endl;
        cout<<"4. "<<endl;
        cout<<"5. "<<endl;
        cout<<"0. "<<endl;*/
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:     if(agregarRegistroLibro()) cout<<"REGISTRO AGREGADO ";
                        else cout<<"NO SE PUDO AGREGAR EL REGISTRO";
                        cout<<endl;
                        break;
            case 2:     if(!mostrarRegistrosLibro())cout<<"ERROR DE LECTURA DEL ARCHIVO"<<endl;
                        break;
            case 3:
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
