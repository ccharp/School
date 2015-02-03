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

		void insert(TNode<T> *node, T value);
		void inOrderTraversal(TNode<T> *t);
		void removeLink(TNode<T> *p1, TNode<T> *p2, TNode<T> *p3);
		void remove(TNode<T> *cN, TNode<T> *pN, const T & item);

		void getSmallest(TNode<T> *cN, TNode<T> *sN, TNode<T> *psN, TNode<T> *realcN);
		void getBiggest(TNode<T> *cN, TNode<T> *bN, TNode<T> *psN, TNode<T> *realcN);
		TNode<T>* search(TNode<T> *node, T value);	
		
	public:
		bsTree();
		//~bsTree();

		void insert(T value){insert(root, value);};
		void remove(T value){remove(root, NULL, value);};
		void inOrderTraversal(){inOrderTraversal(root);};
		TNode<T>* search(T value){return search(root, value);};
		
};

#include "bsTree.cpp"
#endif
