//class MyList implement a single linked list ADT
#include <iostream>
#include <vector>
#include <string>

#include "Node.h"
using namespace std;

class MyList
{
  private: 
    int size;
    Node * header;
    Node * getNode(int i);

  public:
    MyList(){size =0; header = NULL;};
    MyList(string f);
    MyList(MyList & oList);
    ~MyList();
    int getSize(){ return size; };
    void insert(int index, int item);
    int remove(int index);
    void push_back(int item);
    int  getValue(int index); 
    string toString();
	void sort();
};

