#ifndef CELDA_H
#define CELDA_H


class Celda {
private:
    int zacate; // el zacate equivale a energia para ovejas y ratones
    int ocupante; // dependiendo del numero entero que tenga va a ser cierto animal, 0 es vacio

public:
    Celda();
    Celda(int cantidadZacate, int tipoOcupante);
    virtual ~Celda();
};

#endif // CELDA_H
