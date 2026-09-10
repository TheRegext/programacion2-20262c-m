#include <iostream>

using namespace std;

enum Materias{
    PROGRAMACION,
    MATEMATICA,
    ARSO,
    LEGISLACION,
    BASE_DE_DATOS
};

enum Meses{
    ENERO=1,
    MARZO,
    FEBRERO,
    ABRIL,
    MAYO,
    JUNIO,
    JULIO,
    AGOSTO,
    SEPTIEMBRE,
    OCTUBRE,
    NOVIEMBRE,
    DICIEMBRE
};

int main()
{
    string Materias[5]{"Programacion", "Matematica", "ArSO", "Legislacion", "Base de datos"};
    cout<<Materias[ARSO]<<endl;
    return 0;
}
