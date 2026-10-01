#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

class Informes{

public:
    void punto1();
    void punto5();
    void punto7();
    void punto8();
    void ordenarLibrosPorNombre(Libro *vL, int cantReg);
    void ordenarVectorEnteros(int *v, int cant);
    void mostrarVectorEnteros(int *v, int cant);
    int buscarIDenVector(int *vIDSocios,int IdSocio, int cant);
};

#endif // INFORMES_H_INCLUDED
