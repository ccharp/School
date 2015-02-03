#ifndef MYDLIST_CPP
#define MYDLIST_CPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "MyDlist.h"

using namespace std;


template <typename T>
MyDlist<T>::MyDlist()
{
	front = NULL;
	back = NULL;
	size = 0;
}

/*
template <typename T>
int MyDlist<T>findNodeIndex(T key)
{
	int x = -1;
	for(int i=0; i < size; i++)
	{
		if(getNode(i)->getValue() == key)
			x = i;
	}
	return x;
}*/

template <typename T>
bool MyDlist<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
int MyDlist<T>::getSize()
{
	return size;
}

template <typename T>
MyDlist<T>::MyDlist(MyDlist<T> & oList)
{
  //call default constructor 
  size = 0;
  front = NULL;
  back = NULL;
 
  for(int i=0; i<oList.getSize(); i++)
    this->push_back(oList.getValue(i));
}

template <typename T>
MyDlist<T>::~MyDlist()
{
	int tsize = size;
	for(int i=0; i < tsize; i++)
	{
		remove(0);
	}
}

template <typename T>
void MyDlist<T>::push_back(T value)
{
	DNode<T> *p = new DNode<T>(value, NULL, NULL);
	if(size == 0)
	{
		front = p;
		back =p;
	}	
	else 
	{
		back->setNext(p);
		p->setPrev(back);
		back = p;
	}
	size++;
}

template <typename T>
DNode<T>* MyDlist<T>::getNode(int index)
{
	DNode<T> *p = front;
	if(size == 0)
	{	
		cout << "In 'getNode'. List is empty. No node to get." << endl;
		return NULL;
	}
	else if(index >= size || index < 0)
	{
		cout << "Problem with index in getElement" << endl;
	}
	else 
	{
		for(int i=0; i<index; i++)
		{
			p = p->getNext();
		}
	}
	return p;
}

template <typename T>
void MyDlist<T>::insert(T value, int index)
{
	if(index >= size || index < 0)
	{
		cout << "Problem with index in insert()." << endl;
	}
	else if(size == 0 || index == size-1)
	{
		push_back(value);
	}	
	else if(index == 0)
	{
		DNode<T> *p = new DNode<T>(value, NULL, front);
		front->setPrev(p);
		front = p;
		size++;
	}
	else 
	{
		DNode<T> *p = new DNode<T>(value, getNode(index-1), getNode(index));
		getNode(index-1)->setNext(p);
		getNode(index)->setPrev(p);
		size++;
	}
}

template <typename T>
void MyDlist<T>::remove(int index)
{	
	if(index >= size || index < 0)
	{
		cout << "Problem with index in getElement" << endl;
	}
	else if(size == 0)
	{
		cout << "At remove(): nothing to delete. size = 0." << endl;
	}
	else if(size == 1)
	{
		delete getNode(0);
		size--;
	}
	else if(index == 0)
	{
		DNode<T> *p = getNode(1);
		getNode(1)->setPrev(NULL);
		delete getNode(0);
		front = p;
		size--;
		
	}
	else if(index == size-1)
	{	
		delete getNode(index);
		getNode(index-1)->setNext(NULL);
		size--;
	}
	else
	{
		DNode<T> *q = getNode(index+1);
		DNode<T> *p = getNode(index-1);
		DNode<T> *x = getNode(index);

		p->setNext(q);
		q->setPrev(p);
		delete x;
		
		size--;
	}
}
template <typename T>
string MyDlist<T>::toString()
{
	stringstream oss;
   
	for(int i=0; i<size; i++)
	{
		oss << this->getNode(i)->getValue() << " ";
	}
	
	return oss.str();
}

template <typename T>
string MyDlist<T>::toRString()
{
	stringstream oss;
   
	for(int i=size-1; i>=0; i--)
	{
		oss << this->getNode(i)->getValue() << " ";
	}
	
	return oss.str();
}
template <typename T>
T MyDlist<T>::getElement(int index)
{
	if(index >= size || index < 0)
	{
		cout << "Problem with index in getElement" << endl;
	}
	else
	{
		DNode<T> * p = this->getNode(index);
		return p->getValue();
	}
}

#endif


