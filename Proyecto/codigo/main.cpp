#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data long long int

using namespace std;

int main(int argc, char** argv) {

	int order = 8;
	BPlusTree<Data>* tree = new BPlusTree<Data>(order);

	clock_t beginInsert = clock();
	for (int index = 0; index < 100000000; ++index)
		tree->insertAk7(index + 1 + (index * 3));
	clock_t endInsert = clock();

	//tree->printTree();

	clock_t beginFind = clock();
	for (int index = 0; index < 1000000; ++index)
		tree->find(index + 1 + (index * 3));
	clock_t endFind = clock();

	cout << "Order: " << order << endl;
	cout << "Levels: " << tree->levels << endl;
	cout << "\nInsert time: " << (1000 * (endInsert - beginInsert)) / CLOCKS_PER_SEC << "ms" << endl;
	cout << "\nFind time: " << (1000 * (endFind - beginFind)) / CLOCKS_PER_SEC << "ms" << endl;

	// tree->find(1945);
	// tree->find(3673);
	// tree->find(1923);
	// tree->find(1921);
	// tree->find(413);


    return 0;
}
