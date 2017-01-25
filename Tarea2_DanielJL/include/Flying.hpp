#ifndef FLYING_HPP
#define  FLYING_HPP
#include <iostream>
#include "Pokemon.hpp"

using namespace std;

class Flying : virtual public Pokemon{
public:
    //Metodos:
    Flying();
    virtual ~Flying();

    static string type();
    static string sVs();
    static string wVs();
};

#endif //FLYING_HPP
