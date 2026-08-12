///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring> ///string.h

using namespace std;

///NOMBRE DE UN VECTOR: es un puntero constante que contiene la dirección
///de inicio del vector

///PUNTERO: es una variable que almacena direcciones.

///valores de retorno de strcmp()
///0: cuando son iguales
///-1: ave,zorro  cuando la palabra primera está más cerca del inicio del diccionario que la segunda
///1: zorro, ave

int compararCadenas(char *primera, char *segunda);

int main(){
    int valor, &referencia=valor;
    char palabra[20], aux[20],*pCadena;
    //SALUDOS
    cin>>palabra;
    cout<<palabra<<endl;
    /*palabra[4]='\0';
    cout<<palabra<<endl;
    pCadena=palabra;
    cout<<pCadena<<endl;*/

    strcpy(aux,"zorro");///no puedo hacer aux=palabra;
    cout<<aux<<endl;
	//int valorDevuelto=strcmp(palabra,aux);
	int valorDevuelto=compararCadenas(palabra,aux);
	cout<<"VALOR QUE DEVUELVE strcmp() "<<valorDevuelto<<endl;
	cout<<strlen(palabra)<<endl;
	system("pause");
	return 0;

}

int compararCadenas(char *primera, char *segunda){
    int i=0;
    while(primera[i]!='\0' && segunda[i]!='\0'){
        if(primera[i]>segunda[i]){
            return 1;
        }
        else{
            if(primera[i]<segunda[i]){
                return -1;
            }
        }
        i++;
    }
    return 0;
}
