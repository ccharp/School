#ifndef TNODE_CPP
#define TNODE_CPP

#include "TNode.h"

using namespace std;

template <typename T>
TNode<T>::TNode(const T & v)
{	
	left = NULL;
	right = NULL;
	value = v;
}

template <typename T>
void TNode<T>::setLeft(TNode<T> *n)
{
	left = n;
}

template <typename T>
void TNode<T>::setRight(TNode<T> *n)
{
	right = n;
}

template <typename T>
T TNode<T>::getValue()
{
	return value;
}

template <typename T>
TNode<T> * TNode<T>::getLeft()
{
	return left;
}

template <typename T>
TNode<T> * TNode<T>::getRight()
{	
	return right;
}

template <typename T>
void TNode<T>::setValue(const T & v)
{
	value = v;
}
#endif
