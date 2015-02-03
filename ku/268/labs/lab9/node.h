//AUTHOR: PROFESSOR LUKE HUAN
//EDITED by: Corbin Charpentier

//class Node for linked list of integers 
#include <iostream>
using namespace std;

class node
{
  private: 
    int value;
    node * next;
  public:
    node(){ next = NULL; };
    node(int v, node * n);
    void setValue(int v);
    void setNext(node * n);
    int getValue(){return value;};
    node * getNext(){return next;};
};

