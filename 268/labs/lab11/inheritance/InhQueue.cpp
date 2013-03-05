#include <iostream>

#include "InhQueue.h"

template<typename T>
void InhQueue<T>::enqueue(T value)
{
	this->push_back(value);
}

template<typename T> 
T InhQueue<T>::dequeue()
{
	if(this->isEmpty())
	{
		cout << "Queue is emtpy. Cannot dequeue.";
	}
	else
	{
		int temp = this->getNode(0)->getValue();
		this->remove(0);
		return temp;
	}
}
