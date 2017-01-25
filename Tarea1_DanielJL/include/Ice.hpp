#ifndef ICE_HPP
#define  ICE_HPP
#include <iostream>
#include "Pokemon.hpp"

using namespace std;

class Ice : virtual public Pokemon{
public:
    //Metodos:
    Ice();
    virtual ~Ice();

    static string type();
    static string sVs();
    static string wVs();
};

#endif //ICE_HPP
