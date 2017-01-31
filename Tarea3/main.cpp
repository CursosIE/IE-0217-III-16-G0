#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void selectionSort (char* inputFile) {
    int size = 0;
    int temp = 0;
    
    ifstream dataFile;
    dataFile.open(inputFile);
   	while (!dataFile.eof()) {
   		dataFile >> temp;
   		++size;
   	}
    dataFile.close();
    
    int myVector[size];

    dataFile.open(inputFile);

    for (int index = 0; index < size; ++index)
    	dataFile >> myVector[index];

    dataFile.close();

    //selection sort
    for (int n = 0; n <= size - 1; ++n){
		for (int m = 0; m <= size; ++m) {
			if (myVector[n] < myVector[m]) {
				temp = myVector[n];
				myVector[n] = myVector[m];
				myVector[m] = temp;
			}
		}
	}

	//print
	for (int i = 0; i < size; ++i) {
		cout << myVector[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
    selectionSort(argv[1]);
    return 0;
}
