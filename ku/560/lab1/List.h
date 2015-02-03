#ifndef LIST_H_
#define LIST_H_

#include "Node.h"
#include <iostream>
using namespace std;

class List {
	
	private:
		Node* first;
		Node* last;
	
	public:
		List();
		void append(int x);
		void print();
		void reverse();
		~List();
	
};

#endif /* LIST_H_ */
