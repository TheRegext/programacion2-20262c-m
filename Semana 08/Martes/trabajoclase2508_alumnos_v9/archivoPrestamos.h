#ifndef ARCHIVOPRESTAMOS_H_INCLUDED
#define ARCHIVOPRESTAMOS_H_INCLUDED

class ArchivoPrestamos{
private:
    char _nombreArchivo[15];
public:
    ArchivoPrestamos(const char *nombreArchivo="prestamos.dat");
    bool agregarRegistro();
    bool mostrarRegistro(int estado = 0);
    int buscarRegistro(int id);
    Prestamo leerRegistro(int pos);
    bool sobreEscribirRegistro(Prestamo reg,int pos);
    int cantidadRegistros();
    ///modificarRegistroLibros()
};

#endif // ARCHIVOPRESTAMOS_H_INCLUDED
