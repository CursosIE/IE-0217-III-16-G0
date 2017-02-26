
#include <iostream>
#include "Node.h"
#include "Leaf.h"

#define D int

using namespace std;

int main(int argc, char** argv) {

    Node<D>* N = new Node<D>(4);
    Leaf<D>* L = new Leaf<D>(4);

    return 0;
}
