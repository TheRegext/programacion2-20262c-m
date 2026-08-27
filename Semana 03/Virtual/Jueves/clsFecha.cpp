///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

using namespace std;


class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0,int m=0, int a=0);
    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar();

    void setDia(int d);
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void MostrarThis(){cout<<this;}
    ///sobrecarga
    bool operator==(const Fecha &aux);
    bool operator==(const char *_mes);
    ~Fecha(){
        cout<<"SE MURIO EL OBJETO :-("<<endl;
    }
    bool operator>(const Fecha &aux);
};

void Fecha::setDia(int d){
        if(d>=1 && d<=31) dia=d;
        else dia=0;
}

///

void Fecha::Mostrar(){
        cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;
}



///this: es un puntero que contiene la dirección del objeto que llama al método.
///this EXISTE SOLO DENTRO DE LA CLASE, dentro de cada método.
///se dice que es un puntero oculto, poruque no es impresindible hacerlo visible.
///Podemos usarlo cuando nos resuelva algún problema-

Fecha::Fecha(int d,int mes, int a){
    ///dia=d;
    this->setDia(d);
    this->mes=mes;
    anio=a;
}

bool Fecha::operator==(const Fecha &aux){
    if(dia!=aux.dia)return false;
    if(mes!=aux.mes)return false;
    if(anio!=aux.anio)return false;
    return true;
}

bool Fecha::operator==(const char *_mes){
    string vMeses[12]={"ENERO", "FEBRERO","MARZO"};
    if(vMeses[mes-1]==_mes) return true;
    return false;

}

bool Fecha::operator>(const Fecha &aux){///que la fecha que llama sea más nueva que la recibe
     ///como parámetro
    if(anio>aux.anio)return true;
    if(anio<aux.anio)return false;
    ///los años son iguales
    if(mes>aux.mes)return true;
    if(mes<aux.mes)return false;
    ///año y mes iguales
    if(dia>aux.dia)return true;
    return false;


}
int main(){
    /*Fecha hoy(1,1,1),ayer;

    hoy.Mostrar();
    cout<<endl;

    ayer.Mostrar();
    cout<<endl;

    ayer.setDia(25);
    ayer.setMes(8);
    ayer.setAnio(2026);

    ayer.Mostrar();
    cout<<endl;

    cout<<"&hoy "<<&hoy<<endl;
    hoy.MostrarThis();*/

    Fecha obj,vFecha[5];
    vFecha[2].setDia(4);
    obj.Mostrar();
    cout<<endl;
    obj.setAnio(2026);
    vFecha[0]=obj;
    vFecha[0].Mostrar();
    ///if(obj.operator==(vFecha[0]))
    /*if(obj==vFecha[0]){
        cout<<"FECHAS IGUALES"<<endl;
    }
	obj.setMes(1);
	if(obj=="ENERO"){
        cout<<"LA FECHA ES DE ENERO"<<endl;
	}
	else{
        cout<<"LA FECHA NO ES DE ENERO"<<endl;
	}*/
	if(obj>vFecha[1]){
        cout<<"LA PRIMERA FECHA ES MAS ACTUAL "<<endl;
	}
	else{
        cout<<"LA PRIMERA FECHA NO ES MAS ACTUAL "<<endl;
	}
	system("pause");
	return 0;

}



