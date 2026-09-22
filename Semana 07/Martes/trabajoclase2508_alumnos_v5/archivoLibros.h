#ifndef ARCHIVOLIBROS_H_INCLUDED
#define ARCHIVOLIBROS_H_INCLUDED

///Agregar un método que devuelva la cantidad de registros del archivo.
///Ver la aplicación de ese método en el resto de los métodos, o funciones globales realizadas.

class ArchivoLibros{
private:
    char _nombreArchivo[15];
public:
    ArchivoLibros(const char *nombreArchivo="libros.dat");
    bool agregarRegistroLibro();
    bool mostrarRegistroLibro();
    int buscarRegistroLibro(int isbn);
    Libro leerRegistro(int pos);
    bool sobreEscribirRegistro(Libro reg,int pos);
    ///modificarRegistroLibros()
};



#endif // ARCHIVOLIBROS_H_INCLUDED
