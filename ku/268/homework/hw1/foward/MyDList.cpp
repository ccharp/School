#include "MyDlist.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

MyDList::MyDList(string s1)
{	
	//open file
	ifstream fin(s1.c_str());
	if(fin.fail())
	{
		cout << "Failed to open input file." << endl;
		exit(1);
	}

	//front and back start with NULL value
	size = 0;
	front = NULL;
	back = NULL;
	string command;
	int x, y;

	//reads from file command then calls function based on command
	while(fin >> command)
	{	
		if(command == "push_back"){
			fin >> x;
			push_back(x);
		}
		else if(command == "print"){
			toString();
		}
		else if(command == "printR"){
			toRString();
		}
		else if(command == "remove"){
			fin >> x;
			remove(x);
		}
		else if(command == "insert"){
			fin >> x >> y;
			insert(x,y);
		}
		else if(command == "getSize"){
			getSize();
		}
		else if(command == "getElement"){
			fin >> x;
			getElement(x);
		}
		else if(command == "isEmpty"){
			isEmpty();
		}
		else {
			cout << "invalid command" << endl; 
		}
	}
}

//DESTRUCTOR
MyDList::~MyDList()
{
       for(int i=0; i<size; i++)
        {
            remove(i);
        }
}



//push_back definition:
void MyDList::push_back(int element)
{
	//creates new node with next and previous equal to NULL
	DNode *p = new DNode(element, NULL, NULL);
	//if list is empty
	if(size == 0)
	{
		front = p;
		back = p;
	}
	//all other cases
	else
	{
		DNode * s = this->getNode(size-1);
		back->setNext(s);
		p->setPrevious(back);
        	back = s;	
	}

	size++;
 
}

//getSize definition:
int MyDList::getSize()
{
	return size;
}

//getElement definition:
int MyDList::getElement(int index)
{
	//cannot have negative index are an index larger than size
	if(index < 0 || index >= size)
	{
		cout << "Problem with index2" << endl;
		return 0;
	}
	
	//all other cases
	else
	{	//cycles through all nodes ending with index
		cout << "getElement size: " << size << endl;
		DNode *p = this->getNode(index);
		
		return p->getValue();
	}
	//return p->getValue(); 	
}

//getElement definition:
void MyDList::insert(int element, int index)
{
   	//cannot insert into empty list
	if(index < 0 || index >= size)
	{
		cout << "Problem with index3" << endl;
		return;
	}
	//if index is zero, size is zero, new node is created
    else if(index == 0)
    {
        DNode *p = new DNode(element, NULL, front);
        front = p;
        size++;
    }
	//else previous node points to new node and node that was at index points to node replacing it
    else
    {
	//get previous node
	DNode *prev = this->getNode(index-1);
	//get node that will be after
	DNode *curr = this->getNode(index);
        DNode *p = new DNode(element, NULL, NULL);

        p->setNext(curr);
        p->setPrevious(prev);
        curr->setPrevious(p);
        prev->setNext(p);
        
        size++;
    }
}


string MyDList::toString()
{
   stringstream oss;
  // cout << "toString size: " << size << endl;
   for(int i=0; i<size; i++)
   {
	cout << "toString size: " << size << endl;
     	oss << this->getElement(i) << " ";
   }

   return oss.str();
}

string MyDList::toRString()
{
   stringstream oss;
   
   for(int i=size-1; i>=0 ; i--)
   {
     oss << this->getElement(i) << " ";
   }

   return oss.str();
}


//removes designated index from list
void MyDList::remove(int index)
{
    //break if size = 0
    if(size == 0)
    {
        return;
    }
    //if one element: set front and back to NULL 
    else if(size == 1)
    {
        delete getNode(0);
        size--;
    }
    //if first or last node
    else if(index == 0)
    {
        DNode *p = getNode(index+1);
        p->setPrevious(NULL);
        delete getNode(index);
        size--;
    }
    else if(index == size-1)
    {
        DNode *p = getNode(index-1);
        p->setNext(NULL);
        delete getNode(index);
        size--;
    }
    //everything else
    else
    {
        DNode *n = getNode(index+1);
        DNode *prev = getNode(index-1);
        n->setPrevious(prev);
        prev->setNext(prev);
        delete getNode(index);
        size--;
    }  
}

//checks if list is empty
bool MyDList::isEmpty()
{
    return size == 0; 
}
	
//returns node at index index
DNode * MyDList::getNode(int index)
{
	DNode *p = front;
	
	if(index < 0 || index >= size)
	{
		cout << size << endl;
		cout << "Problem with index1" << endl;
		return NULL;
	}
	
	for(int i = 0; i < index; i++)
	{
		p = p->getNext();
	}
	return p;
	
}		
