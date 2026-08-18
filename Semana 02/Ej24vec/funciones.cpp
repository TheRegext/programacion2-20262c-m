///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include "funciones.h"

using namespace std;

/*
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
///una de las posiciones del vector con el promedio e informar si corresponde */


void cargarDatosVentas(int *vArt,int *vDia){
    int art, dia, cantidad;

    cout<<"Ingrese articulo: "<<endl;
    cin>>art;

    while(art!=0){
        cout<<"Ingrese dia: "<<endl;
        cin>>dia;
        cout<<"Ingrese cantidad: "<<endl;
        cin>>cantidad;
        cout<<endl;

        vArt[art-1]+=cantidad;
        vDia[dia-1]++;

        cout<<"Ingrese articulo: "<<endl;
        cin>>art;
    }

}

///a) Informar para cada código de artículo la cantidad total vendida en el mes.
void mostrarPuntoA(int *vArt,int cantArt){

    cout<<"Cantidad total vendida del mes"<<endl;
    for(int i=0; i<cantArt; i++){
        cout<<"Codigo articulo: "<<i+1<<"  |  Cantidad: "<<vArt[i]<<endl;
    }
    cout<<endl;
}

///b) Informar los días en los que no hubo ventas.
void mostrarPuntoB(int *vDia,int dias){

    cout<<"Dias en los que no hubo ventas"<<endl;
    for(int i=0; i<dias; i++){
        if(vDia[i]==0){
            cout<<"Dia "<<i+1<<" sin ventas"<<endl;
        }
    }
    cout<<endl;
}

///c) Informar los códigos de los artículos cuyas ventas en cantidad son mayores al promedio.
void mostrarPuntoC(int *vArt,int cantArt){

    float promedio=promedioVector(vArt, cantArt);

    cout<<"Codigos de los articulos cuyas ventas en cantidad son mayores al promedio"<<endl;
    cout<<"PROMEDIO: "<<promedio<<endl;
    for(int i=0; i<cantArt;i++){
        if(vArt[i]>promedio){
            cout<<"Codigo articulo: "<<i+1<<endl;
        }
    }
    cout<<endl;

}

float promedioVector(int *vArt,int cantArt){
    float promedio=0;
    int acumulador=0;

    for(int i=0; i<cantArt; i++){
        acumulador += vArt[i];
    }

    promedio=acumulador/cantArt;

    return promedio;
}
