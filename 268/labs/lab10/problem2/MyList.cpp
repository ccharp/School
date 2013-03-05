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
//---------------------------------------------------------------------------
//SORTING FUNCTION
void MyList::sort()
{
	int temp;
	int temp2;
	int sizeM = size;
	for(int count=0; count < size; count++)
	{
		for(int i=0; i<sizeM-1; i++)
		{
			if(getValue(i) > getValue(i+1))
			{
				temp = getValue(i);
				temp2 = getValue(i+1);
				getNode(i)->setValue(temp2);
				getNode(i+1)->setValue(temp); 
			}
		}	
		sizeM--;
	}	
}



































