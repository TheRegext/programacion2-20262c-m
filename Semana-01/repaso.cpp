///Fecha:
///Autor:
///Comentario:

#include <iostream>

///tipo de paso: valor, referencia y dirección
///EL nombre de un vector es la dirección de memoria del elemento del 0 de ese vector
using namespace std;

///REFERENCIA: es un alias de una variable. Al momento de la declaración lleva un & antes del nombre de la referencia
///prototipos
void cargarVector(int v[],int tam=12);
void mostrarVector(int *v,int tam);
void cambiarValorA10(int *num);

int main(){
    const int MESES=12;
    int meses[12]={0};
    //Al anteponer el & a un nombre de variable se obtiene su dirección
    /*cout<<"meses "<<meses<<endl;
    cout<<"&meses[0] "<<&meses[0]<<endl;
    cout<<"&meses[1] "<<&meses[1]<<endl;
    cout<<"&meses[2] "<<&meses[2]<<endl;
    cout<<"sizeof(int)"<<sizeof(int)<<endl;
    cout<<"sizeof meses"<<sizeof meses<<endl;*/
    cargarVector(meses,6);
    //cout<<MESES<<endl;
    //system("pause");
    mostrarVector(meses,MESES);
    cout<<endl;
	system("pause");
	return 0;

}

void cargarVector(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=i+1;
    }

}

void mostrarVector(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}


void cambiarValor(int *num){
    num=10;
}
