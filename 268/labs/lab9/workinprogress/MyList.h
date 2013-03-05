//AUTHOR: PROFESSOR LUKE HUAN
//EDITED by: Corbin Charpentier

//class MyList implement a single linked list ADT
#include <iostream>
#include <vector>
#include <string>
#include "node.h"
#include "MyDListIndexOutOfRange.h"
using namespace std;

class MyList
{
  private: 
    int size;
    node * header;
    node * getNode(int i);

  public:
    MyList(){size =0; header = NULL;};
    MyList(string f);
    MyList(MyList & oList);
    ~MyList();
    int getSize(){ return size; };
    void insert(int index, int item) throw(MyDListIndexOutOfRange);
    int remove(int index);
    void push_back(int item);
    int  getValue(int index); 
    string toString();
};

