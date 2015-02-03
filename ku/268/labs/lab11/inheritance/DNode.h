#ifndef DNODE_H
#define DNODE_H
#include <iostream>

using namespace std;

template <typename T>
class DNode 
{
	private:
		int size;
		T value; 
		DNode<T> *next;
		DNode<T> *previous;
	public:
		DNode<T>(){next = NULL; previous = NULL;};
		DNode<T>(T v, DNode<T> *p, DNode<T> *n);
		~DNode<T>();
		T getValue(); 
		void setPrev(DNode<T> *p){previous = p;}; 
		void setNext(DNode<T> *n){next = n;};
		void setValue(T v){value = v;}; 
		DNode<T> * getNext(){return next;};
		DNode<T> * getPrev(){return previous;};
};

#include "DNode.cpp"
#endif
