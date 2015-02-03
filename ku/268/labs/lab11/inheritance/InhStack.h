#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "MyDlist.h"
using namespace std;
template <typename T>
class InhStack : public MyDlist<T>
{
	public:
		InhStack(){MyDlist<T>();};
		void push(T value);
		T pop();
};

#include "InhStack.cpp"
#endif
