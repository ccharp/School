#ifndef INHQUEUE_H
#define INHQUEUE_H

#include <iostream>
#include "MyDlist.h"
using namespace std;
template <typename T>

class InhQueue : public MyDlist<T>
{
	public:
		InhQueue(){MyDlist<T>();};
		void enqueue(T value);
		T dequeue();
};

#include "InhQueue.cpp"
#endif
