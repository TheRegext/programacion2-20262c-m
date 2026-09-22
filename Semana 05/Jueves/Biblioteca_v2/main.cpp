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
///Hacer una clase Resolucion, con los métodos punto3(), punto4() y punto5() que resuelvan lo que se pide a continuación
///3. Sabiendo que los _idSocio están definidos del 100 al 109,  calcular e informar cuántos libros pidió cada socio.
///4. Sabiendo que los valores de _isbn de los libros están definidos enter el 1000 al 1009, informar los libros que no fueron prestados
///5. Hacer un listado de los préstamos que no fueron devueltos, informando el nombre del libro, el nombre del socio y la fecha del préstamo
///6. Informar por cada socio la cantidad de préstamos de cada uno de los libros
///7. Informar los socios que nunca pidieron libros
///8. Listar los libros que fueron publicados en el presente siglo

///9. Cambiar la propiedad IDSocio, de manera tal que sus valores siguen siendo numéricos pero no son correlativos

///10. La biblioteca quiere registrar además a los 5 empleados que tiene, con IDs del 1 al 5.
///Agregar al programa una opción para registrar los empleados con el siguiente formato:
    /*

    int _dni;
    string _apellido;
    string _nombre;
    int _numTelefono;
    string _email;
    float sueldo
    */
/// 11. Modificar préstamos agregando el DNI del empleado que realiza el préstamo.

int const cantPrestamos=20;

int main(){

    //srand(time(NULL));

    Socio vSocios[10];
    Libro vLibros[10];
    Prestamo vPrestamos[cantPrestamos];
    bool vectoresCargados=false;
    int opc;
    Resolucion obj;
    while(true){
        system("cls");
        cout<<"1. CARGAR VECTORES"<<endl;
        cout<<"2. MOSTRAR VECTORES"<<endl;
        cout<<"3. CANTIDAD DE LIBROS POR SOCIO "<<endl;
        cout<<"6. PRESTAMOS DE LIBROS POR SOCIO "<<endl;
        cout<<"4. "<<endl;
        cout<<"5. "<<endl;
        cout<<"0. "<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:     cargarVectores(vLibros, vPrestamos,vSocios, cantPrestamos);
                        vectoresCargados=true;
                        break;
            case 2:     if(vectoresCargados){
                            mostrarVectores(vLibros, vPrestamos,vSocios, cantPrestamos);
                        }
                        else{
                            cout<<endl<<"Primero debe cargar los vectores!"<<endl<<endl;
                        }
                        break;
            case 3:     obj.punto3_sin_orden(vPrestamos, vSocios);
                        break;
            case 4:
                        break;
            case 5:
                        break;
            case 6:     obj.punto6(vLibros,vSocios,vPrestamos,cantPrestamos);
                        break;
            case 0:     return 0;
            default:    cout<<"INGRESO INCORRECTO "<<endl;
                        break;
        }
        system("pause");
    }

    return 0;
}
