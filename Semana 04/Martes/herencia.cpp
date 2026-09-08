///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

using namespace std;

/// clase que se usa por composición en Persona
class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha(int d=0, int m=0, int a=0);
    int getDia();
    int getMes();
    int getAnio();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    void cargar();
    void mostrar();

    bool operator==(const Fecha &aux);

};
int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}
void Fecha::setDia(int dia){
    _dia=dia;
}
void Fecha::setMes(int mes){
    _mes=mes;
}
void Fecha::setAnio(int anio){
    _anio=anio;
}
void Fecha::cargar(){
    cout<<"DIA ";
    cin>>_dia;
    cout<<"MES ";
    cin>>_mes;
    cout<<"ANIO ";
    cin>>_anio;
}

void Fecha::mostrar(){
    ///DEBEN IMPLEMENTAR ALUMNOS
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}

Fecha::Fecha(int d, int m, int a){
    _dia=d;
    _mes=m;
    _anio=a;
}

bool Fecha::operator==(const Fecha &aux){
    if(_dia!=aux._dia)return false;
    if(_mes!=aux._mes)return false;
    if(_anio!=aux._anio)return false;
    return true;
}

///

class Persona{///clase base
protected:
    int DNI;
    char nombre[25];
    char apellido[25];
    Fecha fechaNacimiento;
public:
    void Cargar();
    void Mostrar();
    ///gets()
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}

    void setDNI(int d){DNI=d;}
    void setNombre(const char *valor){strcpy(nombre,valor);}
    void setApellido(const char *valor){strcpy(apellido,valor);}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
};

void Persona::Cargar(){
    cout<<"DNI ";
    cin>>DNI;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.cargar();

}
void Persona::Mostrar(){
    cout<<"DNI "<<DNI<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.mostrar();
    cout<<endl;
}


///Cuando se hereda se puede hacer de manera pública o privada
///class Alumno:Persona{///por defecto se hereda de manera privada
class Alumno:public Persona{
private:
    int legajo;
public:
    void setLegajo(int l){legajo=l;}
    int getLegajo(){return legajo;}
    void _setApellido(const char *a){strcpy(apellido,a);}
    void Mostrar();
    void Cargar();
};

void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>legajo;
    Persona::Cargar();
}

void Alumno::Mostrar(){
    cout<<"LEGAJO ";
    cout<<legajo<<endl;
    Persona::Mostrar();
}

int main(){
    Alumno obj;
    //obj.Cargar();
    //obj.Mostrar();
    obj._setApellido("KLOSTER");
    obj.Mostrar();
	system("pause");
	return 0;
}
