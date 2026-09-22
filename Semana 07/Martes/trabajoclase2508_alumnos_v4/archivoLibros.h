#ifndef ARCHIVOLIBROS_H_INCLUDED
#define ARCHIVOLIBROS_H_INCLUDED


class ArchivoLibros{
private:
    char _nombreArchivo[15];
public:
    ArchivoLibros(const char *nombreArchivo="libros.dat");
    bool agregarRegistroLibro();
    bool mostrarRegistroLibro();
    int buscarRegistroLibro(int isbn);
};



#endif // ARCHIVOLIBROS_H_INCLUDED
