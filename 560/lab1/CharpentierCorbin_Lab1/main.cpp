#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "List.h"
#include "Array.h"
using namespace std;

int main() {
	
	// Create data structures
	List L;
	Array A;
	
	// Get items
	int x;
	ifstream dataFile ("data.txt");
	if (dataFile.is_open()) {
		while (dataFile >> x){
			L.append(x);
			A.append(x);
		}
		
	}
	dataFile.close();

	// Perform test operations
	L.print();
	L.reverse();
	L.print();
	
	cout << endl;
	
	A.print();
	A.reverse();
	A.print();

	return 0;
}
