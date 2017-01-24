#ifndef ANIMAL_H
#define ANIMAL_H


class Animal {

//Atricbutos
public:
    int Sexo; //Sexo del animal.
    int Energia; //Energia del aimal.
    int Fila, Columna; //Posicion del animal.

//Funciones
public:
    Animal();
    virtual ~Animal();

    virtual void Mover() = 0;
    virtual void Comer() = 0;
    virtual void Reproducir() = 0;
    virtual void Morir() = 0;
};

#endif // ANIMAL_H