#include <iostream>

using namespace std;

int *crearVectorDinamico(int tam);

int main()
{
    cout<<"INGRESE LA CANTIDAD DE ELEMENTOS DEL VECTOR: ";
    int tam;
    cin>>tam;
    int *vec = nullptr;
    vec = crearVectorDinamico(tam);
    for(int i=0;i<tam; i++){
        vec[i] = tam - i;
    }
    for(int i=0;i<tam; i++){
        cout<<vec[i]<<endl;
    }
    system("pause");
//    cargarVector(vec, tam);
//    mostrarVector(vec, tam);
    delete[] vec;
    return 0;
}

int *crearVectorDinamico(int tam){
    int *vec = nullptr;
    if(tam<=0){
        cout<<"NO SE PUEDE PEDIR MEMORIA PARA ESA CANTIDAD DE ELEMENTOS"<<endl;
        return nullptr;
    }
    vec = new int[tam];
    if(vec == nullptr){
        cout<<"ERROR AL ASIGNAR MEMORIA"<<endl;
        return nullptr;
    }
    return vec;
}
