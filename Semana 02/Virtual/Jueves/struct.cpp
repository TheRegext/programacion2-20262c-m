///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

struct Fecha{
    int dia, mes, anio;

};

int main(){
    ///int simple, compuesto[3], *punteroEntero;
    Fecha unaSola, varias[5],*punteroFecha;
    cin>>unaSola.dia;
    cin>>unaSola.mes;
    cin>>unaSola.anio;
    ///unaSola.anio=2026
    cout<<unaSola.dia<<"/"<<unaSola.mes<<"/"<<unaSola.anio<<endl;

	system("pause");
	return 0;

}
