#ifndef RESOLUCION_H_INCLUDED
#define RESOLUCION_H_INCLUDED


class Resolucion{

public:
    void punto3(Prestamo *vP);
    void punto4(Prestamo *vP);
    void punto5(Libro *vL, Socio *vS, Prestamo *vP);
    void punto6(Libro *vL, Socio *vS, Prestamo *vP, int cantPrestamos);
    void punto3_sin_orden(Prestamo *vP, Socio *vS);
    int buscarPosicionSocio(int IdSocio,Socio *vS);


};


#endif // RESOLUCION_H_INCLUDED
