#ifndef LIST_H_
#define LIST_H_

#include "Node.h"
#include <iostream>
using namespace std;

class List {
	
	private:
		Node* first;
		Node* last;

		int size;

		Node* getNode(int i);
	
	public:
		List();
		void append(int x);
		void print();
		void reverse();
		bool isEmpty();
		void insert(int i, int x);
		int remove(int i);
		int find(int x);
		~List();
	
};

#endif /* LIST_H_ */
