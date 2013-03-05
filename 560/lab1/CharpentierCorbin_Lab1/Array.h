#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

class Array {

	private:
		static const int CAPACITY_INCREMENT = 20;
		int capacity;
		int size;
		int* items;
	
	public:
		Array();
		void append(int x);
		void print();
		void reverse();
		~Array();
		
};

#endif /* ARRAY_H_ */
