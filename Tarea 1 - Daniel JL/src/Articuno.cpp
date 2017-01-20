#include "../include/Articuno.hpp"

Articuno::Articuno(){
  nombre = "";
  especie = "Articuno";
  hp = 100;
  atk = 85;
  defensa = 100;
  atkEspecial = 95;
  defensaEspecial = 125;
  spd = 85;
  experiencia = 0;
  call = "zsdaaaddddaad";
  type = Ice::type() + Flying::type();
  strongVs = Ice::sVs() + Flying::sVs();
  weekVs = Ice::wVs() + Flying::wVs();
}

Articuno::Articuno(string Nombre){
  nombre = Nombre;
  especie = "Articuno";
  hp = 100;
  atk = 85;
  defensa = 100;
  atkEspecial = 95;
  defensaEspecial = 125;
  spd = 85;
  experiencia = 0;
  call = "zsdaaaddddaad";
  type = Ice::type() + Flying::type();
  strongVs = Ice::sVs() + Flying::sVs();
  weekVs = Ice::wVs() + Flying::wVs();
}

Articuno::~Articuno(){
}

void Articuno::printArticuno(){
  print();
  cout << "Debil contra: " << weekVs << endl;
  cout << "Fuerte contra: " << strongVs << endl;
}

void Articuno::ataque1(Pokemon &other){
  other.hp -= 3;
}

void Articuno::ataque2(Pokemon &other){
  other.hp -= other.hp/8;
}

void Articuno::ataque3(Pokemon &other){
  other.hp -= other.hp/4;
}

void Articuno::ataque4(Pokemon &other){
  other.hp -= other.hp/2;
}
