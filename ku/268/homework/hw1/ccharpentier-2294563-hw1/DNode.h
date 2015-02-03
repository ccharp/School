//DNode.h
//Declares class 'DNode'


#include <iostream>

using namespace std;

//class: DNode
class DNode 
{
	//private variables include pointers 'next' and 'previous' of type DNode
	private:
		int value; 
		DNode *next;
		DNode *previous;
	public:
		//Constructor with no parameters sets pointers 'next' and 'previous' to NULL
		DNode(int x){next = NULL; previous = NULL;};
		DNode(int v, DNode *p, DNode *n);
       		DNode(){};

		//destructor is not needed to implement this program
		~DNode();

		//returns value of node
		int getValue(); 

		//sets previous to point to previous node
		void setPrevious(DNode *p){previous = p;}; 

		//sets next to point to next node
		void setNext(DNode *n){next = n;};

		//sets value variable of DNode
		void setValue(int v){value = v;}; 

		//returns next DNode
		DNode * getNext(){return next;};

		//returns previous DNode
		DNode * getPrev(){return previous;};
};



