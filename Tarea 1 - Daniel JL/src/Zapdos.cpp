#include "../include/Zapdos.hpp"

Zapdos::Zapdos(){
  nombre = "";
  especie = "Zapdos";
  hp = 100;
  atk = 90;
  defensa = 85;
  atkEspecial = 125;
  defensaEspecial = 90;
  spd = 90;
  experiencia = 0;
  call = "Thhrppppzz";
  type = Electric::type() + Flying::type();
  strongVs = Electric::sVs() + Flying::sVs();
  weekVs = Electric::wVs() + Flying::wVs();
}

Zapdos::Zapdos(string Nombre){
  nombre = Nombre;
  especie = "Zapdos";
  hp = 100;
  atk = 90;
  defensa = 85;
  atkEspecial = 125;
  defensaEspecial = 90;
  spd = 90;
  experiencia = 0;
  call = "Thhrppppzz";
  type = Electric::type() + Flying::type();
  strongVs = Electric::sVs() + Flying::sVs();
  weekVs = Electric::wVs() + Flying::wVs();
}

Zapdos::~Zapdos(){
}

void Zapdos::printZapdos(){
  print();
  cout << "Debil contra: " << weekVs << endl;
  cout << "Fuerte contra: " << strongVs << endl;
}

void Zapdos::ataque1(Pokemon &other){
  other.hp -= 3;
}

void Zapdos::ataque2(Pokemon &other){
  other.hp -= other.hp/8;
}

void Zapdos::ataque3(Pokemon &other){
  other.hp -= other.hp/4;
}

void Zapdos::ataque4(Pokemon &other){
  other.hp -= other.hp/2;
}
