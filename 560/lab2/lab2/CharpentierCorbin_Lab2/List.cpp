#include "List.h"

using namespace std;

List::List()
{
    first = NULL;
    last = NULL;
	size = 0;
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
	size++;
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

			// When last is reached, exit the loop
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

Node* List::getNode( int i )
{
	if( first )
	{
		Node *iter = first;
		int count = 0;
		while( iter )
		{
			if( count == i )
			{
				return iter;
			}
			iter = iter->next;
			count++;
		}
	}
	return NULL;	
}

int List::find( int x )
{
	Node *iter = first;
	int i = 0;
	while( iter )
	{
		if( iter->value == x )
		{
			return i;
		}
		iter = iter->next;
		i++;
	}
	return -1;
}

bool List::isEmpty()
{
	return( size == 0 );
}

void List::insert( int i, int x )
{
	// This Method assumes no insertion on empty list

	Node *newNode = new Node( x, NULL );

	if( i > size || i < 0 )
	{
		cout << "Index, " << i << ", out of bounds for insertion." << endl;
	}
	else
	{	
		if( i == 0 )
		{
			newNode->next = first;
			first = newNode;
		}
		else if( i == size || i == size-1 )
		{
			append( x );
		}
		else
		{
			Node *prevNode = getNode( i-1 );
			Node *ithNode = getNode ( i );
			newNode->next = ithNode;
			prevNode->next = newNode;
		}
		size++;
	}
}

int List::remove( int i )
{
	// Assumes no negative values
	if( i >= size || i < 0 )
	{
		cout << "Index, " << i << ", out of bounds for removal." << endl;
		return -1;
	}
	else
	{
		Node *delNode = getNode( i );
		int value = delNode->value;
		if( i == 0 )
		{
			first = first->next;
			delete delNode;
		}
		else if( i == size-1 )
		{
			last = getNode( i-1 );
			last->next = NULL;
			delete delNode;
		}
		else
		{
			Node *prevNode = getNode( i-1 );
			prevNode->next = delNode->next;
			delete delNode;
		}
		size--;
		return value;
	}
}
































