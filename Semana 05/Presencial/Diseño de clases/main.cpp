#include <iostream>
#include <cstring>

using namespace std;

/**
Aplicando el mecanismo de diseño de clases visto, desarrollar las siguientes clases:

1) Figuras geométricas:
-Cuadrado: color, lado.
-Rectángulo: color, base, altura.
-Círculo: color, radio.
Además cada clase debe poder calcular el area y el perímetro de la figura correspondiente.

2) Animales:
-Perro: nombre, peso, raza, ladrar(), morder().
-Gato: nombre, peso, maullar(), arañar().
-Pajaro: nombre, peso, color, cantar(), volar().
*/

class FiguraGeometrica{
    private:
        char color[20];
    public:
        void setColor(const char *);
        const char *getColor();
};

void FiguraGeometrica::setColor(const char *c){
    strcpy(color, c);
}

const char *FiguraGeometrica::getColor(){
    return color;
}

class Cuadrado : public FiguraGeometrica{
    private:
        float lado;
    public:
        void setLado(float);
        float getLado();
        float calcularArea();
        float calcularPerimetro();
};

void Cuadrado::setLado(float l){
    lado = l;
}
float Cuadrado::getLado(){
    return lado;
}
float Cuadrado::calcularArea(){
    return lado*lado;
}
float Cuadrado::calcularPerimetro(){
    return lado*4;
}
class Rectangulo : public FiguraGeometrica{
    private:
        float base;
        float altura;
    public:
        void setBase(float);
        void setAltura(float);
        float getBase();
        float getAltura();
        float calcularArea();
        float calcularPerimetro();
};

void Rectangulo::setBase(float b){
    base = b;
}
void Rectangulo::setAltura(float a){
    altura = a;
}
float Rectangulo::getBase(){
    return base;
}
float Rectangulo::getAltura(){
    return altura;
}
float Rectangulo::calcularArea(){
    return base*altura;
}
float Rectangulo::calcularPerimetro(){
    return base*2+altura*2;
}

int main()
{
    Cuadrado obj;
//    obj.setBase(2);
//    obj.setAltura(4);
//    cout<<"AREA: "<<obj.calcularArea()<<endl;
//    cout<<"PERIMETRO: "<<obj.calcularPerimetro()<<endl;
    return 0;
}
