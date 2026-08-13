///Fecha:
///Autor:
///Comentario:

#include <iostream>


using namespace std;

void cargarVector(int v[],int tam=12);
void mostrarVector(int *v,int tam);


int main(){

    int tam, *pDinamico;
    cout<<"INGRESAR LA CANTIDAD DE ELEMENTOS QUE NECESITA PARA EL VECTOR ";
    cin>>tam;

    pDinamico=new int[tam];
    if(pDinamico==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return -1;
    }
    cargarVector(pDinamico,tam);
    mostrarVector(pDinamico,tam);
    delete []pDinamico;
    cout<<endl;
	system("pause");
	return 0;

}


void cargarVector(int *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        *(v+i)=i+1;///v[i]=i+1;
    }

}

void mostrarVector(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}


