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
};

//---------------------------------------------------------------

#include <fstream>
#include <sstream>
#include "stdlib.h"
#include "MyList.h"

//constructor
MyList::MyList(string f)
{
  //open a file
  ifstream inFile(f.c_str());
  int t;

  //call default constructor
  size =0;
  header = NULL;

  while(  inFile >> t)
  {
    this->push_back(t);
  }
}

//deep copy in constructor
MyList::MyList(MyList & oList)
{
  //call default constructor 
  size = 0;
  header = NULL;
 
  for(int i=0; i<oList.getSize(); i++)
    this->push_back(oList.getValue(i));
}

MyList::~MyList()
{
  for( int i=0; i< size; i++)
    this->remove(0);
}
 
Node * MyList::getNode(int index)
{
  Node * p = header;

  if( index <0 || index >= size ) return NULL;

  for( int i=0; i< index; i++)
    p = p->getNext();
  
  return p;
}

void MyList::insert(int index, int item)
{
  //check boundary
  if( index < 0 || index >= size )
     return;

  //get the previous node
  Node * p = this->getNode(index-1);
  
  if( p != NULL)
  {
    Node * q = new Node(item, NULL);
    Node * pnext = p->getNext();
    p->setNext(q);
    q->setNext(pnext);
  } 
  else
  {
    //update header 
    Node * q = new Node(item, NULL);
    if( header != NULL) 
      q->setNext(header);
    header = q;
  }
  size++;
}

int MyList::remove(int index)
{
  //check boundary
  if( index < 0 || index >= size) 
    return 0;

  //locate the locatin of theh ndoe at location index -1
  Node * p = this->getNode(index-1);
  Node * q;
  int r;

  if( p != NULL)
  {
    //q must not be NULL
    q = p->getNext();
    p->setNext(q->getNext());
  }
  else 
  {
    //update header
    q = header;
    header = header->getNext();
  }
  r = q->getValue();
  delete q; 
  size--; 
  return r;
}

void MyList::push_back(int item)
{
  Node * p = new Node(item, NULL);
  if( size == 0)
    header = p;
  else
  { 
    Node * q = this->getNode(size-1);
    q->setNext(p);
  }
  size++;
}

int MyList::getValue(int index)
{
   if( index <0 || index >= size) 
     exit(1);
   else
   {
     Node * p = this->getNode(index);
     return p->getValue();
   }
}

string MyList::toString()
{
   stringstream oss;
   
   for(int i=0; i<size; i++)
   {
     oss << this->getValue(i) << " ";
   }

   return oss.str();
}

//----------------------------------------------------------------------------------------------------------------------

//MORE REFERENCE


void MyList::push_back(int item)
{
	Node * p = new Node(item); //creates mew mode. Next step: find next node of list
	Node * cp = header;
	if(size == 0){header = p; size++}
	while(cp->getNext())
	{
		cp = cp -> getNext(); 
	}//at end of list
	cp -> setnext(p); 
	size++;
}

//constructor //header points to front of list
MyList::MyList(string f)
{
	//open file
	ifstream infile(f.c_str());
	
	//initialize size and header
	int size(0);
	int header = NULL;
	
	//add node to end of list push_back function
	while(infile>>t)
	{
		//push_back(t)
		this->push_back(t); //"this" is == "this" points to function
		
		//update header and size
		
	}
}

//DESTRUCTOR
MyList::~MyList()
{	
	Node *t;

	for(int i=0; i < size; i++)
	{
		t = header; //two pointers point to same thing
		header = header -> getNext(); //update header
		delete t;  //now it's ok to delete t
		(header = NULL)
	}
	//set size equeal to zero
	size = 0; //not necessary but not a bad practice
----------------------------------------OR
	for(int i=0; i<size; i++)
	{
		this->remove(0); //remove() is function we write
	}
}

int MyList::getValue(int index)
{
	//error handling
	if(index < 0 || index > size)
	{
		exit(1); 
	}

	//assuming index is in range of the list
	Node *t = header;
	for(int i=0; i < index; i++)
	{
		t = t -> getNext();
	}
	return t->getValue(); 
--------------OR
	return this->getNode(index);
}

MyList::insert(int index, int v)
	//work through list until index is found
{	//creates new node 
	Node * t = new Node(v);
	if(index > 0)
	{
		//get previes node
		Node * p1 = this->getNode(index-1);

		//inserted number must point to next number
		Node * pastI=pI->getNode(index); 

		p1->setNext(t); 

		//increase size
		size++
	}
	else{
		t->setNext(pastI)
		t->setNext
}

MyList::remove(int index)

MyList::getValue()

//UTILITY FUNCTION
//works through list and returns pointer to particular node
Node * MyList::getNode(int index)
{
	Node * t = header; 
	for(int i=0; i<index; i++)
	{
		t = t->getNext();
	}	
	return t; 
}




