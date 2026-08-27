#include <iostream>

using namespace std;


#include "funciones.h"

/*Una empresa que fabrica 200 artículos tiene la siguiente información para cada uno de las ventas del mes anterior:

Código de Artículo (1 a 200)
Día (1 a 31)
Cantidad vendida

Puede haber más de un registro para el mismo artículo.

El lote finaliza con un registro con número de artículo igual a cero.

Se pide determinar e informar:

a) Informar para cada código de artículo la cantidad total vendida en el mes.
b) Informar los días en los que no hubo ventas.
c) Informar los códigos de los artículos cuyas ventas en cantidad son mayores al promedio.


cargarDatosVentas()///tiene que recibir un vector de enteros de 200 para a
///tiene que recibir un vector de enteros de 31 para b
///Ingresar el artículo, el día de la venta y la cantidad,hasta que se ingrese
///un artículo igual a 0
///Para el punto a me conviene usar un vector de 200 de tipo entero, y acumular las cantidades en la carga,
///Para el punto b me conviene usar un vector de 31 de enteros y sumar las cantidades

mostrarPuntoA()///tiene que recibir un vector de enteros de 200 y mostrarlo
///Acumular para cada artículo la cantidad vendida. Son 200 artículos
///identificados con los números del 1 al 200->
///Me conviene usar un vector de 200 de tipo entero, y acumular las cantidades en la carga,
///En esta función recibo el vector y lo muestro

mostrarPuntoB()///tiene que recibir un vector de enteros de 31 con la cantidad vendida cada día
///Para informar días sin ventas, necesito saber la cantidad (puede ser si hizo o no ventas)
///Me conviene usar un vector de 31 de enteros y sumar las cantidades
///También puedo usar un vector booleano, lo inicio en false y le pongo true cuando
///encuentro una venta de ese día

mostrarPuntoC()///recibe el vector del punto a
///Con el vector del punto a, calcular el promedio de ventas y luego comparar cada
///una de las posiciones del vector con el promedio e informar si corresponde
*/

///HACER UN MENU!!!!!!
int main(){
    const int CANT_ART=200;
    int vCantPorArt[CANT_ART]={0};
    int ventasDia[31]={};
    cargarDatosVentas(vCantPorArt,ventasDia);
    mostrarPuntoA(vCantPorArt,CANT_ART);
    mostrarPuntoB(ventasDia,31);
    mostrarPuntoC(vCantPorArt,CANT_ART);

    return 0;
}
