#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "BinomialQueue.h"
using namespace std;

int main() {
	
	// Create BinomialQueue
	BinomialQueue Q;

	// Build Q using insert
	int v;
	ifstream dataFile ("data.txt");
	if(dataFile.is_open())
	{
		while(dataFile >> v)
		{
			Q.insert(v);			
		}
	}
	dataFile.close();

	// Test findMin
	cout << Q.findMin() << endl;
	// Test result of deleteMins
	cout << Q.deleteMin() << endl;
	cout << Q.deleteMin() << endl;
	cout << Q.deleteMin() << endl;
	cout << endl;


	return 0;
}
