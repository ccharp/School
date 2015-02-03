#ifndef TNODE_CPP //prevents recompilation
#define TNODE_CPP

#include "TNode.h"

using namespace std;

template <typename T>
bool TNode<T>::hasOnlyLeft()				//retusn true of node has only left child
{
	return (right == NULL && left != NULL);
}

template <typename T>
bool TNode<T>::hasOnlyRight()				//returns true if node has only right child
{
	return (left == NULL && right != NULL);
}

template <typename T>
TNode<T>::TNode(const T & v)				//constructor, assigns value to v. 
{	
	parent = NULL;
	left = NULL;
	right = NULL;
	value = v;
}

template <typename T>
void TNode<T>::setLeft(TNode<T> *n)			//sets pointer 'left'
{
	left = n;
}

template <typename T>
void TNode<T>::setRight(TNode<T> *n)		//sets pointer 'right'
{
	right = n;
}

template <typename T>
void TNode<T>::setParent(TNode<T> *n)		//sets pointer 'parent'
{
	parent = n;
}

template <typename T>
T TNode<T>::getValue()						//returs value of node, can be of any type
{
	return value;
}

template <typename T>
TNode<T> * TNode<T>::getLeft()				//returns pointer to left node
{
	return left;
}

template <typename T>
TNode<T> * TNode<T>::getRight()				//returns pointer to right node
{	
	return right;
}

template <typename T>
void TNode<T>::setValue(const T & v)      //sets value of node to v.
{
	value = v;
}
#endif
