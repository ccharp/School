#ifndef MINMAXHEAP_H_
#define MINMAXHEAP_H_

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class MinMaxHeap {

private:
	
	static const int DEFAULT_CAPACITY = 100;
	int* array;
	int size;
	
	// Information Methods
	void swapArrayIndex( int i, int j );
	bool atMinLevel(int i);
	int getParent(int child);
	int getGrandParent(int child);
	bool hasParent(int child);
	bool hasGrandParent(int child);
	int getFirstChild(int parent);
	int getFirstGrandChild(int parent);
	bool hasChildren(int parent);
	bool isGrandChild(int child, int parent);
	int getMinIndex();
	int getMaxIndex();
	int findMinChild(int parent);
	int findMaxChild(int parent);

	// Manipulation Methods
	void buildHeap();
	void trickleDown(int i);
	void trickleDownMin(int i);
	void trickleDownMax(int i);
	void bubbleUp(int i);
	void bubbleUpMin(int i);
	void bubbleUpMax(int i);
	
public:
	
	MinMaxHeap(int* data, int n);
	bool isEmpty();
	void print();
	void insert(int item);
	int findMin();
	int findMax();
	int deleteMin();
	int deleteMax();
	void increaseKey(int i, int amount);
	void decreaseKey(int i, int amount);
	~MinMaxHeap();

};

#endif /* MINMAXHEAP_H_ */
