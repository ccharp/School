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
void bsTree<T>::remove(TNode<T> *cN, TNode<T> *pN, const T & item)
{
	if(item > cN->getValue())
		remove(cN->getRight(), cN, item);
	else if(item < cN->getValue())
		remove(cN->getLeft(), cN, item);
	else if(item == cN->getValue())
	{
		if(cN->getLeft()==NULL && cN->getRight()==NULL)//is a leaf
		{
			removeLink(cN, pN, NULL);
		}
		else if(cN->hasOnlyLeft())
			removeLink(cN, pN, cN->getLeft());
		else if(cN->hasOnlyRight())
		{
			removeLink(cN, pN, cN->getRight());
		}
		else //node has two children
		{
			if(cN->getValue() < root->getValue())//find largest value on left sub tree
			{
				TNode<T> *bN, *psN = cN;
				getBiggest(cN->getLeft(), cN, psN, cN);
			
			}
			else//find smallest value on right sub tree
			{
				
				TNode<T> *psN = cN;
				getSmallest(cN->getRight(), cN, psN, cN);
	
			}
		}
	}
}

template <typename T>
void bsTree<T>::getBiggest(TNode<T> *cN, TNode<T> *bN, TNode<T> *psN, TNode<T> *realcN)
{
	if(cN->getRight() != NULL)
	{
		getBiggest(cN->getLeft(), cN, psN, realcN);
	}
	else if(cN->getRight() == NULL)
	{	
		realcN->setValue(cN->getValue());
		if(cN->getLeft() == NULL)
			removeLink(cN, bN, NULL);
		else
			removeLink(cN, bN, cN->getLeft());
	}
}

template <typename T>
void bsTree<T>::getSmallest(TNode<T> *cN, TNode<T> *sN, TNode<T> *psN, TNode<T> *realcN)
{
	if(cN->getLeft() != NULL)
	{
		getSmallest(cN->getLeft(), cN, psN, realcN);
	}
	else if(cN->getLeft() == NULL)
	{
		realcN->setValue(cN->getValue());
		if(cN->getRight() == NULL)
		{	
			removeLink(cN, sN, NULL);
		}
		else
		{
			removeLink(cN, sN, cN->getRight());
		}
	}
}

template <typename T>
void bsTree<T>::removeLink(TNode<T> *cN, TNode<T> *pN, TNode<T> *child)
{
	if(cN == root)
	{
		root = child;
	}
	else if(cN == pN->getLeft())
	{
		pN->setLeft(child);
	}
	else
	{
		pN->setRight(child);
	}

	delete cN;
	size--;
}

template <typename T>
TNode<T>* bsTree<T>::search(TNode<T> *node, T value)
{
	if(node == NULL)
		return NULL;
	if(value == node->getValue())
	{
		return node;
	}
	else if(value < node->getValue())
		search(node->getLeft(), value);
	else if(value > node->getValue())
		search(node->getRight(), value);
	
}


template <typename T>
void bsTree<T>::insert(TNode<T> *node, T value)//must be passed root
{	
	if(size==0)
	{
		TNode<T> *t = new TNode<T>(value);
		root = t;
		size++;
	}
	else if(value < node->getValue())
	{
		if(node->getLeft() == NULL)
		{
			TNode<T> *t = new TNode<T>(value);
			node->setLeft(t);
			size++;
		}
		else
			insert(node->getLeft(), value);
	}
	else if(value > node->getValue())
	{
		if(node->getRight() == NULL)
		{
			TNode<T> *t = new TNode<T>(value);
			node->setRight(t);
			size++;
		}
		else
			insert(node->getRight(), value);	
	}
}

template <typename T>
void bsTree<T>::inOrderTraversal(TNode<T> *t)//must be passed root
{
	//cout << "here1" << endl;
	//cout << root->getValue() << endl;
	if(!t) return; 
	inOrderTraversal(t->getLeft());
	cout << t->getValue() << " ";
	inOrderTraversal(t->getRight());
} 

#endif




