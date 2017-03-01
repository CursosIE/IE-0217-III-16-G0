#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data long long int

using namespace std;

int main(int argc, char** argv) {

	BPlusTree<Data>* tree = new BPlusTree<Data>(3);

	// clock_t insertBegin = clock();
	// for (int index = 0; index < 1000000; ++index)
	// 	tree->insert(index + 1 + (index * 3));

	// clock_t insertEnd = clock();

	// clock_t printBegin = clock();
	// tree->printTree();
	// clock_t printEnd = clock();
	
	// // clock_t findBegin = clock();
	// // tree->find(2097); //no funca, este es root
	// // clock_t findEnd = clock();

	// tree->find(2097145);

	// cout << "\nInsert time: " << (1000* (insertEnd - insertBegin)) / CLOCKS_PER_SEC << "ms." << endl;
	// cout << "\nPrint time: " << (1000* (printEnd - printBegin)) / CLOCKS_PER_SEC << "ms." << endl;
	// //cout << "\nFind time: " << (1000* (findEnd - findBegin)) / CLOCKS_PER_SEC << "ms." << endl;

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

	// tree->find(85);
	// tree->find(150);
	// tree->find(35);
	// tree->find(20);
	// tree->find(45);
	// tree->find(200);
	// tree->find(1000);
	// tree->find(90);
	// tree->find(50);
	// tree->find(47);
	// tree->find(60);
	// cout << endl; 

    return 0;
}
