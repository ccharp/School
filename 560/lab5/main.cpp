#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "BinaryHeap.h"
using namespace std;

int main() {
	
	// Get data size
	int n;
	ifstream dataFile ("data.txt");
	if(dataFile.is_open())
		dataFile >> n;
		
	// Fill initial data to array
	int* data = new int[n];
	int v;
	int i = 0;
	if(dataFile.is_open()){
		while(dataFile >> v){
			data[i] = v;
			i++;
		}
	}	
	dataFile.close();

	// Test buildHeap
	BinaryHeap heap(data, n);
	heap.print();
	
	// Test insert
	heap.insert(35);
	heap.insert(25);
	heap.insert(40);
	heap.insert(45);
	heap.insert(30);
	heap.insert(15);
	heap.insert(20);
	heap.print();
	
	// Test find
	cout << heap.find(17) << endl;
	cout << heap.find(35) << endl;
	cout << heap.find(10) << endl;
	cout << heap.find(4) << endl;
	
	// Test remove
	heap.remove(35);
	heap.remove(30);
	heap.print();
	
	// Test deleteMax
	heap.deleteMax();
	heap.deleteMax();
	heap.print();
		
	// Test deleteMin and isEmpty
	//while(!heap.isEmpty())
	//	cout << heap.deleteMin() << " ";
	//cout << endl;

	return 0;
}
