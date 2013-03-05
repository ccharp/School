#include "List.h"

using namespace std;

List::List()
{
    first = NULL;
    last = NULL;
}

List::~List()
{
	if( first )
	{
		while( first )
		{
			Node *curr = first;
			first = first->next;
			delete curr;
		}
	}
}

void List::append( int x )
{
	// If the list is empty, allocate node and point first and last to it
    if( !first )
    {
        first = new Node( x, NULL );
        last = first;
    }
	// Else append the new node at the end of the list
    else
    {
        last->next = new Node( x, NULL );
		last = last->next;
    }
}
    
void List::print()
{
	// If the list isn't empty, print it
	if( first )
	{
		Node *iter = first;
		// Loop while iter isn't null
		while( iter )
		{
			cout << iter->value << " ";
			iter = iter->next;
		}
		cout << endl;
	}
}

void List::reverse()
{
	// Only 1 node in the list
	if( first == last )
	{
		return;
	}
	// 2 nodes in the list
	else if( first->next == last )
	{
		int temp = first->value;
		first->value = last->value;
		last->value = temp;		
	}
	// There are atleast 3 nodes in the list
	else 
	{	
		Node *curr = first;
		Node *currNext = first->next;
		Node *nextNext = currNext->next;

        // Loops while not at end of list
		while( true )
		{
			currNext->next = first;
			curr->next = nextNext;
			first = currNext;

			currNext = curr->next;
			nextNext = currNext->next;

			// When last is reach, exit the loop
			if( !nextNext )
			{
				currNext->next = first;
				first = currNext;
				curr->next = NULL;
				last = curr;
				break;
			}	
		}		
	}
}

Node* List::getNode(int i)
{
	if( first )
	{
		Node* iter = first;
		int count = 0;
		while( iter )
		{
			if( count == i)
			{
				return iter;
			}
			
			iter = iter->next;
			count++;
		}
	}
	return NULL;	
}

bool List::isEmpty()
{
	return !(first == NULL);
}

void List::insert( int i, int x )
{
	
}





























