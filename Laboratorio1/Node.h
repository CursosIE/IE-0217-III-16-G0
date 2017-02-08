
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T> class Node {
public:

    Node* L;
    Node* R;
    Node* P;
    T* D;

    Node() {
        L = 0x0; // puntero nulo
        R = 0x0;
        D = 0x0;
        P = 0x0;
    };

    Node(Node* l, Node* r, Node* p, T* d) {
        L = l;
        R = r;
        D = d;
        P = p;
    };

    virtual ~Node() {
        delete L;
        delete R;
        delete D;
        delete P;
    };

    //-------------------

    void display() {
        cout << "n: " << this << "\t\t";
        cout << "val: " << *D << "\t\t";
        cout << "P: " << P << "\t\t";
        cout << "L: " << L << "\t\t";
        cout << "R: " << R << "\t\t";
        cout << endl;
    };

    bool isleaf()
    {
        if(L == 0x0 && R == 0x0)
            return 1;
        else
            return 0;
    }

private:

};

#endif /* NODE_H */

