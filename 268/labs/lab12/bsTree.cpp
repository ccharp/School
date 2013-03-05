#ifndef BSTREE_CPP
#define BSTREE_CPP

#include "bsTree.h"
#include <iostream>
using namespace std;

template <typename T>
bsTree<T>::bsTree()
{
	root = NULL;
	size = 0;
} 

template <typename T>
void bsTree<T>::insert(TNode<T> *node, T value)//must be passed root
{	
	TNode<T> *t = new TNode<T>(value); 

	if(size == 0)
	{
		root = t; 	
	}
	else if(value < node->getValue())
	{
		if(node->getLeft() != NULL)
			insert(node->getLeft(), value);
		else 
			node->setLeft(t);
	}
	else if(value > node->getValue())
	{
		if(node->getRight() != NULL)
			insert(node->getRight(), value);
		else 
			node->setRight(t);
	}
	size++;
}

template <typename T>
void bsTree<T>::inOrderTraversal(TNode<T> *t)//must be passed root
{
	if(!t) return; //t is NULL
	inOrderTraversal(t->getLeft());
	cout << t->getValue() << " ";
	inOrderTraversal(t->getRight());
} 

#endif




