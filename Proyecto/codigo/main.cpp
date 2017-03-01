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
	cout << endl;

	tree->find(85);
	tree->find(150);
	tree->find(35);
	tree->find(20);
	tree->find(45);
	tree->find(200);
	tree->find(1000);
	tree->find(90);
	tree->find(50);
	tree->find(47);
	tree->find(60);
	cout << endl; 

    return 0;
}
