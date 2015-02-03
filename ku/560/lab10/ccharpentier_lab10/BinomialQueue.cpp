#ifndef BINOMIALQUEUE_CPP
#define BINOMIALQUEUE_CPP
#include <iostream>
#include "BinomialQueue.h"

using namespace std;

BinomialQueue::BinomialQueue()
{
	currentSize = 0;
	minIndex = -1;
}

void BinomialQueue::insert( int v )
{
	BNode *newNode = new BNode( v );

	if( currentSize == 0 )
	{
		count++; 
		theTrees.push_back( newNode );
		currentSize++;
	}
	else 
	{
		if( theTrees[0] == NULL )
		{
			count++; 
			theTrees[0] = newNode;
		}
		else 
		{
			BNode *node = theTrees[0];
			if( node->key > newNode->key )
			{
				count++; 
				newNode->leftChild = node;
				theTrees[0] = newNode;
			}
			else 
			{
				node->leftChild = newNode;
			}
			combine( 0 );
		}
	}
	findNewMin();
}

void BinomialQueue::combine( int currIndex )
{
	if( currIndex + 1 >= currentSize )
	{
		count++; 
		theTrees.push_back( theTrees[currIndex] );
		theTrees[currIndex] = NULL; 
		currentSize++;
	}
	else if( theTrees[currIndex + 1] == NULL )
	{
		count++; 
		theTrees[currIndex + 1] = theTrees[currIndex];
		theTrees[currIndex] = NULL; 
	} 
	else // Root at next index is not null, so we must append current index to it then repeat.  
	{
		// Get the pointer to append the current index's tree to 
		theTrees[currIndex + 1] = mergeTrees( theTrees[currIndex], theTrees[currIndex + 1] );
		theTrees[currIndex] = NULL;
		combine( currIndex + 1 ); 
	}
}

BNode* BinomialQueue::getFarRightSib( BNode *start )
{
	while( start->nextSibling )
	{
		count++; 
		start = start->nextSibling;
	}
	return start; 
}

int BinomialQueue::findMin()
{
	return theTrees[minIndex]->key;
}

void BinomialQueue::findNewMin()
{
	// Get the first index that's not NULL
	for( int i = 0; i < theTrees.size(); i++ )
	{
		count++; 
		if( theTrees[i] != NULL )
		{
			count++; 
			minIndex = i;
			break;
		}
	}
	for( int i = minIndex; i < theTrees.size(); i++ )
	{
		count++; 
		if( theTrees[i] && theTrees[i]->key < theTrees[minIndex]->key )
		{
			count++; 
			minIndex = i;
		}
	}
}

int BinomialQueue::deleteMin()
{
	if( currentSize <= 0 ) // Assumes not negative numbers in queue. Should throw exception.
	{
		count++; 
		return -1;
	}

	BNode *minNode = theTrees[minIndex];
	int min = minNode->key;
	if( minIndex == 0 )
	{
		count++; 
		delete minNode;
		findNewMin();
		return min;
	}

	BNode *child = theTrees[minIndex]->leftChild;

	theTrees[minIndex] = NULL;
	delete minNode;

	BNode *tmp;
	for( int i = 0; i < theTrees.size(); i++ )
	{
		count++; 
		if( child == NULL )
		{
			count++; 
			break;
		}

		tmp = child;
		child = child->nextSibling;
		tmp->nextSibling = NULL; 

		if( i == 0 )
		{
		count++; 
			if( theTrees[i] == NULL )
			{
				count++; 
				theTrees[i] = tmp;
			}
			else 
			{
				BNode *node = theTrees[0];
				if( node->key > tmp->key )
				{
					count++; 
					tmp->leftChild = node;
					theTrees[0] = tmp;
				}
				else 
				{
					node->leftChild = tmp;
				}
				combine( i );
			}
		}
		else 
		{
			if( theTrees[i] != NULL )
			{
				count++; 
				theTrees[i] = mergeTrees( theTrees[i], tmp );
				combine( i );
			}
			else 
				theTrees[i] = tmp;
		}
	}
	findNewMin();
	return min;
}
// given two trees of the same order, combines then and returns the result. 
BNode *BinomialQueue::mergeTrees( BNode *currRoot, BNode *nextRoot )
{
	BNode *mergePoint;

	if( currRoot->key < nextRoot->key )
	{
		count++; 
		mergePoint = getFarRightSib( currRoot->leftChild );
		mergePoint->nextSibling = nextRoot; 
		
	}
	else 
	{
		mergePoint = getFarRightSib( nextRoot->leftChild );
		mergePoint->nextSibling = currRoot; 
		currRoot = nextRoot; 
	}
	return currRoot;
}

bool BinomialQueue::isEmpty()
{
	return currentSize == 0;
}

void BinomialQueue::printTree( BNode *node )
{
	if( !node )
	{
		return;
	}

	cout << node->key << " ";
	printTree( node->leftChild );
	printTree( node->nextSibling );
}

//Prints queue one tree at a time 
void BinomialQueue::print()
{
	cout << "Printing ------- :" << endl;
	for( int i = 0; i < theTrees.size(); i++ )
	{
		cout << "Tree " << i << ":";
		printTree( theTrees[i] );
		cout << endl;
	}
	cout << endl;
}
void BinomialQueue::makeEmptyTree( BNode *node )
{
	if( !node )
	{
		return;
	}
	
	makeEmptyTree( node->leftChild );
	makeEmptyTree( node->nextSibling );
	delete node; 
}

void BinomialQueue::makeEmpty()
{
	for( int i = 0; i < theTrees.size(); i++ )
	{
		makeEmptyTree( theTrees[i] );
	}
}

BinomialQueue::~BinomialQueue()
{
	makeEmpty();
}

#endif
