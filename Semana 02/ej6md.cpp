///Fecha: 18-108-2026
///Autor:DEKS
///Comentario:muestra TODOS LOS PARES, no los distintos.

#include <iostream>

using namespace std;

void cargarVector(int v[],int tam);

int *copiarSoloPares(int *v,int tam);

void mostrarVector(int *v, int tam);

int contarPares(int *v,int tam);

void copiarParesEnVector(int *vOrigen,int tam,int *vDestino);

int main(){
    int vec[10];
    int *vPares;
    cout<<"INGRESAR 10 NUMEROS ";


    cargarVector(vec,10);
    cout<<endl;
    system("pause");
    system("cls");

    int cant=contarPares(vec,10);

    if(cant==0){
        cout<<"NO HAY PARES"<<endl;
        return 0;
    }

    vPares=copiarSoloPares(vec,10);

    if(vPares==nullptr){
        cout<<"NO SE PUDO ASIGNAR MEMORIA"<<endl;
        return -1;
    }


    mostrarVector(vPares, cant);

    delete []vPares;
	system("pause");
	return 0;

}

void cargarVector(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
    }
}

int *copiarSoloPares(int *v,int tam){
    int *vNuevo;
    int cantPares=contarPares(v,tam);
    if(cantPares==0){
        return nullptr;
    }
    vNuevo=new int[cantPares];
    if(vNuevo==nullptr)return nullptr;
    copiarParesEnVector(v,tam,vNuevo);
    return vNuevo;
}

void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}


int contarPares(int *v,int tam){
    int i,cantPares=0;
    for(i=0;i<tam;i++){
        if(v[i]%2==0){
            cantPares++;
        }
    }
    return cantPares;
}

void copiarParesEnVector(int *vOrigen,int tam,int *vDestino){
    int i, j=0;
    for(i=0;i<tam;i++){
        if(vOrigen[i]%2==0){
            vDestino[j]=vOrigen[i];
            j++;
        }
    }
}
