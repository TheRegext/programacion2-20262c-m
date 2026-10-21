#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Mob {
protected:
    std::string nombre;
    int vida;
    bool muerto;

public:
    Mob(const std::string& nom, int v){
        nombre = nom;
        vida=v;
        muerto = false;
    }

    virtual ~Mob() = default;

    void recibirDanio(int danio) {
        if (muerto || danio <= 0) {
            return;
        }

        vida -= danio;

        if (vida <= 0) {
            vida = 0;
            muerto = true;
            std::cout << nombre << " ha muerto.\n";
        }
    }

    std::string getNombre() const {
        return nombre;
    }

    int getVida() const {
        return vida;
    }

    bool estaMuerto() const {
        return muerto;
    }

    virtual void atacar() = 0;
};

class Zombie : public Mob {
public:
    Zombie(const std::string& nombre, int vida)
        : Mob(nombre, vida) {}

    void atacar() override {
        //if (muerto) return;

        std::cout << nombre
                  << " ataca cuerpo a cuerpo.\n";
    }
};

class Creeper : public Mob {
public:
    Creeper(const std::string& nombre, int vida)
        : Mob(nombre, vida) {}

    void atacar() override {
        //if (muerto) return;

        std::cout << nombre
                  << " explota causando dano.\n";
    }
};

class Esqueleto : public Mob {
public:
    Esqueleto(const std::string& nombre, int vida)
        : Mob(nombre, vida) {}

    void atacar() override {
        //if (muerto) return;

        std::cout << nombre
                  << " dispara una flecha.\n";
    }
};

void spawnearMob(vector <Mob *> &vec){
    if(vec.size()<15){
        int valor = rand()%100;
        if(valor < 10){
            Creeper *creeper = new Creeper("Laureano", 10);
            vec.push_back(creeper);
        }else if(valor < 70){
            Zombie *zombie = new Zombie("Pepe", 20);
            vec.push_back(zombie);
        }else{
            Esqueleto *esqueleto = new Esqueleto("Huesitos", 20);
            vec.push_back(esqueleto);
        }
    }else{
        cout<<"EL VECTOR ESTA LLENO"<<endl;
    }
}

void checkAttack(vector <Mob *> vec){
    int tam = vec.size();
    for(int i=0; i<tam; i++){
        ///PRIMERO COMPRUEBO QUE EL MOB ESTE EN RANGO DE ATAQUE
        ///if(verificarRango(vec[i]))
        vec[i]->atacar();
    }
}

void eliminarMuertos(vector <Mob *> &vec){
    int tam = vec.size();
    for(int i=0; i<tam; i++){
        if(vec[i]->estaMuerto()){
            delete vec[i];
            vec.erase(vec.begin()+i);
            tam--;
            i--;
        }
    }
}

void limpiarMemoria(vector <Mob *> &vec){
    int tam = vec.size();
    for(int i=0; i<tam; i++){
        delete vec[i];
    }
}

int main(){
    srand(time(NULL));
    vector<Mob *> vectorMobs;
    spawnearMob(vectorMobs);
    spawnearMob(vectorMobs);
    spawnearMob(vectorMobs);
    spawnearMob(vectorMobs);
    checkAttack(vectorMobs);
    eliminarMuertos(vectorMobs);
    vectorMobs[1]->recibirDanio(20);
    vectorMobs[2]->recibirDanio(20);
    eliminarMuertos(vectorMobs);
    checkAttack(vectorMobs);
    limpiarMemoria(vectorMobs);
    return 0;
}
