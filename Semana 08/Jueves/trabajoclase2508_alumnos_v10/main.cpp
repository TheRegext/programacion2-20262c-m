#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;


#include "fecha.h"
#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "archivoLibros.h"
#include "informes.h"
#include "archivoSocios.h"
#include "archivoPrestamos.h"
#include "informes2.h"
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
   /// generarArchivos();
    //int vec[10]={5,7,9,3,1,2,10,4,8,6};
    //Informes obj;
    //obj.ordenarVectorEnteros(vec,10);
    //obj.mostrarVectorEnteros(vec,10);
   /* string mes="ENERO";
    Fecha fecha1, fecha2(mes);
    fecha1.cargar();
    fecha1.mostrar();
    cout<<endl;
    fecha2.mostrar();
    cout<<endl;
    if(fecha1>fecha2) fecha1.mostrar();
    else fecha2.mostrar();

    system("pause");*/
    Informe2 obj;
    while(true){
        system("cls");
        cout<<"********ARCHIVO LIBROS*******"<<endl;
        cout<<"1. AGREGAR REGISTRO DE LIBRO"<<endl;
        cout<<"2. BORRAR REGISTRO DE LIBRO"<<endl;
        cout<<"3. MODIFICAR CANTIDAD DE UN REGISTRO DE LIBRO"<<endl;
        cout<<"4. MODIFICAR FECHA DE PUBLICACION DE UN LIBRO"<<endl;
        cout<<"5. MOSTRAR REGISTROS DE LIBROS"<<endl;
        cout<<"6. MOSTRAR REGISTROS DE SOCIOS"<<endl;
        cout<<"7. MOSTRAR REGISTROS DE PRESTAMOS"<<endl;
        cout<<"8. INFORMES"<<endl;
        cout<<"9. INFORMES PRACTICA 01/10"<<endl;
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
            case 2:     if(!borrarRegistroLibros()) cout<<"NO SE PUDO BORRAR EL REGISTRO "<<endl;
                        else    cout<<"REGISTRO BORRADO "<<endl;
                        break;
            case 3:     if(!modificarRegistroLibros()) cout<<"NO SE PUDO MODIFICAR EL REGISTRO "<<endl;
                        else    cout<<"REGISTRO MODIFICADO "<<endl;
                        break;
            case 4:     if(!modificarRegistroLibrosFecha()) cout<<"NO SE PUDO MODIFICAR EL REGISTRO "<<endl;
                        else    cout<<"REGISTRO MODIFICADO "<<endl;
                        break;

            case 5:     if(!archiLibro.mostrarRegistroLibro(1))cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
                        break;
            case 6:     mostrarSocios();
                        break;
            case 7:     mostrarPrestamos();
                        break;
            case 8:     menuInformes();
                        break;
            case 9:     obj.menuInformes2();
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
