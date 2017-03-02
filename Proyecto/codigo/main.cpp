#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data long long int

using namespace std;

int main(int argc, char** argv) {

	BPlusTree<Data>* tree = new BPlusTree<Data>(3);

	for (int index = 0; index < 1000; ++index)
		tree->insertAk7(index + 1 + (index * 3));


	//tree->printTree();

	tree->find(1945);
	tree->find(3673);
	tree->find(1923);
	tree->find(1921);
	tree->find(413);


    return 0;
}
