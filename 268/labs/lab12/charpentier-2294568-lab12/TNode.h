#ifndef TNODE_H
#define TNODE_H

#include <iostream>

using namespace std;

template <typename T>
class TNode
{
	private:
		T value;
		TNode<T> *left;
		TNode<T> *right;
	public:
		TNode(){ left = NULL; right = NULL; };
		TNode(const T & v);

		void setValue(const T & v);
		void setLeft(TNode<T> *n);
		void setRight(TNode<T> *n);
		TNode<T>* getLeft();
		TNode<T>* getRight();
		T getValue();
};

#include "TNode.cpp"
#endif
