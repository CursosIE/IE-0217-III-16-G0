#include "../include/Zapdos.hpp"
#include "../include/Articuno.hpp"
#include "../include/Moltres.hpp"

int main(int argc, char const *argv[]) {

  //Creacion de un obejto correspondiente a cada posible pokemon.

  cout << endl << "Creacion de Pokemones" << endl << endl;

  Zapdos* p0 = new Zapdos("Daniel");
  p0->printZapdos();

  cout << endl << "--------------------------" << endl << endl;

  Articuno* p1 = new Articuno("Juan");
  p1->printArticuno();

  cout << endl << "--------------------------" << endl << endl;

  Moltres* p2 = new Moltres("Pedro");
  p2->printMoltres();

  //Ataques entre Daniel y Juan.
  p0->ataque1(*p1);
  p1->ataque3(*p0);

  p0->ataque4(*p1);
  p1->ataque2(*p0);


  //Verificacion de daño por ataques en HP de cada pokemon.
  cout << endl << "Cambio en HP despues de ataques entre Daniel y Juan:" << endl << endl;

  p1->printArticuno();

  cout << endl << "--------------------------" << endl << endl;

  p0->printZapdos();

  cout << endl;

  delete p0;
  delete p1;
  delete p2;

  return 0;
}
