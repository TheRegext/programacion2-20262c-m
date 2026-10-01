# include<iostream>
# include<cstring>

using namespace std;
# include "Socio.h"
# include "archivoSocios.h"
# include "funcionesGlobales.h"


bool ArchivoSocios::agregarRegistro()
{
    ///declaración de variables
    FILE *pSocio;
    Socio reg;
    ///apertura del archivo
    pSocio=fopen(_nombreArchivo, "ab");
    ///chequear si se pudo abrir
    if(pSocio==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Cargar en memoria el registro de Socio
    int id;
    cout<<"INGRESAR EL VALOR DE ID ";
    cin>>id;
    int pos=buscarRegistro(id);
    ///pos debe ser ??? para aceptarlo como nuevo _isbn
    if(pos==-1)
    {
        reg.cargar(id);
        ///Escribir en el disco el registro
        int escribio=fwrite(&reg,sizeof reg, 1, pSocio);///Si pudo escribir devuelve la cantidad de registros
        ///Cerrrar el archivo                           ///Si no pudo escribir devuelve 0
        fclose(pSocio);
        return escribio;
    }
    else
    {
        cout<<"YA EXISTE UN SOCIO CON ESE Id"<<endl<<endl;
    }
    return false;
}

bool ArchivoSocios::mostrarRegistro(int estado)
{
    /// parametro= 0 muestra todos
    /// parametro= 1 muestra solo los activos
    /// parametro= 2 muestra solo los inactivos


    ///declaración de variables
    FILE *pSocio;
    Socio reg;
    ///apertura del archivo
    pSocio=fopen(_nombreArchivo, "rb");
    ///chequear si se pudo abrir
    if(pSocio==nullptr)
    {
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    ///Leer del disco el/los registro/s mientras haya registros en el archivo
    while(fread(&reg,sizeof reg, 1, pSocio)==1)
    {
        ///Si pudo leer devuelve la cantidad de registros
        ///mostrar el registro
        if(estado == 0)
        {

            reg.mostrar();

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

    fclose(pSocio);
    return true;
}

///Devuelve la posición que ocupa el Socio con el _isbn igual a isbn
///Si no lo encuentra devuelve -1
///Si no pudo abrir el archivo devuelve -2

int ArchivoSocios::buscarRegistro(int id)
{
    FILE *pSocio;
    Socio reg;
    int pos=0;
    pSocio=fopen(_nombreArchivo, "rb");
    if(pSocio==nullptr)
    {
        return -2;
    }
    while(fread(&reg, sizeof reg, 1, pSocio)==1)
    {
        if(reg.getId()==id && reg.getEstado())
        {
            fclose(pSocio);
            return pos;
        }
        pos++;
    }
    fclose(pSocio);
    return -1;
}

ArchivoSocios::ArchivoSocios(const char *nombreArchivo)
{
    strcpy(_nombreArchivo,nombreArchivo);
}

Socio ArchivoSocios::leerRegistro(int pos)
{
    FILE *pSocio;
    Socio reg;
    reg.setId(-1);
    pSocio=fopen(_nombreArchivo, "rb");
    if(pSocio==nullptr)
    {
        return reg;
    }
    fseek(pSocio,pos*sizeof(Socio),0);  ///SEEK_SET->0 DESDE EL PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL ///SEEK_END->2 DESDE EL FINAL
    fread(&reg,sizeof(Socio),1,pSocio);
    fclose(pSocio);
    return reg;
}


bool ArchivoSocios::sobreEscribirRegistro(Socio reg,int pos)
{
    FILE *pSocio;
    pSocio=fopen(_nombreArchivo, "rb+");///+ le agrega al modo lo que no tiene
    if(pSocio==nullptr)
    {
        return false;
    }
    fseek(pSocio,pos*sizeof(Socio),0);  ///SEEK_SET->0 DESDE EL PRINCIPIO; SEEK_CUR->1 POSICION ACTUAL ///SEEK_END->2 DESDE EL FINAL
    bool escribio=fwrite(&reg,sizeof(Socio),1,pSocio);
    fclose(pSocio);
    return escribio;
}

int ArchivoSocios::cantidadRegistros()
{
    FILE *pSocio;
    pSocio = fopen(_nombreArchivo, "rb");

    if(pSocio == nullptr)
    {
        return -1;
    }
    fseek(pSocio, 0,SEEK_END);  // movemos el puntero al final del archivo
    int totalBytes = ftell(pSocio); // se le asigna a la variable el peso total del archivo
    int tamanioRegistro = totalBytes/sizeof(Socio);
    fclose(pSocio);
    return tamanioRegistro;
}


