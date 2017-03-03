#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data long long int

using namespace std;

int main(int argc, char** argv) {

	int order = 3;
	BPlusTree<Data>* tree = new BPlusTree<Data>(order);
	//
	//clock_t beginInsert = clock();
	for (int index = 0; index < 1000; ++index)
		tree->insertAk7(index);
	//clock_t endInsert = clock();
	//
	//tree->printTree();
	//
	// clock_t beginFind = clock();
	// for (int index = 0; index < 10000; ++index)
	// 	tree->find(index);
	// clock_t endFind = clock();
	//
	//cout << "Order: " << order << endl;
	//cout << "Levels: " << tree->levels << endl;
	//cout << "\nInsert time: " << (1000 * (endInsert - beginInsert)) / CLOCKS_PER_SEC << "ms" << endl;
	// cout << "\nFind time: " << (1000 * (endFind - beginFind)) / CLOCKS_PER_SEC << "ms" << endl;
	//
	delete tree;

	return 0;
}
