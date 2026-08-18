#include <iostream>

using namespace std;

void cargarVector(int vec[], int tam);
void mostrarVector(int vec[], int tam=5);
void mostrarVector(float vec[], int tam=5){cout<<"Muestro el vector float"<<endl;}
//void mostrarVector(int vec[]);
void funcion(int num, int num2);
void funcion2(int &refe);
void mostrarMatriz(int mat[][3], int filas, int col);

/**
HACER UNA FUNCION QUE ME PERMITA CARGAR VALORES POSITIVOS EN MI VECTOR.
SI NO SE CUMPLE ESA CONDICION, SE DEBERA GUARDAR UN CERO.
*/

int main()
{
    int matriz[15][3]{1,2,3,4,5,
                    6,7,8,9,10};
    mostrarMatriz(matriz, 15, 3);
    return 0;
    const int tam = 50;
    float vect[tam]{10, 20, 30, 40, 50};
    //cargarVector(vect, tam);
//    cout<<"*vect: "<<*vect<<endl;
//    cout<<"&vect[0]: "<<&vect[0]<<endl;
//    cout<<"*(vect + 2): "<<*(vect+2)<<endl;
//    cout<<"&vect[1]: "<<&vect[1]<<endl;
    mostrarVector(vect);
    return 0;
    cout<<vect<<endl;
    int entero=10;
    funcion2(entero);
    cout<<"ENTERO: "<<entero<<endl;
    int *valor;
    int **puntero;
    puntero = &valor;
    valor = &entero;
    cout<<valor<<endl;
    return 0;
    funcion(1, 5);
    return 0;
}

void mostrarMatriz(int mat[][3], int filas, int col){
    for(int i=0; i<filas; i++){
        for(int j=0; j<col; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void cargarVector(int vec[], int tam){
    for(int i=0; i<tam; i++){
            vec[i] = i+1;
//        cout<<"INGRESE UN VALOR PARA EL ELEMENTO "<<i<<": ";
//        int valor;
        //cin>>valor;
//        if(valor>0){
//            vec[i] = valor;
//        }else{
//            vec[i] = 0;
//        }
    }
}

void mostrarVector(int vec[], int tam){
    for(int i=0; i<tam; i++){
        cout<<i<<": ";
        cout<<vec[i]<<endl;
    }
}

//void mostrarVector(int vec[]){
//    for(int i=0; i<5; i++){
//        cout<<i<<": ";
//        cout<<vec[i]<<endl;
//    }
//}

void funcion(int num, int num2){
    int resultado;
    resultado = num + num2;
    cout<<resultado<<endl;
}


void funcion2(int &refe){
    refe *= -1;
}
