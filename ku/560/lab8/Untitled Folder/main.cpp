#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "LeftistHeap.h"
#include "SkewHeap.h"
using namespace std;

int main() {
	
	// Create LeftistHeap
	LeftistHeap LHeap;
	
	// Build LHeap using insert
	int v;
	ifstream dataFile ("data.txt");
	if(dataFile.is_open())
		while(dataFile >> v)
		{
			LHeap.insert(v);			
			//LHeap.print();
		}
	dataFile.close();
	
	// Test result of inserts*/
	LHeap.print();
	cout << endl;
	
	// Test findMin
	cout << LHeap.findMin() << endl;
	// Test result of deleteMins
	cout << LHeap.deleteMin() << endl;
	cout << LHeap.deleteMin() << endl;
	cout << LHeap.deleteMin() << endl;
	cout << endl;
	
	// Check final heap
	LHeap.print();
	
	cout << endl << "---" << endl << endl;
	
	// Create SkewHeap
	SkewHeap SHeap;

	// Build SHeap using insert
	ifstream dataFile2 ("data.txt");
	if(dataFile2.is_open())
		while(dataFile2 >> v)
			SHeap.insert(v);			
	dataFile2.close();

	// Test result of inserts
	SHeap.findMin();
	SHeap.print();
	cout << endl;

	// Test findMin
	cout << SHeap.findMin() << endl;
	// Test result of deleteMins
	cout << SHeap.deleteMin() << endl;
	cout << SHeap.deleteMin() << endl;
	cout << SHeap.deleteMin() << endl;
	cout << endl;

	// Check final heap
	SHeap.print();
	
	return 0;
}
