///Fecha:
///Autor:
///Comentario:primera clase de Programación Orientada a Objetos

#include <iostream>

using namespace std;
///Clase: es un molde donde se definen las propiedades y el
///comportamiento que tendrán los objetos de esa clase.

///Objetos: variables (instancias) de una clase.

///Especificadores de acceso:indican que es visible de una la clase

///public:es visible tanto dentro como fuera de la clase.
///private: sólo es visible dentro de la clase

///Encapsulamiento: el objeto no permite el acceso directo a sus propiedades.
///Para acceder a ellas es necesario utilizar métodos (funciones de la clase)
///definidos dentro de esa clase


class Fecha{
    private:///propiedades o variables de la clase
       int dia, mes, anio;
    public:///métodos o funciones de la clase->comportamiento
        Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
        }
        void Cargar(){
            cout<<"INGRESAR EL DIA ";
            cin>>dia;
            cout<<"INGRESAR EL MES ";
            cin>>mes;
            cout<<"INGRESAR EL ANIO ";
            cin>>anio;
        }
        void Mostrar();
        ///sets()->puedo establecer validaciones para cada propiedad
        void setDia(int d){dia=d;}///habría que validar!!!
        void setMes(int d){mes=d;}///habría que validar!!!
        void setAnio(int d){anio=d;}///habría que validar!!!
        ///gets()->permiten que el mundo externo conozca el valor de la propiedad
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};

void Fecha::Mostrar(){
            cout<<"DIA "<<dia<<endl;
            cout<<"MES "<<mes<<endl;
            cout<<"ANIO "<<anio<<endl;
}


int main(){
    Fecha unaSola(20,8,2026), aux;

    ///unaSola.dia=5; ///NO ES ACCESIBLE FUERA DE LA CLASE
    ///unaSola.Cargar();
    unaSola.Mostrar();
    cout<<endl;
    aux.Mostrar();
    cout<<endl;

    /*unaSola.setAnio(2026);

    if(unaSola.getAnio()==2026){
        cout<<"Anio actual"<<endl;
    }*/
	system("pause");
	return 0;

}
