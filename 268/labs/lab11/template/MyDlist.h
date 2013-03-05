#ifndef MYDLIST_H
#define MYDLIST_H

#include "DNode.h"
#include <iostream>

using namespace std;

template <typename T>
class MyDlist
{
	private: 
		DNode<T> * front;
		DNode<T> * back;
		int size;
	public: 
		MyDlist();
		MyDlist(MyDlist<T> & oList);
		~MyDlist();
		void remove(int index);
		void push_back(T value);
		void insert(T value, int index);
		int getSize(){return size;};
		bool isEmpty(){return size == 0;};
		DNode<T> * getNode(int index);
		string toString();
		T getElement(int index);
		//string toRString();
};

#include "MyDlist.cpp"
#endif
