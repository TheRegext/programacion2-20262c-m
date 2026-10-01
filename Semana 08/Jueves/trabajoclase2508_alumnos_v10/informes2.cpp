
# include<iostream>


using namespace std;

# include "informes2.h"
# include "libro.h"
# include "archivoLibros.h"

void Informe2::menuInformes2(){
    int opc;
    while(true){
        system("cls");
        cout<<"***********************INFORMES ADICIONALES***********************"<<endl;
        cout<<"1. MOSTRAR REGISTRO DE LIBRO DE ACUERDO A POSICION QUE SE INGRESA"<<endl;
        //cout<<"2. "<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"OPCION ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: mostrarRegistroPorPosicion();
                    break;
            case 0: return;


        }
        system("pause");
    }



}
void Informe2::mostrarRegistroPorPosicion(){
    FILE *p;
    p=fopen("libros.dat","rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO "<<endl;
        return;
    }
    int posAleer;
    Libro reg;
    cout<<"INGRESAR LA POSICION DEL REGISTRO QUE SE QUIERE LEER ";
    cin>>posAleer;
    fseek(p,posAleer*sizeof(Libro),0);///0,1,2 ///SEEK_SET, SEEK_CUR, SEEK_END
    int leyo=fread(&reg,sizeof(Libro),1,p);
    if(leyo==1){
       reg.mostrar();
    }
    else{
        cout<<"NO HAY REGISTROS EN ESA POSICION "<<endl;
    }

}
