#include <iostream>

#include "BPlusTree.h"
// #include "Node.h"
// #include "Leaf.h"

#define Data long long int

using namespace std;

int main(int argc, char** argv) {

	BPlusTree<Data>* tree = new BPlusTree<Data>(3);

	// // clock_t insertAk7Begin = clock();
	// cout << "Inserting: ";
	for (int index = 0; index < 100; ++index) {
		//cout << index + 1 + (index * 3) << "  ";
		tree->insert(index + 1 + (index * 3));
	}
	// cout << "\n" << endl;

	// // clock_t insertAk7End = clock();

	// // clock_t printBegin = clock();
	// tree->printTree();
	// // clock_t printEnd = clock();

	// // tree->find(25);
	//tree->find(1);
	//tree->find(2);
	//tree->find(129);
	// tree->find(73);


	
	// clock_t findBegin = clock();
	// tree->find(2097); //no funca, este es root
	// clock_t findEnd = clock();

	//tree->find(2097145);

	// cout << "\nInsert time: " << (1000* (insertAk7End - insertAk7Begin)) / CLOCKS_PER_SEC << "ms." << endl;
	// cout << "\nPrint time: " << (1000* (printEnd - printBegin)) / CLOCKS_PER_SEC << "ms." << endl;
	//cout << "\nFind time: " << (1000* (findEnd - findBegin)) / CLOCKS_PER_SEC << "ms." << endl;

	// tree->insertAk7(85);//
	// tree->insertAk7(150);//
	// tree->insertAk7(35);
	// tree->insertAk7(20);//
	// tree->insertAk7(45);
	// tree->insertAk7(200);//
	// tree->insertAk7(23);//
	// tree->insertAk7(99);//
	// tree->insertAk7(1);//
	// tree->insertAk7(50);//
	// tree->insertAk7(90);//
	// tree->insertAk7(250);//
	// tree->insertAk7(47);//
	// // tree->insertAk7(46);
	// // tree->insertAk7(53);//
	// // tree->insertAk7(333);//
	// // tree->insertAk7(88);//
	// // tree->insertAk7(31);//
	// // tree->insertAk7(2);//
	// // tree->insertAk7(999);//
	// // tree->insertAk7(71);
	// //tree->insertAk7(54);//
	// //tree->insertAk7(9);//
	// //tree->insertAk7(19);//
	// //tree->insertAk7(83);
	// //tree->insertAk7(44);//


	tree->printTree();

	// tree->insertAk7(90);
	// tree->insertAk7(50);
	// tree->insertAk7(47);
	// tree->insertAk7(60);
	// tree->insertAk7(220);
	// tree->insertAk7(250); 	
	// tree->insertAk7(300);
	// tree->insertAk7(350);

	// cout << endl;
	// tree->printTree();
	// cout << endl;

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
