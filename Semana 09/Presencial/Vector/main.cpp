#include <iostream>
#include <vector>

/**
Clase Pila:

La clase Pila deberá almacenar números enteros utilizando un atributo privado de tipo vector<int>.

Métodos que deberá implementar:
    apilar(int valor): incorporar un nuevo elemento en el tope de la pila.
    desapilar(): eliminar el elemento que se encuentra en el tope. Si la pila está vacía, deberá informar que no es posible realizar la operación.
    tope(): devolver el elemento ubicado en el tope sin eliminarlo. Se deberá contemplar el caso en que la pila esté vacía.
    estaVacia(): devolver un valor booleano que indique si la pila no contiene elementos.
    cantidadElementos(): devolver la cantidad de elementos almacenados.
    mostrar(): mostrar los elementos de la pila desde el tope hasta la base, sin modificar su contenido.


Clase Cola:

La clase Cola deberá almacenar números enteros utilizando un atributo privado de tipo vector<int>.

Métodos que deberá implementar:

    encolar(int valor): incorporar un nuevo elemento al final de la cola.
    desencolar(): eliminar el elemento que se encuentra al frente de la cola. Si la cola está vacía, deberá informar que no es posible realizar la operación.
    frente(): devolver el primer elemento de la cola sin eliminarlo. Se deberá contemplar el caso en que la cola esté vacía.
    estaVacia(): devolver un valor booleano que indique si la cola no contiene elementos.
    cantidadElementos(): devolver la cantidad de elementos almacenados.
    mostrar(): mostrar los elementos de la cola desde el frente hasta el final, sin modificar su contenido.
*/

using namespace std;

int main()
{
    vector<int> vec;
    /**
    vec.begin() es el iterador del inicio de mi vector
    vec.end() es el iterador del final del vector
    vec.erase() elimina un elemento o varios en un rango determinado (se utiliza en conjunto con begin y end)
    vec.empty() devuelve true si esta vacio o false si contiene al menos un elemento
    vec.size() devuelve la cantidad de elementos de mi vector
    vec.push_back(valor) agrega un elemento al final de mi vector
    vec.pop_back() elimina el elemento del final de mi vector
    vec.front() me devuelve el valor del principio de mi vector (no lo elimina)
    vec.back() me devuelve el valor del final de mi vector (no lo elimina)
    vec.clear() elimina todos los elementos del vector
    */
    if(vec.empty() == true){
        cout<<"EL VECTOR ESTA VACIO"<<endl;
    }
    for(int i=0; i<15; i++){
        vec.push_back(i+1);
    }
    int tam = vec.size();
    for(int i=0; i<tam;i++){
        vec.push_back(i+1);
    }
    while(vec.empty() == false){
//        cout<<vec.back()<<endl; //vec[vec.size()-1]
//        vec.pop_back();
        cout<<vec.front()<<endl;
        vec.erase(vec.begin());
    }
    if(vec.empty() == true){
        cout<<"EL VECTOR ESTA VACIO"<<endl;
    }
    return 0;
}
