#include "Moltres.h"

Moltres::Moltres() {

}

//implementacion del constructor del constructor
Moltres::Moltres(string nombre) {
    this->name = nombre;
    this->species = "Moltres";
    this->type = Fire::type() + Flying::type();
    this->cry = "ktnnnnrghhnnnnghhnnngn";
    this->status = "Healthy";
    this->SPD = 90;
    this->HP = 90;
    this->ATK = 90;
    this->DEF = 90;
    this->sATK = 125;
    this->sDEF = 85;
    this->EXP = 0;
    this->strongVs = Fire::strongVs() + Flying::strongVs();
    this->weakVs = Fire::weakVs() + Flying::weakVs();
}

Moltres::~Moltres() {

}

void Moltres::print() {
    printInfo();
    cout << "Strong against: " << strongVs << endl;
    cout << "Weak against: " << weakVs << endl;
    cout << "\n";
}

//Burn up
void Moltres::atk1(Pokemon &other) {
    cout << this->name << " attacks " << other.name << " with Burn up " << endl;
    cout << "Enemy is burned " << "\n" <<endl;
    other.status = "Burned";
    other.HP *= 0.85;
}

//Flamethrower
void Moltres::atk2(Pokemon &other) {
    cout << this->name << " attacks " << other.name << " with Flamethrower " << "\n" << endl;
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
void Moltres::atk3() {
    cout << this->name << " used Agility " << endl;
    cout << this->name << " speed rose " << "\n" << endl;
    SPD *= 1.2;
}

//Fire Blast
void Moltres::atk4(Pokemon &other) {
    cout << this->name << " attacks " << other.name << " with Fire Blast " << endl;
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
