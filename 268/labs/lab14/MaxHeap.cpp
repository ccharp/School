#ifndef MAXHEAP_CPP
#define MAXHEAP_CPP

#include "MaxHeap.h"
#include <iostream>
#include <sstream>

using namespace std;

//constructor
template <typename T>
MyHeap<T>::MyHeap()
{
	size = 1;	
}

//inserts node at index 'size' and calls trickledown
template <typename T>
void MyHeap<T>::insert(T value)
{
	a[size] = value;
	trickleDown(size, size);
	size++;
}

//trickles node down if it is larger in value than its parent
template <typename T>
void MyHeap<T>::trickleDown(int i, int n)
{	
	if(i <= 1)
		return;
	else
	{
		int parent = (i+1)/2;
		if(a[i] > a[parent])//swap values
		{
			int temp; 
			temp = a[i];
			a[i] = a[parent];
			a[parent] = temp;
		}
		trickleDown(parent, size);
	}
}

//assigns value at index size to index 1 and calls trickle up.
template <typename T>
void MyHeap<T>::deleteMax()
{

	if(size == 2)
		size--;
	else
	{
		a[1] = a[size-1]; //assignes value at index size to index 1.

		size--;
		trickleUp(1); 
	}
}

//checks it node at index 1 is less than it's children. if true, swap. 
template <typename T>
void MyHeap<T>::trickleUp(int i)
{
	int left = 2*i;
	int right = 2*i+1;
	int child = left;

	//find children and checks if it's out of range
	if(a[left] < a[right])
		child = right;
	if(right >= size)
		child = left;
	if(left > size && right > size)
		return;

	//base case index greater than size-1
	if(i >= size-1)
		return;
	else if(a[i] < a[child]) //swap case
	{	
		int temp; 
		temp = a[i];
		a[i] = a[child];
		a[child] = temp;
	
		trickleUp(child);//recursive call
	}
	else
		return;	
}

//outputs 
template <typename T>
string MyHeap<T>::toString()
{
	stringstream oss;
	for(int i=1; i <= size-1; i++)
	{
		oss << a[i] << " ";
	}
	return oss.str();
}

#endif
