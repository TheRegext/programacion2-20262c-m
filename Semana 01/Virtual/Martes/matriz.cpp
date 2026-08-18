///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

void cargarMatriz(int mat[5][3],int filas, int columnas);
void mostrarMatriz(int mat[][3],int filas, int columnas);

int main(){
    int mat[5][3];
    cargarMatriz(mat,5,3);
    mostrarMatriz(mat,5,3);
    cout<<endl;

	system("pause");
	return 0;

}


void cargarMatriz(int (*mat)[3],int filas, int columnas){
    int i, j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            mat[i][j]=i+j;
        }
    }

}

void mostrarMatriz(int mat[5][3],int filas, int columnas){
    int i, j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}
