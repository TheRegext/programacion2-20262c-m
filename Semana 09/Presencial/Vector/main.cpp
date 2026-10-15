#include <iostream>
#include <vector>

/**
Clase Pila
La clase Pila deberá almacenar números enteros utilizando un atributo privado de tipo vector<int>.
Métodos que deberá implementar:
    apilar(int valor): incorporar un nuevo elemento en el tope de la pila.
    desapilar(): eliminar el elemento que se encuentra en el tope. Si la pila está vacía, deberá informar que no es posible realizar la operación.
    tope(): devolver el elemento ubicado en el tope sin eliminarlo. Se deberá contemplar el caso en que la pila esté vacía.
    estaVacia(): devolver un valor booleano que indique si la pila no contiene elementos.
    cantidadElementos(): devolver la cantidad de elementos almacenados.
    mostrar(): mostrar los elementos de la pila desde el tope hasta la base, sin modificar su contenido.
*/

using namespace std;

int main()
{
    vector<int> vec;
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
