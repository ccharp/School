#include "MyQueue.h"
#include <sstream>
#include <iostream>

MyQueue::MyQueue()
{
	back = -1;
}

void MyQueue::enqueue(int x)
{
	if(back < 99)
	{
		back++;
		queue[back] = x;
	}
	else
		cout << "Queue is full" << endl;
}

void MyQueue::dequeue()
{

	if(back >= 0){
		for(int i = 1; i < back; i++)
		{
			queue[i-1] = queue[i];
		}
		back--;
	}
	else
		cout << "Queue is empty: cannot remove." << endl;
}


