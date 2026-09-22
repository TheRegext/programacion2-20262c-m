#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;


#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "archivoLibros.h"

///Agregar al programa las siguientes opciones del menú:
    ///cout<<"3. AGREGAR REGISTRO DE SOCIO"<<endl;
    /// cout<<"4. MOSTRAR REGISTROS DE SOCIOS"<<endl;
    ///cout<<"5. AGREGAR REGISTRO DE PRESTAMO"<<endl;
    /// cout<<"6. MOSTRAR REGISTROS DE PRESTAMOS"<<endl;
///Agregar todas las funciones y archivos que sean necesarios.
///Modificar, si es necesario, el tipo de dato de las propiedades definidas en las clases

///Para la opción de agregar registros de libros, validar que no se repita el ISBN
int main(){
    int opc;
    ArchivoLibros archiLibro;

    while(true){
        system("cls");
        cout<<"********ARCHIVO LIBROS*******"<<endl;
        cout<<"1. AGREGAR REGISTRO DE LIBRO"<<endl;
        cout<<"2. BORRAR REGISTRO DE LIBRO"<<endl;
        cout<<"3. MODIFICAR CANTIDAD DE UN REGISTRO DE LIBRO"<<endl;
        cout<<"4. MOSTRAR REGISTROS DE LIBROS"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:     if(archiLibro.agregarRegistroLibro()) cout<<"REGISTRO AGREGADO";
                        else cout<<"NO SE PUDO AGREGAR EL REGISTRO";
                        cout<<endl;
                        break;
            case 4:     if(!archiLibro.mostrarRegistroLibro())cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
                        break;
            case 2:     if(!borrarRegistroLibros()) cout<<"NO SE PUDO BORRAR EL REGISTRO "<<endl;
                        else    cout<<"REGISTRO BORRADO "<<endl;
                        break;
            case 3:     if(!modificarRegistroLibros()) cout<<"NO SE PUDO MODIFICAR EL REGISTRO "<<endl;
                        else    cout<<"REGISTRO MODIFICADO "<<endl;
                        break;
            case 5:
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
