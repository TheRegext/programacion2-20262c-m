#include <iostream>

using namespace std;

class Animal{
    private:

    public:
        virtual void HacerSonido(){
            cout<<"TENGO QUE HACER RUIDO"<<endl;
        }
        virtual void Atacar(){
            cout<<"ATACO"<<endl;
        }
};

class Perro : public Animal{
    private:

    public:
        void HacerSonido() override{
            cout<<"GUAU"<<endl;
        }
        void Atacar() override{
            cout<<"MUERDE"<<endl;
        }
        void Saltar(){
            cout<<"SALTA"<<endl;
        }
};

class Gato : public Animal{
    private:

    public:
        void HacerSonido() override{
            cout<<"MIAU"<<endl;
        }
        void Atacar(){
            cout<<"ARAÑA"<<endl;
        }
};

class Pajaro : public Animal{
    private:

    public:
        void HacerSonido() override{
            cout<<"PIO PIO"<<endl;
        }
};

void HacerSonido(Animal **vec, int tam){
    for(int i=0; i<tam; i++){
        vec[i]->HacerSonido();
        vec[i]->Atacar();
    }
}

int main()
{
    setlocale(LC_ALL, "spanish");
    Perro obj;
    Animal *ani[2];
    ani[0] = new Perro;
    ani[1] = new Gato;
    HacerSonido(ani, 2);
    delete ani[0];
    delete ani[1];
    return 0;
}
