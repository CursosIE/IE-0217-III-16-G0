#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int binarySearch (int myVector[], int size, int find) {
	int min = 0;
	int max = size;
	int flag = 0;

	cout << find << endl;

	clock_t begin = clock();

	while (flag == 0) {
		if (myVector[(min + max) / 2] == find) {
            flag = 1;
            clock_t end = clock();
            cout << 1 << endl;
            cout << "\ntime: " << (1000000* (end - begin)) / CLOCKS_PER_SEC << "\u00B5s" << endl;
            return 1;
        }
        else if (myVector[(min + max) / 2] > find)
            size = (min + max) / 2;
        else if (myVector[(min + max) / 2] < find)
            min = (min + max) / 2;
       
       if(max == min + 1) {
        	clock_t end = clock();
        	cout << 0 << endl;
        	cout << "\ntime: " << (1000000* (end - begin)) / CLOCKS_PER_SEC << "\u00B5s" << endl;
        	return 0;
        }
	}
	return 0;
}

void selectionSort (int myVector[], int size) {
    //selection sort
    clock_t begin = clock();
    int temp = 0;
    int posMin = 0;
    for (int n = 0; n < size - 1; n++){
    	posMin = n;
		for (int m = n + 1; m < size; m++) {
			if (myVector[m] < myVector[posMin]) 
				posMin = m;
		}
		if (posMin != n) {
			temp = myVector[n];
			myVector[n] = myVector[posMin];
			myVector[posMin] = temp;
		}
	}
	clock_t end = clock();

	for (int i = 0; i < size; ++i) {
		cout << myVector[i] << " ";
	}

	cout << "\ntime: " << (1000000* (end - begin)) / CLOCKS_PER_SEC << "\u00B5s" << endl;
}

int main(int argc, char *argv[]) {
	int find = 0;
	int size = 0;
    int temp = 0;
    int ss = true;
    char* fileName;

    if (strcmp (argv[1], "ss") ==  0)
    	fileName = argv[2];
    else {
    	find = atoi(argv[2]);
    	fileName = argv[3];
    	ss = false;
    }

    //cout << "find : " << find << endl;

    ifstream dataFile;

    dataFile.open(fileName);

   	while (!dataFile.eof()) {
   		dataFile >> temp;
   		size += 1;
   	}

    dataFile.close();

    size -= 1;
    
    int myVector[size];

    dataFile.open(fileName);

    for (int index = 0; index < size; ++index)
    	dataFile >> myVector[index];

    dataFile.close();

    cout << size << endl;

    if (ss)
    	selectionSort(myVector, size);
    else 
    	return binarySearch(myVector, size, find);
    
    return 0;
}
