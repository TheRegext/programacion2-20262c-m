# include<iostream>
# include<cstring>

using namespace std;
# include "Prestamo.h"
# include "archivoPrestamos.h"
# include "funcionesGlobales.h"
# include "archivoSocios.h"

bool ArchivoPrestamos::agregarRegistro()
{
    ///declaración de variables
    FILE *pPrestamo;
    Prestamo reg;
    ///apertura del archivo
    pPrestamo=fopen(_nombreArchivo, "ab");
    ///chequear si se pudo abrir
    if(pPrestamo==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Cargar en memoria el registro de Prestamo
    int id;
    cout<<"INGRESAR EL VALOR DE ID DE SOCIO";
    cin>>id;

    ArchivoSocios arSocio;
    int pos=arSocio.buscarRegistro(id);

    if(pos>=0)
    {
        reg.cargar(id);
        ///Escribir en el disco el registro
        int escribio=fwrite(&reg,sizeof reg, 1, pPrestamo);///Si pudo escribir devuelve la cantidad de registros
        ///Cerrrar el archivo                           ///Si no pudo escribir devuelve 0
        fclose(pPrestamo);
        return escribio;
    }
    else
    {
        cout<<"NO EXISTE UN SOCIO CON ESE ID"<<endl<<endl;
    }
    return false;
}

bool ArchivoPrestamos::mostrarRegistro(int estado)
{
    /// parametro= 0 muestra todos
    /// parametro= 1 muestra solo los activos
    /// parametro= 2 muestra solo los inactivos


    ///declaración de variables
    FILE *pPrestamo;
    Prestamo reg;
    ///apertura del archivo
    pPrestamo=fopen(_nombreArchivo, "rb");
    ///chequear si se pudo abrir
    if(pPrestamo==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Leer del disco el/los registro/s mientras haya registros en el archivo
    while(fread(&reg,sizeof reg, 1, pPrestamo)==1)
    {
        ///Si pudo leer devuelve la cantidad de registros
        ///mostrar el registro
        if(estado == 0)
        {

            reg.mostrar(1);

        }
        else if(estado == 1)
        {
            if(reg.getEstado() )
            {
                reg.mostrar();
            }
        }
        else if(estado == 2)
        {
            if(!reg.getEstado() )
            {
                reg.mostrar();
            }
        }
        else return false;
    }

    fclose(pPrestamo);
    return true;
}

///Devuelve la posición que ocupa el Prestamo con el _isbn igual a isbn
///Si no lo encuentra devuelve -1
///Si no pudo abrir el archivo devuelve -2

int ArchivoPrestamos::buscarRegistro(int id)
{
    FILE *pPrestamo;
    Prestamo reg;
    int pos=0;
    pPrestamo=fopen(_nombreArchivo, "rb");
    if(pPrestamo==nullptr)
    {
        return -2;
    }
    while(fread(&reg, sizeof reg, 1, pPrestamo)==1)
    {
        if(reg.getIdSocio()==id && reg.getEstado())
        {
            fclose(pPrestamo);
            return pos;
        }
        pos++;
    }
    fclose(pPrestamo);
    return -1;
}

ArchivoPrestamos::ArchivoPrestamos(const char *nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}

Prestamo ArchivoPrestamos::leerRegistro(int pos)
{
    FILE *pPrestamo;
    Prestamo reg;
    reg.setIdSocio(-1);
    pPrestamo=fopen(_nombreArchivo, "rb");
    if(pPrestamo==nullptr)
    {
        return reg;
    }
    fseek(pPrestamo,pos*sizeof(Prestamo),0);  ///SEEK_SET->0 DESDE EL PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL ///SEEK_END->2 DESDE EL FINAL
    fread(&reg,sizeof(Prestamo),1,pPrestamo);
    fclose(pPrestamo);
    return reg;
}


bool ArchivoPrestamos::sobreEscribirRegistro(Prestamo reg,int pos)
{
    FILE *pPrestamo;
    pPrestamo=fopen(_nombreArchivo, "rb+");///+ le agrega al modo lo que no tiene
    if(pPrestamo==nullptr)
    {
        return false;
    }
    fseek(pPrestamo,pos*sizeof(Prestamo),0);  ///SEEK_SET->0 DESDE EL PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL ///SEEK_END->2 DESDE EL FINAL
    bool escribio=fwrite(&reg,sizeof(Prestamo),1,pPrestamo);
    fclose(pPrestamo);
    return escribio;
}

int ArchivoPrestamos::cantidadRegistros()
{
    FILE *pPrestamo;
    pPrestamo = fopen(_nombreArchivo, "rb");

    if(pPrestamo == nullptr)
    {
        return -1;
    }
    fseek(pPrestamo, 0,SEEK_END);  // movemos el puntero al final del archivo
    int totalBytes = ftell(pPrestamo); // se le asigna a la variable el peso total del archivo
    int tamanioRegistro = totalBytes/sizeof(Prestamo);
    fclose(pPrestamo);
    return tamanioRegistro;
}


