///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
#include <cstring>

using namespace std;

#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "archivoLibros.h"
#include "informes.h"
#include "archivoSocios.h"
#include "archivoPrestamos.h"

bool borrarRegistroLibros(){
///    Buscar el registro que se quiere modificar.
    ArchivoLibros archiLibros;
    int isbn;
    Libro reg;


    cout<<"INGRESAR EL ISBN DEL LIBRO A BORRAR ";
    cin>>isbn;
    int pos=archiLibros.buscarRegistroLibro(isbn);
    if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
    }
    if(pos==-1){
            cout<<"NO EXISTE EL REGISTRO EN EL ARCHIVO "<<endl;
            return false;
    }
///Leer el registro (escribirlo en una variable de memoria)
    reg=archiLibros.leerRegistro(pos);
///Cambiar el/los valores de los campos de la variable
    reg.setEstado(false);
///Sobrescribir el registro en la misma posición del archivo en que se encontraba.
    bool borrado=archiLibros.sobreEscribirRegistro(reg,pos);
    return borrado;
}

bool modificarRegistroLibros(){
    ///    Buscar el registro que se quiere modificar.
    ArchivoLibros archiLibros;
    int isbn;
    Libro reg;
    cout<<"INGRESAR EL ISBN DEL LIBRO A MODIFICAR ";
    cin>>isbn;
    int pos=archiLibros.buscarRegistroLibro(isbn);
    if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
    }
    if(pos==-1){
            cout<<"NO EXISTE EL REGISTRO EN EL ARCHIVO "<<endl;
            return false;
    }
///Leer el registro (escribirlo en una variable de memoria)
    reg=archiLibros.leerRegistro(pos);
///Cambiar el/los valores de los campos de la variable
    int cantidad;
    cout<<"INGRESAR EL NUEVO VALOR DE CANTIDAD ";
    cin>>cantidad;
    reg.setCantEjemplares(cantidad);
///Sobrescribir el registro en la misma posición del archivo en que se encontraba.
    bool modificado=archiLibros.sobreEscribirRegistro(reg,pos);
    return modificado;
}

void generarArchivos() {
    /// Listas de datos reales para la carga automática
    Libro vLibros[10];
    Prestamo vPrestamos[10];
    Socio vSocios[10];
    int cantPrestamos=10;

    string nombresLibros[10] = {
        "Don Quijote de la Mancha", "Cien anos de soledad", "El principito",
        "Ficciones", "Pedro Paramo", "La ciudad y los perros",
        "Rayuela", "El aleph", "La casa de los espiritus", "Crónica de una muerte anunciada"
    };

    string autoresLibros[10] = {
        "Miguel de Cervantes", "Gabriel Garcia Marquez", "Antoine de Saint-Exupery",
        "Jorge Luis Borges", "Juan Rulfo", "Mario Vargas Llosa",
        "Julio Cortazar", "Jorge Luis Borges", "Isabel Allende", "Gabriel Garcia Marquez"
    };

    string nombresSocios[10] = {
        "Juan", "Maria", "Carlos", "Ana", "Luis", "Laura", "Diego", "Sofia", "Javier", "Elena"
    };

    string apellidosSocios[10] = {
        "Gonzalez", "Rodriguez", "Lopez", "Martinez", "Gomez", "Perez", "Sanchez", "Fernandez", "Romero", "Diaz"
    };

    /// 1. Cargar el vector de Libros con datos reales
    for (int i = 0; i < 10; i++) {
        vLibros[i].setIsbn(1000 + i); // ISBNs del 1000 al 1009
        vLibros[i].setNombre(nombresLibros[i].c_str());
        vLibros[i].setAutor(autoresLibros[i].c_str());
        vLibros[i].setFechaPublicacion(Fecha(1, 1, 1950 + (i * 5))); // Fechas de publicación variadas
        vLibros[i].setCantEjemplares(3 + i);
        vLibros[i].setEstado(true);
    }

    /// 2. Cargar el vector de Socios con datos reales
    for (int i = 0; i < 10; i++) {
        vSocios[i].setId(100 + i); // IDs del 100 al 109
        vSocios[i].setDni(40000000 + (i * 1234)); // DNIs ficticios pero con formato real
        vSocios[i].setNombre(nombresSocios[i].c_str());
        vSocios[i].setApellido(apellidosSocios[i].c_str());

        // Genera emails realistas basados en sus nombres
        string emailMuestra = nombresSocios[i] + "." + apellidosSocios[i] + "@email.com";
        vSocios[i].setEmail(emailMuestra.c_str());

        vSocios[i].setNumTelefono(15400000 + i);
        vSocios[i].setFechaNacimiento(Fecha(15, 6, 1985 + i));
        vSocios[i].setEstado(true);
    }

    /// 3. Cargar el vector de Prestamos respetando las relaciones (ISBN e ID existentes)
    for (int i = 0; i < cantPrestamos; i++) {
        vPrestamos[i].setNumLibro(vLibros[rand() % 10].getIsbn());   /// Toma un ISBN válido del vector en forma aleatoria
        vPrestamos[i].setIdSocio(vSocios[rand() % 10].getId());     /// Toma un ID válido del vector en forma aleatoria
        vPrestamos[i].setPrestamo(Fecha((rand()%31)+1,(rand()%12)+1, 2026));
        if(i%2==0)vPrestamos[i].setDevolucion(Fecha((rand()%31)+1,(rand()%12)+1, 2026));
        vPrestamos[i].setEstado(true);
    }

    ///generar archivo de libros
    FILE *pArchi;
    pArchi=fopen("libros.dat", "wb");
    if(pArchi==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fwrite(vLibros,sizeof(Libro), 10, pArchi);
    fclose(pArchi);
    ///generar archivo de socios
    pArchi=fopen("socios.dat", "wb");
    if(pArchi==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fwrite(vSocios,sizeof(Socio), 10, pArchi);
    fclose(pArchi);
    ///generar archivo de prestamos
    pArchi=fopen("prestamos.dat", "wb");
    if(pArchi==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fwrite(vPrestamos,sizeof(Prestamo), 10, pArchi);
    fclose(pArchi);
}


/*void buscarLibroIsbn(){
    int isbn;
    cout<<"INGRESAR EL ISBN DEL LIBRO A BUSCAR ";
    cin>>isbn;
    int valorDevuelto=buscarRegistroLibro(isbn);
    switch(valorDevuelto){
        case -1:    cout<<"NO EXISTE UN LIBRO CON ESE VALOR DE ISBN";
                    break;
        case -2:    cout<<"ERROR EN LA APERTURA DEL ARCHIVO";
                    break;
        default:    cout<<"EL LIBRO CON ISBN "<<isbn<<" EXISTE EN EL ARCHIVO";
                    break;
    }
    cout<<endl;

}
*/
void cargarLibros() {
    /// Listas de datos reales para la carga automática
    Libro vLibros[10];
    string nombresLibros[10] = {
        "Don Quijote de la Mancha", "Cien anos de soledad", "El principito",
        "Ficciones", "Pedro Paramo", "La ciudad y los perros",
        "Rayuela", "El aleph", "La casa de los espiritus", "Crónica de una muerte anunciada"
    };

    string autoresLibros[10] = {
        "Miguel de Cervantes", "Gabriel Garcia Marquez", "Antoine de Saint-Exupery",
        "Jorge Luis Borges", "Juan Rulfo", "Mario Vargas Llosa",
        "Julio Cortazar", "Jorge Luis Borges", "Isabel Allende", "Gabriel Garcia Marquez"
    };


    /// 1. Cargar el vector de Libros con datos reales
    for (int i = 0; i < 10; i++) {
        vLibros[i].setIsbn(1000 + i); // ISBNs del 1000 al 1009
        vLibros[i].setNombre(nombresLibros[i].c_str());
        vLibros[i].setAutor(autoresLibros[i].c_str());
        vLibros[i].setFechaPublicacion(Fecha(1, 1, 1950 + (i * 5))); // Fechas de publicación variadas
        vLibros[i].setCantEjemplares(3 + i);
        vLibros[i].setEstado(true);
    }

    FILE *pLibro;

    pLibro=fopen("libros.dat", "wb");
    ///chequear si se pudo abrir
    if(pLibro==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fwrite(vLibros,sizeof(Libro), 10, pLibro);
    fclose(pLibro);

}


/*
 Informar la cantidad de libros que tienen una cantidad de ejemplares igual a un valor que se ingresa por teclado
    Informar la cantidad de libros eliminados
    Informar el libro con más cantidad de ejemplares disponibles
    Informar el libro con menos cantidad de ejemplares disponibles
    Listar los libros ordenados por nombre alfabeticamente
    Informar el libro más antiguo
    Informar por cada mes la cantidad de libros publicados
*/
void menuInformes(){
    int opc;
    Informes obj;
    while(true){
        system("cls");
        cout<<"*************INFORMES***************"<<endl;
        cout<<"1. LIBROS POR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"2. CANTIDAD DE LIBROS ELIMINADOS"<<endl;
        cout<<"3. LIBRO CON MAYOR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"4. LIBROS CON MENOR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"5. LIBROS ORDENADOS ALFABETICAMENTE"<<endl;
        cout<<"6. LIBRO MAS ANTIGUO"<<endl;
        cout<<"7. CANTIDAD DE LIBROS PUBLICADOS POR MES "<<endl;
        cout<<"8. SOCIO CON MAS CANTIDAD DE PRESTAMOS "<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"OPCION ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: obj.punto1();
                    break;
            case 5: obj.punto5();
                    break;
            case 7: obj.punto7();
                    break;
            case 8: obj.punto8();
                    break;
            case 0: return;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;

        }
        system("pause");

    }




}


void mostrarSocios(){
    /*FILE *p;
    p=fopen("socios.dat","rb");
    if(p==nullptr)return;
    Socio reg;
    while(fread(&reg, sizeof reg, 1, p)==1){
        reg.mostrar();
        cout<<endl;
    }
    fclose(p);*/
    ArchivoSocios archi;
    archi.mostrarRegistro();
}

void mostrarPrestamos(){
/*    FILE *p;
    p=fopen("prestamos.dat","rb");
    if(p==nullptr)return;
    Prestamo reg;
    while(fread(&reg, sizeof reg, 1, p)==1){
        reg.mostrar(1);
        cout<<endl;
    }
    fclose(p);*/
    ArchivoPrestamos archi;
    archi.mostrarRegistro(0);
}
