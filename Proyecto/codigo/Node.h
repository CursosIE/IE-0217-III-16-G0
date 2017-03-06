/**
*@file Node.h
*@version 1.0
*@date 6/03/17
*@author Luis Diego Fernandez, Daniel Jimenez
*@title Arbol B+
*@brief Clase Nodo 
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

//se crea la clase como una plantilla
template <typename Data>
class Node {
public:
    int elements; //elementos del nodo
    int order; //orden del arbol
    int isLeaf; //bandera de control, en este caso es falsa 
    int* arrayKeys; //arreglo de llaves 
    Node<Data>** arrayPtrs; //arrelgo de punteros
    Node<Data>* father; //puntero al padre


    /*! \brief Constructor por defecto.
     */
    Node() {
        order = 0;
        this->father = nullptr;
        this->arrayKeys = nullptr;
        this->arrayPtrs = nullptr;
        isLeaf = 0;
        this->elements = 0;
    }

    /*! \brief Constructor para crear un Nodo de un tamanno pre establecido.
     */
    Node(int order) {
        this->father = nullptr;
        this->order = order;
        arrayKeys = new int[order];
        arrayPtrs = new Node<Data>*[order + 1];
        for (int index = 0; index < order + 1; ++index) {
            arrayPtrs[index] = nullptr;
            if (index < order)
                arrayKeys[index] = -1;
        }
        isLeaf = 0;
        this->elements = 0;
    }

    /*! \brief Constructor por copia.
     */
    Node(int order, Node<Data>* father) {
        this->order = order;
        this->father = father;
        arrayKeys = new int[order];
        arrayPtrs = new Node<Data>*[order + 1];
        isLeaf = 0;
    }

    /*! \brief Destructor.
     */
    virtual ~Node() {
        delete[] arrayKeys;
        delete[] arrayPtrs;
    }

};

#endif /* NODE_H */
