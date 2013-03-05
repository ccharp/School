//DNode.cpp
//Class 'DNode' function definitions

#include "DNode.h"

using namespace std;

//builds object DNode with 3 parameters: a value and  a pointer to previous and next node
DNode::DNode(int v, DNode *p, DNode *n)
{
	setValue(v);
	setNext(n);
	setPrevious(p);
}

//constructor is not necessary for this exercise 
DNode::~DNode(){}

//returns value of DNode
int DNode::getValue()
{
	return value; 
}



