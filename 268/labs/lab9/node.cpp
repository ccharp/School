//AUTHOR: PROFESSOR LUKE HUAN
//EDITED by: Corbin Charpentier

#include "node.h"

node::node(int v, node* n)
{
  value = v;
  next = n;
}

void node::setValue(int v)
{
  value = v;
}

void node::setNext(node * n)
{ 
  next = n;
}

