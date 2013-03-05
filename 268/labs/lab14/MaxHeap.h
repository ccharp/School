#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>

using namespace std;

const int MaxSize = 100;

template <typename T>
class MyHeap
{
	private:
		int size;
		T a[MaxSize];
		void trickleUp(int i); //checks if a[i] is greater than its parent, if it is, swaps
		void trickleDown(int i, int n); //checks if a[i] is less than it's child, if it is, swaps
	public:
		MyHeap();//constructor
		void insert(T value);//inserts new node at back then calls trickle up
		void deleteMax();//swaps first and last index, then trickles first index up.
		string toString();//converst priority queue to string and returns it
};

#include "MaxHeap.cpp"
#endif 
