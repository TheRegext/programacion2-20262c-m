#include <iostream>
#include "clsAlumno.h"

using namespace std;

/**
Crear un programa con un menú con las siguientes opciones:
1-Agregar un registro al archivo.
2-Listar los registros del archivo.
EXTRA:
Hacer una opción que reciba una posición y liste el registro de esa posición (el primer registro de mi archivo ocupa la posición 0).

TAREA:
Agregar una opción al menú que me permita listar un alumno que tenga un legajo que se ingresa por teclado.

DIFICIL:
Listar a todos los alumnos que tengan una fecha de nacimiento anterior a una fecha que se ingresa por teclado.
*/

void menuPrincipal();
void agregarAlumno();
void listarAlumnos();
void buscarAlumnoPosicion(int pos);
void listarPosicion();
int contarAlumnos();

int main(){
    menuPrincipal();
    return 0;
}

void menuPrincipal(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR ALUMNO"<<endl;
        cout<<"2 - LISTAR ALUMNOS"<<endl;
        cout<<"3 - BUSCAR ALUMNO"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarAlumno();
                break;
            case 2:
                listarAlumnos();
                break;
            case 3:
                listarPosicion();
                break;
            case 0:
                return;
        }
        system("pause");
    }
}

Alumno leerAlumno(int pos){
    Alumno obj;
    FILE *p = fopen("alumnos.dat", "rb");
    if(p == nullptr){
        obj.setLegajo(-1);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    obj.setLegajo(-2);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
    /**
    Primer argumento: vínculo con mi archivo (puntero FILE).
    Segundo argumento: cantidad de bytes que quiero desplazarme.
    Tercer argumento: desde donde quiero desplazarme.
        -SEEK_SET (o 0): desde el principio.
        -SEEK_CUR (o 1): desde la posición actual.
        -SEEK_END (o 2): desde el eof (end of file) o el final del archivo.
    */
}

void buscarAlumnoPosicion(int pos){
    Alumno obj;
    FILE *p = fopen("alumnos.dat", "rb");
    if(p == nullptr){
        return;
    }
    int cont = 0;
    while(fread(&obj, sizeof obj, 1, p) and cont < pos){
        cont++;
    }
    if(cont != pos){
        cout<<"LA POSICION INGRESADA NO EXISTE EN EL ARCHIVO"<<endl;
        return;
    }
    obj.Mostrar();
    fclose(p);
}

void listarPosicion(){
    cout<<"INGRESE LA POSICION DEL REGISTRO A MOSTRAR: ";
    int pos;
    cin>>pos;
    if(pos<0){
        cout<<"LA POSICION NO PUEDE SER NEGATIVA"<<endl;
        return;
    }
    Alumno obj = leerAlumno(pos);
    if(obj.getLegajo() == -2){
        cout<<"NO EXISTE ESA POSICION EN EL ARCHIVO"<<endl;
        return;
    }
    if(obj.getLegajo() == -1){
        cout<<"ERROR DE APERTURA DE ARCHIVO"<<endl;
        return;
    }
    obj.Mostrar();
}

void agregarAlumno(){
    Alumno obj;
    obj.Cargar();
    FILE *pAlumno;
    pAlumno = fopen("alumnos.dat", "ab");
    if(pAlumno == nullptr){
        cout<<"ERROR DE APERTURA DEL ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, pAlumno);
    fclose(pAlumno);
}

int contarAlumnos(){
    FILE *p = fopen("alumnos.dat", "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Alumno);
}

void listarAlumnos(){
    Alumno obj;
    int cantReg = contarAlumnos();
    for(int i = 0; i < cantReg; i++){
        obj = leerAlumno(i);
        obj.Mostrar();
        cout<<"================="<<endl;
    }
}

int mainViejo()
{
    Alumno obj;
//    obj.Mostrar();
    //obj.Cargar();
    ///CREO UN PUNTERO FILE QUE VA A SER EL VINCULO CON MI ARCHIVO
    FILE *p;
    ///ABRO EL ARCHIVO
    p = fopen("alumnos.dat", "rb");
    ///MODOS DE APERTURA:
    ///LA b INDICA QUE ES UN ARCHIVO BINARIO
    ///r (read): ABRE EL ARCHIVO EN MODO LECTURA. SI NO EXISTE, NO LO CREA.
    ///a (append): ABRE EL ARCHIVO EN MODO ESCRITURA. SI NO EXISTE, LO CREA. SIEMPRE ESCRIBE AL FINAL.
    ///w (write): ABRE EL ARCHIVO EN MODO ESCRITURA. SIEMPRE CREA UN ARCHIVO EN BLANCO.
    if(p == nullptr){
        cout<<"ERROR DE APERTURA DE ARCHIVO"<<endl;
        return -1;
    }
    ///GUARDO INFORMACION EN MI ARCHIVO
    obj.setNombreApellido("PISO EL NOMBRE");
    while(fread(&obj, sizeof obj, 1, p)==1){
        obj.Mostrar();
        cout<<"====================="<<endl;
    }
//    fwrite(&obj, sizeof obj, 1, p);
    /**
    Primer argumento: la dirección de memoria donde está la información que quiero copiar en mi archivo.
    Segundo argumento: la cantidad de bytes que quiero copiar a mi archivo.
    Tercer argumento: la cantidad de registros que quiero copiar en mi archivo.
    Cuarto argumento: el vínculo con mi archivo (puntero FILE).
    */
    //fread(&obj, sizeof obj, 1, p);
    /**
    Primer argumento: la dirección de memoria a donde quiero copiar la información de mi archivo.
    Segundo argumento: la cantidad de bytes que quiero leer de mi archivo.
    Tercer argumento: la cantidad de registros que quiero leer de mi archivo.
    Cuarto argumento: el vínculo con mi archivo (puntero FILE).
    */
    ///CIERRO EL VINCULO CON MI ARCHIVO
    fclose(p);
    return 0;
}
