#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data int

using namespace std;

int main(int argc, char** argv) {

	int order = 3;
	BPlusTree<Data>* tree = new BPlusTree<Data>(order);
	//
	clock_t beginInsert = clock();
	for (int index = 0; index < 2000000; ++index)
		tree->insertAk7(index);
	clock_t endInsert = clock();
	//
	//tree->printTree();
	//
	clock_t beginFind = clock();
	for (int index = 0; index < 10000; ++index)
		tree->find(index);
	clock_t endFind = clock();
	//
	cout << "Order: " << order << endl;
	cout << "Levels: " << tree->levels << endl;
	cout << "\nInsert time: " << (1000 * (endInsert - beginInsert)) / CLOCKS_PER_SEC << "ms" << endl;
	cout << "\nFind time: " << (1000 * (endFind - beginFind)) / CLOCKS_PER_SEC << "ms" << endl;
	//
	delete tree;

	tree->insertAk7(13);
	tree->insertAk7(16);
	tree->insertAk7(89);
	tree->insertAk7(77);
	tree->insertAk7(1);
	tree->insertAk7(25);
	tree->insertAk7(99);
	tree->insertAk7(50);
	tree->insertAk7(53);
	tree->insertAk7(8);
	tree->insertAk7(9);
	tree->insertAk7(7);
	tree->insertAk7(15);
	tree->insertAk7(40);

	tree->printTree();

	// tree->find(99);
	// tree->deleteAk7(99);
	// tree->find(99);
	// tree->printTree();
	tree->deleteAk7(15);
	tree->find(15);

	tree->deleteAk7(13);
	tree->find(13);

	tree->printTree();




	return 0;
}
