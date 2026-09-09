#ifndef CLSDOMICILIO_H_INCLUDED
#define CLSDOMICILIO_H_INCLUDED

class Domicilio{
    private:
        char calle[30];
        int altura;
        char localidad[30];
        char provincia[30];
        char codigoPostal[6];
    public:
        ///SETTERS Y GETTERS
        void Cargar();
        void Mostrar();
        ///AGREGAR CONSTRUCTOR CON VALORES POR DEFECTO
};

#endif // CLSDOMICILIO_H_INCLUDED
