#ifndef BSTREE_H
#define BSTREE_H

#include "TNode.h"
#include <iostream>

using namespace std;

template <typename T>
class bsTree
{
	private:
		int size;
		TNode<T> * root;

		void insert(TNode<T> *root, T value);
		void inOrderTraversal(TNode<T> *t);
	public:
		bsTree();
		//~bsTree();

		void insert1(T value){insert(root, value);};
		void inOrderTraversal(){inOrderTraversal(root);};
};

#include "bsTree.cpp"
#endif
