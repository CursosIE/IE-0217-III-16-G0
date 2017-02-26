#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data int

using namespace std;

int main(int argc, char** argv) {

	BPlusTree<Data>* tree = new BPlusTree<Data>(3, 3);
    // Node<D>* N = new Node<D>(4);
    // Leaf<D>* L = new Leaf<D>(4);

    return 0;
}
