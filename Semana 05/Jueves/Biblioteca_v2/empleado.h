#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

class Empleado: public Persona{
private:
    float _sueldo
public:
    void setSueldo(float sueldo);
    float getSueldo();
    void cargar();
    void mostrar();

};


#endif // EMPLEADO_H_INCLUDED
