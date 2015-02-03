#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

class Array {

	private:
		static const int CAPACITY_INCREMENT = 200000;
		int capacity;
		int size;
		int* items;

		int comparisons;

		void mergeSort( int low, int high );
		void merge( int low, int middle, int high);
	
	public:
		Array();
		void append(int x);
		void print();
		void reverse();
		void insert( int i, int x);
		int remove( int i );
		void sort();
		int find( int x);
		int binarySearch( int key, int low, int high );	

		int getComparisons();
		~Array();
		
};

#endif /* ARRAY_H_ */
