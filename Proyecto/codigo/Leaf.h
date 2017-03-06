/**
*@file Node.h
*@version 1.0
*@date 6/03/17
*@author Luis Diego Fernandez, Daniel Jimenez
*@title Arbol B+
*@brief Clase Hoja 
*/

#ifndef LEAF_H
#define LEAF_H

#include <iostream>

#include "Node.h"
using namespace std;

//se crea la clase como una plantilla
template <typename Data>
class Leaf : public Node<Data> {
public:

    Data* arrayData; //arreglo de datos

    /*! \brief Constructor por defecto.
     */
    Leaf() {
        this->father = nullptr;
        this->order = 0;
        this->arrayKeys = nullptr;
        this->arrayPtrs = nullptr;
        this->arrayData = nullptr;
        this->isLeaf = 1;
    }

    /*! \brief Constructor para crear una Hoja de un tamanno pre establecido.
     */
    Leaf(int order) {
        this->father = nullptr;
        this->isLeaf = 1;
        this->order = order;
        this->arrayKeys = new int[order];
        this->arrayPtrs = nullptr;
        this->arrayData = new Data[order];
        for (int index = 0; index < order; ++index)
                this->arrayKeys[index] = -1;
    }

    /*! \brief Constructor por copia.
     */
    Leaf(int order, Node<Data>* father) {
        this->father = father;
        this->isLeaf = 1;
        this->order = order;
        this->arrayKeys = new int[order];
        this->arrayPtrs = nullptr;
        this->arrayData = new Data[order];
    }

    /*! \brief Destructor.
     */
    virtual ~Leaf() {
        delete[] this->arrayKeys;
        delete[] this->arrayData;
    }

};

#endif /* LEAF_H */
