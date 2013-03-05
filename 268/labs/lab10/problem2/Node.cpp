#include "Node.h"

Node::Node(int v, Node* n)
{
  value = v;
  next = n;
}

void Node::setValue(int v)
{
  value = v;
}

void Node::setNext(Node * n)
{ 
  next = n;
}

