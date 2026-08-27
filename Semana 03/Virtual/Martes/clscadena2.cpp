///Ejercicio: hacer una clase de nombre clsCadena, que permita trabajar con cadenas de caracteres.
///Cada objeto clsCadena debe ajustar su tamaño al estrictamente necesario.
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>///string.h contiene las funciones para trabajar con vectores de char

using namespace std;


class clsCadena{
private:
    int tam;
    char *pCadena;
public:
    clsCadena(const char *cad);
    clsCadena(int tam);
    ~clsCadena();
    void Mostrar();
    void MostrarDireccion();
    ///SOBRECARGA DEL OPERADOR ==
    bool operator==(const clsCadena &aux);

};

clsCadena::clsCadena(const char *cad){
    this->tam=strlen(cad)+1;
    if(tam==0)return;
    pCadena=new char[tam];
    if(pCadena==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        exit(1);
    }
    strcpy(pCadena,cad);
    pCadena[tam-1]='\0';
}
///this es un puntero que existe SOLO dentro de la clase
///y que contiene la dirección del objeto que llama al método.
///Se dice que es un puntero oculto

void clsCadena::MostrarDireccion(){
    cout<<this<<endl;
}


clsCadena::clsCadena(int _tam){
    this->tam=_tam+1;
    if(tam==0)return;
    pCadena=new char[this->tam];
    if(pCadena==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        exit(1);
    }
    for(int i=0;i<this->tam;i++) pCadena[i]='0';
    pCadena[this->tam-1]='\0';
}

clsCadena::~clsCadena(){
    delete []pCadena;
}

void clsCadena::Mostrar(){
    cout<<pCadena<<endl;
}

///strcpy("chau","hola")->-1
///strcpy("chau","chau")->0 ambas cadenas son iguales
///strcpy("hola", "chau")->1

bool clsCadena::operator==(const clsCadena &aux){
    if(strcmp(pCadena,aux.pCadena)==0) return true;
    return false;
}

int main(){
    clsCadena palabra("hola a todos los participantes!!");
    clsCadena obj(5);
    //palabra.Mostrar();
    //obj.Mostrar();
    //cout<<"&obj "<<&obj<<endl;
    //obj.MostrarDireccion();
    //cout<<endl;
    //palabra.MostrarDireccion();
    if(palabra.operator==(obj)){

      // palabra==obj){
        cout<<"CADENAS IGUALES "<<endl;
    }
    else{
        cout<<"CADENAS DISTINTAS "<<endl;
    }
    cout<<endl;
	system("pause");
	return 0;
}
