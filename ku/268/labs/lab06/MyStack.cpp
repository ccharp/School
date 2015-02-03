#include "MyStack.h"
#include <iostream>
#include <sstream>

MyStack::MyStack();
{
	index = -1;
}

void MyStack::push(int x)
{
	if(index < 100)
	{
		index++;
		stack[index] = x;
	}
	else
		cout << "Stack is full" << endl;
}

void MyStack::pop()
{
	if(index < 0)
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		index--;
	}
}

string MyStack::toString()
{
   stringstream oss;
   
   for(int i=index; i>=0; i--)
   {
     oss << stack[i] << " ";
   }

   return oss.str();
}

int MyStack::size()
{
	return index+1;
}

