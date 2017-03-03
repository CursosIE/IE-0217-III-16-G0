#include <cmath>
#include <cstdlib>
#include <iostream>

#include "BPlusTree.h"

#define Data int

using namespace std;

int main(int argc, char** argv) {

	//prueba 1, 16 entradas
	// int order = 3;
	// int n = 10;
	// BPlusTree<Data>* tree = new BPlusTree<Data>(order);

	// tree->insertAk7(1);
	// tree->insertAk7(3);
	// tree->insertAk7(21);
	// tree->insertAk7(29);
	// tree->insertAk7(35);
	// tree->insertAk7(44);
	// tree->insertAk7(55);
	// tree->insertAk7(61);
	// tree->insertAk7(73);
	// tree->insertAk7(82);
	// tree->insertAk7(88);
	// tree->insertAk7(111);
	// tree->insertAk7(150);
	// tree->insertAk7(201);
	// tree->insertAk7(277);
	// tree->insertAk7(288);
	// tree->insertAk7(300);

	// tree->printTree();

	// cout << "Finding number 288..." << endl;
	// if (tree->find(288))
	// 	cout << "Number 288 was found!!" << endl;
	// else
	// 	cout << "Number 288 was NOT found!!" << endl;

	// cout << "\n//////////\n" << endl;

	// tree->deleteAk7(288);

	// tree->printTree();

	// cout << "Finding number 288..." << endl;
	// if (tree->find(288))
	// 	cout << "Number 288 was found!!" << endl;
	// else
	// 	cout << "Number 288 was NOT found!!" << endl;

	// // tree->printTree();
	// cout << endl;
	// cout << "Order: " << order << endl;
	// cout << "Elements: " << tree->treeElements << endl;
	// cout << "Levels: " << tree->levels << endl;


	//prueba 2 insercion de 1 millon de numeros e impresion
	// int order = 3;
	// BPlusTree<Data>* tree = new BPlusTree<Data>(order);
	// clock_t beginInsert1 = clock();
	// for (int insertIndex = 0; insertIndex < 1000000; ++insertIndex)
	// 	tree->insertAk7(insertIndex);
	// clock_t endInsert1 = clock();

	// cout << "First tree: " << endl;
	// cout << "Finding number 1932..." << endl;
	// if (tree->find(1932))
	// 	cout << "Number 1932 was found!!" << endl;
	// else
	// 	cout << "Number 1932 was NOT found!!" << endl;
	// cout << endl;

	// cout << "Finding number 9829552..." << endl;
	// if (tree->find(9829552))
	// 	cout << "Number 9829552 was found!!" << endl;
	// else
	// 	cout << "Number 9829552 was NOT found!!" << endl;
	// cout << endl;

	// cout << "Finding number 783015..." << endl;
	// if (tree->find(783015))
	// 	cout << "Number 783015 was found!!" << endl;
	// else
	// 	cout << "Number 783015 was NOT found!!" << endl;
	// cout << endl;

	// cout << endl;

	// int order2 = 50;
	// BPlusTree<Data>* tree2 = new BPlusTree<Data>(order2);
	// clock_t beginInsert2 = clock();
	// for (int insertIndex = 0; insertIndex < 1000000; ++insertIndex)
	// 	tree2->insertAk7(insertIndex);
	// clock_t endInsert2 = clock();


	// clock_t beginFind4 = clock();
	// tree->find(1932);
	// clock_t endFind4 = clock();

	// clock_t beginFind5 = clock();
	// tree->find(9829552);
	// clock_t endFind5 = clock();

	// clock_t beginFind6 = clock();
	// tree->find(783015);
	// clock_t endFind6 = clock();

	// cout << "Second tree: " << endl;
	// cout << "Finding number 1932..." << endl;
	// if (tree2->find(1932))
	// 	cout << "Number 1932 was found!!" << endl;
	// else
	// 	cout << "Number 1932 was NOT found!!" << endl;
	// cout << "Finding time: " << (1000000 * (endFind4- beginFind4)) / CLOCKS_PER_SEC << " \u00B5s.\n" << endl;

	// cout << "Finding number 9829552..." << endl;
	// if (tree2->find(9829552))
	// 	cout << "Number 9829552 was found!!" << endl;
	// else
	// 	cout << "Number 9829552 was NOT found!!" << endl;
	// cout << "Finding time: " << (1000000 * (endFind5- beginFind5)) / CLOCKS_PER_SEC << " \u00B5s.\n" << endl;

	// cout << "Finding number 783015..." << endl;
	// if (tree2->find(783015))
	// 	cout << "Number 783015 was found!!" << endl;
	// else
	// 	cout << "Number 783015 was NOT found!!" << endl;
	// cout << "Finding time: " << (1000000 * (endFind6- beginFind6)) / CLOCKS_PER_SEC << " \u00B5s.\n" << endl;

	// cout << "First tree:" << endl;
	// cout << "Order: " << order << endl;
	// cout << "Elements: " << tree->treeElements << endl;
	// cout << "Levels: " << tree->levels << endl;

	// cout << "\nSecond tree:" << endl;
	// cout << "Order: " << order2 << endl;
	// cout << "Elements: " << tree2->treeElements << endl;
	// cout << "Levels: " << tree2->levels << endl;

	// cout << endl;

	// cout << "\nFirst tree insrtion time: " << (1000 * (endInsert1 - beginInsert1)) / CLOCKS_PER_SEC << "ms" << endl;
	// cout << "\nSecond tree insrtion time: " << (1000 * (endInsert2 - beginInsert2)) / CLOCKS_PER_SEC << "ms" << endl;

	

	return 0;
}