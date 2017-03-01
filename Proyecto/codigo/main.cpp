#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data int

using namespace std;

int main(int argc, char** argv) {

	BPlusTree<Data>* tree = new BPlusTree<Data>(3);

	tree->insert(85);
	tree->insert(150);
	tree->insert(35);
	tree->insert(20);
	tree->insert(45);
	tree->insert(200);
	tree->insert(90);
	tree->insert(50);
	tree->insert(47);
	tree->insert(60);

	cout << endl;
	tree->printTree();

    return 0;
}
