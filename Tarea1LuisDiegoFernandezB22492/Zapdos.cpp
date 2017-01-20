#include "Zapdos.h"

Zapdos::Zapdos() {

}

//implementacion del constructor del constructor
Zapdos::Zapdos(string nombre) {
    this->name = nombre;
    this->species = "Zapdos";
    this->type = Electric::type() + Flying::type();
    this->cry = "tnnrrnghhng";
    this->status = "Healthy";
    this->SPD = 100;
    this->HP = 90;
    this->ATK = 90;
    this->DEF = 85;
    this->sATK = 125;
    this->sDEF = 90;
    this->EXP = 0;
    this->strongVs = Electric::strongVs() + Flying::strongVs();
    this->weakVs = Electric::weakVs() + Flying::weakVs();
}

Zapdos::~Zapdos() {

}

void Zapdos::print() {
    printInfo();
    cout << "Strong against: " << strongVs << endl;
    cout << "Weak against: " << weakVs << endl;
    cout << "\n";
}

//Thunder Shock
void Zapdos::atk1(Pokemon &other) {
    cout << this->name << " attacks " << other.name << " with Thunder Shock " << endl;
    cout << "Enemy is paralyzed, Enemy's speed fell " << "\n" <<endl;
    other.status = "Paralyzed";
    other.SPD *= 0.7;
}

//thunderbolt
void Zapdos::atk2(Pokemon &other) {
    cout << this->name << " attacks" << other.name << " with Flamethrower " << "\n" << endl;
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
void Zapdos::atk3() {
    cout << this->name << " used Agility " << endl;
    cout << this->name << " speed rose " << "\n" << endl;
    SPD *= 1.2;
}

//Thunder
void Zapdos::atk4(Pokemon &other) {
    cout << this->name << " attacks " << other.name << " with Fire Blast " << endl;
    cout << "It's a critical hit!" << "\n" <<endl;
    if (other.HP <= 110) {
        other.HP = 0;
        if ((EXP + 75) < 100)
            EXP += 75;
        else
            EXP = (EXP + 75 - 100);
    }
    else
        other.HP -= 110;
}
