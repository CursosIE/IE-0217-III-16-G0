#ifndef ElECTRIC_HPP
#define  ElECTRIC_HPP
#include <iostream>
#include "Pokemon.hpp"

using namespace std;

class Electric : virtual public Pokemon{
public:
    //Metodos:
    Electric();
    virtual ~Electric();

    static string type();
    static string sVs();
    static string wVs();
};

#endif //ElECTRIC_HPP
