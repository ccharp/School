//class Node for linked list of integers 
#include <iostream>
using namespace std;

class Node
{
  private: 
    int value;
    Node * next;
  public:
    Node(){ next = NULL; };
    Node(int v, Node * n);
    void setValue(int v);
    void setNext(Node * n);
    int getValue(){return value;};
    Node * getNext(){return next;};
};

