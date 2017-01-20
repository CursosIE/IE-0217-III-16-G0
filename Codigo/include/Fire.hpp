#ifndef FIRE_HPP
#define  FIRE_HPP
#include <iostream>
#include "Pokemon.hpp"

using namespace std;

class Fire : virtual public Pokemon{
public:
    //Metodos:
    Fire();
    virtual ~Fire();

    static string type();
    static string sVs();
    static string wVs();
};

#endif //FIRE_HPP
