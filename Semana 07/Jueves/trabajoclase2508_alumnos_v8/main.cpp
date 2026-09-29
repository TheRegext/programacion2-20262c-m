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
#include "informes.h"
/*
    Informar la cantidad de libros que tienen una cantidad de ejemplares igual a un valor que se ingresa por teclado
    Informar la cantidad de libros eliminados
    Informar el libro con más cantidad de ejemplares disponibles
    Informar el libro con menos cantidad de ejemplares disponibles
    Listar los libros ordenados por nombre alfabeticamente
    Informar el libro más antiguo
*/

int main(){
    int opc;
    ArchivoLibros archiLibro;
   // cargarLibros();
    while(true){
        system("cls");
        cout<<"********ARCHIVO LIBROS*******"<<endl;
        cout<<"1. AGREGAR REGISTRO DE LIBRO"<<endl;
        cout<<"2. BORRAR REGISTRO DE LIBRO"<<endl;
        cout<<"3. MODIFICAR CANTIDAD DE UN REGISTRO DE LIBRO"<<endl;
        cout<<"4. MOSTRAR REGISTROS DE LIBROS"<<endl;
        cout<<"5. MOSTRAR CANTIDAD DE REGISTROS"<<endl;
        cout<<"6. INFORMES"<<endl;
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
            case 5:     {
                            int cant = archiLibro.cantidadRegistros();
                            if(cant >= 0){
                                cout<< "LA CANTIDAD DE REGISTROS ES: "<< cant <<endl;
                            }else {
                                cout<< "NO SE PUDO ABRIR EL ARCHIVO"<<endl;
                            }
                            break;
                        }
            case 6:     menuInformes();
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
