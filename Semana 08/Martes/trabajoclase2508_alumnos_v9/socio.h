#pragma once
#include "fecha.h"

using namespace std;

class Socio
{

///  DNI, el nombre, el apellido, un número de teléfono, un email y la fecha de nacimiento
private:
    int _dni;
    char _apellido[25];
    int _numTelefono;
    char _nombre[25];
    char _email[40];
    Fecha _fechaNacimiento;
    ///int diaNacimiento, mesNacimiento, anioNacimiento;
    int _id;
    bool _estado;


public:
    void setDni(int dni);
    int getDni();
    ///
    void setDiaNacimiento(int d);
    ///
    void setApellido(const char*apellido);
    const char* getApellido();
    void setNumTelefono(int numTelefono);
    int getNumTelefono();
    void setNombre(const char* nombre);
    const char* getNombre();
    void setEmail(const char* email);
    const char* getEmail();
    void setFechaNacimiento(Fecha fechaNacimiento);
    Fecha getFechaNacimiento();
    void setId(int id);
    int getId();

    void cargar(int id=0);
    void mostrar();

    int getMesNacimiento();

    bool getEstado();
    void setEstado(bool _estado);
};
