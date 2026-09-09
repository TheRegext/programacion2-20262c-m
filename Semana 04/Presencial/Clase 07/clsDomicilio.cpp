#include <iostream>
#include "clsDomicilio.h"
#include "cargarCadena.h"

using namespace std;

void Domicilio::Cargar(){
    cout<<"INGRESE EL NOMBRE DE LA CALLE: ";
    cargarCadena(calle, 30);
    cout<<"INGRESE LA ALTURA: ";
    cin>>altura;
    cout<<"INGRESE LA LOCALIDAD: ";
    cargarCadena(localidad, 30);
    cout<<"INGRESE LA PROVINCIA: ";
    cargarCadena(provincia,30);
    cout<<"INGRESE EL CODIGO POSTAL: ";
    cin>>codigoPostal;
}
void Domicilio::Mostrar(){
    cout<<"NOMBRE DE LA CALLE: "<<calle<<endl;
    cout<<"ALTURA: "<<altura<<endl;
    cout<<"LOCALIDAD: "<<localidad<<endl;
    cout<<"PROVINCIA: "<<provincia<<endl;
    cout<<"CODIGO POSTAL: "<<codigoPostal<<endl;
}
