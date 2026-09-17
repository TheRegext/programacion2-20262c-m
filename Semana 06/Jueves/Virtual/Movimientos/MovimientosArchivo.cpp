#include <iostream>
#include "MovimientosArchivo.h"
using namespace std;

MovimientosArchivo::MovimientosArchivo(std::string fileName)
{
  _fileName = fileName;
}

int MovimientosArchivo::getCantidadRegistros()
{
  FILE  *pFile = nullptr;
  int cant;
  pFile = fopen(_fileName.c_str(),"rb");

  if(pFile == nullptr)
  {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);

  cant = ftell(pFile) / sizeof(Movimiento);

  fclose(pFile);

  return cant;
}

void MovimientosArchivo::agrear(Movimiento reg)
{
  FILE  *pFile = nullptr;

  pFile = fopen(_fileName.c_str(),"ab");

  if(pFile == nullptr)
  {
    cout<< "No se encontro el archivo"<<endl;
    return;
  }

  fwrite(&reg, sizeof (Movimiento), 1, pFile);

  fclose(pFile);
}

void MovimientosArchivo::leerTodos(Movimiento mov[], int cant)
{
  FILE  *pFile = nullptr;
  pFile = fopen(_fileName.c_str(),"rb");

  if(pFile == nullptr)
  {
    cout<< "No se encontro el archivo"<<endl;
    return;
  }

  fread(mov, sizeof(Movimiento), cant, pFile);

  fclose(pFile);
}
