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
    ///sobrecarga
    bool operator==(const Fecha &aux);
    bool operator==(const char *_mes);
    bool operator>(const Fecha &aux);
};

///métodos de Fecha
void Fecha::setDia(int d){
        if(d>=1 && d<=31) dia=d;
        else dia=0;
}

void Fecha::Mostrar(){
        cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;
}

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

///fin métodos de fecha

class Alumno{
private:
    int legajo;
    char nombre[25];
    int codigoCarrera;
    ///Domicilio?????
    Fecha fechaNacimiento;
public:
    ///Alumno(int _legajo, const char *_nombre, int _codigoCarrera, Fecha _fechaNacimiento);
    Alumno(int _legajo, const char *_nombre, int _codigoCarrera, int _dia, int _mes, int _anio);
    void setLegajo(int l){legajo=l;}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setFechaNacimiento(Fecha fn){fechaNacimiento=fn;}

    int getLegajo(){return legajo;}
    const char *getNombre(){return nombre;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}

    void Mostrar();

};

/*Alumno::Alumno(int _legajo, const char *_nombre, int _codigoCarrera, Fecha _fechaNacimiento){
    legajo=_legajo;
    strcpy(nombre,_nombre);
    codigoCarrera=_codigoCarrera;
    fechaNacimiento=_fechaNacimiento;
}*/

/*Alumno::Alumno(int _legajo, const char *_nombre, int _codigoCarrera, int _dia, int _mes, int _anio){
    legajo=_legajo;
    strcpy(nombre,_nombre);
    codigoCarrera=_codigoCarrera;
    fechaNacimiento.setDia(_dia);
    fechaNacimiento.setMes(_mes);
    fechaNacimiento.setAnio(_anio);
}
*/
Alumno::Alumno(int _legajo, const char *_nombre, int _codigoCarrera, int _dia, int _mes, int _anio)
    :fechaNacimiento(_dia, _mes,_anio)
    {
    legajo=_legajo;
    strcpy(nombre,_nombre);
    codigoCarrera=_codigoCarrera;
    /*fechaNacimiento.setDia(_dia);
    fechaNacimiento.setMes(_mes);
    fechaNacimiento.setAnio(_anio);*/
}

void Alumno::Mostrar(){
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    fechaNacimiento.Mostrar();
}

int main(){
    //Fecha nacimiento(15,12,2000);
    //Alumno obj(1234,"ANA PEREZ",3,nacimiento);
    Alumno obj(1234,"ANA PEREZ",3,15,12,2000);
    ///obj.Mostrar();
    cout<<obj.getFechaNacimiento().getAnio()<<endl;
	system("pause");
	return 0;

}



