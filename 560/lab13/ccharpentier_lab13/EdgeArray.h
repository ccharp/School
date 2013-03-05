#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include "Edge.h"

class EdgeArray {

	private:
		static const int CAPACITY_INCREMENT = 100000000;
		int capacity;
		int size;
		Edge* items;

		int comparisons;

		void mergeSort( int low, int high );
		void merge( int low, int middle, int high);

	public:
		EdgeArray();
		void append(int v, int w, int cost );
		void print();
		void printSimple();
		void insert( int i, int v, int w, int cost );
		Edge remove( int i );
		void sort();
		int getSize();
		Edge operator[] (int i);

		int getComparisons();
		~EdgeArray();
		
};

#endif /* ARRAY_H_ */
