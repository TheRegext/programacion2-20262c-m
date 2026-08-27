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
    ~clsCadena();
    void Mostrar();

};

clsCadena::clsCadena(const char *cad){
    tam=strlen(cad)+1;
    if(tam==0)return;
    pCadena=new char[tam];
    if(pCadena==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        exit(1);
    }
    strcpy(pCadena,cad);
    pCadena[tam-1]='\0';
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

int main(){
    clsCadena palabra("hola a todos los participantes!!");
    palabra.Mostrar();
	system("pause");
	return 0;
}
