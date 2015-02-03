#include <iostream>
#include "DNode.h"
#include <string>

using namespace std;

class MyDList
{
private:
	int size;
	DNode *front;
	DNode *back;

	//utility function
	DNode * getNode(int index); 
public:
	//constructor, destructor
	MyDList(string s1);
	MyDList(){size =0; front = NULL; back = NULL;};
	~MyDList(); 
	
	//FUNCTIONS
	void insert(int element, int index);
	void remove(int index);
	void push_back(int element);
	int getElement(int index); 
	int getSize();
	bool isEmpty();
	string toString();
	string toRString(); 
};


