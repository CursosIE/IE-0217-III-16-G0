#include "../include/Pokemon.hpp"

Pokemon::Pokemon(){
}

Pokemon::~Pokemon(){
}

string Pokemon::callFun(){
  return call;
}

void Pokemon::print(){

  cout << "Nombre: " << nombre << endl;
  cout << "Especie: " << especie << endl;
  cout << "HP: " << hp << endl;
  cout << "Atk: " << atk << endl;
  cout << "Defensa: " << defensa << endl;
  cout << "Atk Especial: " << atkEspecial << endl;
  cout << "Def Especial: " << defensaEspecial << endl;
  cout << "Velocidad: " << spd << endl;
  cout << "Experiencia: " << experiencia << endl;
}
