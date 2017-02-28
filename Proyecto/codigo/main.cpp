#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data int

using namespace std;

int main(int argc, char** argv) {

	BPlusTree<Data>* tree = new BPlusTree<Data>(3);

	tree->insert(11);
	tree->insert(69);
	tree->insert(5);
	tree->insert(100);
	tree->insert(12);
	tree->insert(71);
	cout << "\n" << endl;
	cout << "\n" << endl;
	tree->insert(85);
	cout << endl;
	tree->printTree();

    return 0;
}
