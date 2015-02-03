//AUTHOR: PROFESSOR LUKE HUAN
//EDITED by: Corbin Charpentier

#include <iostream>
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
 
node * MyList::getNode(int index)
{
  node * p = header;

  if( index <0 || index >= size ) return NULL;

  for( int i=0; i< index; i++)
    p = p->getNext();
  
  return p;
}

void MyList::insert(int index, int item) throw(MyDListIndexOutOfRange)
{
  //check boundary
  if( index < 0 || index >= size )
	{	string something(something);
		//cout << "Exception found. Index " << index << " is out of range" << endl;
		throw(MyDListIndexOutOfRange(something));
    }

  //get the previous node
  node * p = this->getNode(index-1);
  
  if( p != NULL)
  {
    node * q = new node(item, NULL);
    node * pnext = p->getNext();
    p->setNext(q);
    q->setNext(pnext);
  } 
  else
  {
    //update header 
    node * q = new node(item, NULL);
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
  node * p = this->getNode(index-1);
  node * q;
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
  node * p = new node(item, NULL);
  if( size == 0)
    header = p;
  else
  { 
    node * q = this->getNode(size-1);
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
     node * p = this->getNode(index);
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

