#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

template <typename D>
class Edge {
public:
    Node<D>* From;
    Node<D>* To;
    double Weight;

    Edge() {
        From = nullptr;
        To = nullptr;
    }

    Edge(Node<D>* From, Node<D>* To, double W) {
        this->From = From;
        this->To = To;
        this->Weight = W;
    }

    virtual ~Edge() {
        delete From;
        delete To;
    }
};

#endif /* EDGE_H */
