#include "Articuno.h"

Articuno::Articuno() {

}

//implementacion del constructor del constructor
Articuno::Articuno(string nombre) {
    this->name = nombre;
    this->species = "Articuno";
    this->type = Ice::type() + Flying::type();
    this->cry = "prrrnnniinnprnnn";
    this->status = "Healthy";
    this->SPD = 85;
    this->HP = 90;
    this->ATK = 85;
    this->DEF = 100;
    this->sATK = 95;
    this->sDEF = 125;
    this->EXP = 0;
    this->strongVs = Ice::strongVs() + Flying::strongVs();
    this->weakVs = Ice::weakVs() + Flying::weakVs();
}

Articuno::~Articuno() {

}

void Articuno::print() {
    printInfo();
    cout << "Strong against: " << strongVs << endl;
    cout << "Weak against: " << weakVs << endl;
    cout << "\n";
}

//Freeze dry
void Articuno::atk1(Pokemon &other) {
    cout << this->name << " attacks " << other.name << " with Freezze dry " << endl;
    cout << "Enemy got frozen! " << "\n" <<endl;
    other.status = "Frozen";
    other.SPD = 0;
}

//Ice Beam
void Articuno::atk2(Pokemon &other) {
    cout << this->name << " attacks" << other.name << " with Ice Beam " << "\n" << endl;
    if (other.HP <= 90) {
        other.HP = 0;
        if (EXP + 75 < 100)
            EXP += 75;
        else
            EXP = (EXP + 75 - 100);
    }
    else
        other.HP -= 90;
}

//Agility
void Articuno::atk3() {
    cout << this->name << " used Agility " << endl;
    cout << this->name << " speed rose " << "\n" << endl;
    SPD *= 1.2;
}

//Blizzard
void Articuno::atk4(Pokemon &other) {
    cout << this->name << " attacks " << other.name << " with Blizzard " << endl;
    cout << "It's a critical hit!" << "\n" <<endl;
    if (other.HP <= 110) {
        other.HP = 0;
        if (EXP + 75 < 100)
            EXP += 75;
        else
            EXP = (EXP + 75 - 100);
    }
    else
        other.HP -= 110;
}
