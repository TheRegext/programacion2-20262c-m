///Fecha:
///Autor:
///Comentario:

#include <iostream>


using namespace std;

void cargarVector(int v[],int tam=12);
void mostrarVector(int *v,int tam);

void cargarVector(char *pChar,int tam);
void mostrarVector(char *pChar,int tam);

///SOBRECARGA DE FUNCIONES: puedo tener funciones distintas con el mismo nombre.
///Tienen que diferenciarse en los parámetros que reciben

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
    ///
    char *palabra;
    palabra=new char[20];
    cout<<endl<<"INGRESAR UNA PALABRA ";
    cargarVector(palabra,20);
    mostrarVector(palabra,20);
    delete []palabra;

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


void cargarVector(char *pChar,int tam){
    cin>>pChar;

}

void mostrarVector(char *pChar,int tam){
    cout<<pChar;
}
