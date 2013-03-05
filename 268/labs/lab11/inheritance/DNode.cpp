#ifndef DNODE_CPP
#define DNODE_CPP

#include "DNode.h"

using namespace std;

template <typename T>
DNode<T>::DNode(T v, DNode<T> *p, DNode<T> *n)
{
	setValue(v);
	setNext(n);
	setPrev(p);
}

template <typename T>
DNode<T>::~DNode()
{}

template <typename T>
T DNode<T>::getValue()
{
	return value; 
}

#endif

