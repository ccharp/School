#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <iostream>
using namespace std;

class BinaryHeap {

private:

	static const int DEFAULT_CAPACITY = 100000;
	int* array;
	int size;
	int count;

	void buildHeap();
	void percolateDown(int item, int hole);
	void percolateUp(int item, int hole);

public:
	int getCount() 
	{
		return count;
	}

	BinaryHeap(int* data, int n);
	~BinaryHeap();
	void insert(int item);
	void print();
	bool isEmpty();
	int deleteMin();
	
	int find(int item);
	void remove(int item);
	int deleteMax();
	int findMin();
	int findMax();
	int getComparisons() {
		return count;
	}
	void resetComparisons() {
		count = 0;
	}
};

#endif /* BINARYHEAP_H_ */
