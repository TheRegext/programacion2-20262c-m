#include <iostream>
#include <cstring>
#include "clsEjemplo.h"

void Ejemplo::setCodigo(const char *c){
    strcpy(codigo, c);
}

const char *Ejemplo::getCodigo(){
    return codigo;
}
