#include "../include/Moltres.hpp"

Moltres::Moltres(){
  nombre = "";
  especie = "Moltres";
  hp = 100;
  atk = 100;
  defensa = 90;
  atkEspecial = 125;
  defensaEspecial = 85;
  spd = 70;
  experiencia = 0;
  call = "kssggaaaazaaaaaa";
  type = Fire::type() + Flying::type();
  strongVs = Fire::sVs() + Flying::sVs();
  weekVs = Fire::wVs() + Flying::wVs();
}

Moltres::Moltres(string Nombre){
  nombre = Nombre;
  especie = "Moltres";
  hp = 100;
  atk = 100;
  defensa = 90;
  atkEspecial = 125;
  defensaEspecial = 85;
  spd = 70;
  experiencia = 0;
  call = "kssggaaaazaaaaaa";
  type = Fire::type() + Flying::type();
  strongVs = Fire::sVs() + Flying::sVs();
  weekVs = Fire::wVs() + Flying::wVs();
}

Moltres::~Moltres(){
}

void Moltres::printMoltres(){
  print();
  cout << "Debil contra: " << weekVs << endl;
  cout << "Fuerte contra: " << strongVs << endl;

}

void Moltres::ataque1(Pokemon &other){
  other.hp -= 3;
}

void Moltres::ataque2(Pokemon &other){
  other.hp -= other.hp/8;
}

void Moltres::ataque3(Pokemon &other){
  other.hp -= other.hp/4;
}

void Moltres::ataque4(Pokemon &other){
  other.hp -= other.hp/2;
}
