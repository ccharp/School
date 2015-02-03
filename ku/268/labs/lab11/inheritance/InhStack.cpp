#include <iostream>

#include "InhStack.h"
using namespace std;


template<typename T>
void InhStack<T>::push(T value)
{
	this->push_back(value);
}

template<typename T> 
T InhStack<T>::pop()
{
	if(this->isEmpty())
	{
		cout << "Stack is emtpy. Cannot dequeue.";
	}
	else
	{
		int temp = this->getNode(this->getSize()-1)->getValue();
		this->remove(this->getSize()-1);
		return temp;
	}
}

