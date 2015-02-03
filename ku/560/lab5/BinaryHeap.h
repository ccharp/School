#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <iostream>
using namespace std;

class BinaryHeap {

private:

	static const int DEFAULT_CAPACITY = 100;
	int* array;
	int size;

	void buildHeap();
	void percolateDown(int item, int hole);
	void percolateUp(int item, int hole);

public:
	
	BinaryHeap(int* data, int n);
	void insert(int item);
	void print();
	bool isEmpty();
	int deleteMin();
	
	int find(int item);
	void remove(int item);
	int deleteMax();
};

#endif /* BINARYHEAP_H_ */
