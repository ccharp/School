#include "LeftistHeap.h"

using namespace std;

LeftistHeap::LeftistHeap()
{
	root = NULL; 
}

void LeftistHeap::print()
{
	print( root, 0 );
}		

void LeftistHeap::print( LNode* h, int level) 
{
	if( !h )
	{
		return;
	}

	print( h->right, level+1 );
	//level--;

	for( int i = 0; i < level; i++ )
	{
		cout << "	";
	}
	cout << h->value <<"("<< h->rank <<")";
	if( !h->left && h->right )
	{
		cout << "/";
	}
	else if( h->left && !h->right )
	{
		cout << "\\";
	}
	else if( h->left && h->right )
	{
		cout << "<";
	}
	cout << endl;

	print( h->left, level+1 );
	
}

int LeftistHeap::computeRank( LNode* h )
{
	if( !h )
	{
		return -1;
	}

	int heightl = 1 + computeRank( h->left );
	int heightr = 1 + computeRank( h->right );

	if( heightl < heightr )
	{
		return heightl + 1;
	}
	else
	{
		return heightr + 1;
	}
}

LNode* LeftistHeap::merge( LNode* h1, LNode* h2 )
{
	if( !h1 && !h2 )
	{
		cout << "Can't merge two empty heaps." << endl;
	}
	else if( !h2 )
	{
		return h1;
	}
	else if( !h1 )
	{
		return h2;
	}

	if( h1->value > h2->value )
	{
		LNode* temp = h1;
		h1 = h2;
		h2 = temp;
	}

	h1->right = merge( h1->right, h2 );
	h1->rank = computeRank( h1 );
	if( h1->left && h1->right )
	{
		if( h1->left->rank < h1->right->rank )
		{
			LNode* temp = h1->left;
			h1->left = h1->right;
			h1->right = temp; 
		}	
	}
	else if( !h1->left && h1->right )
	{
		h1->left = h1->right;
		h1->right = NULL;
	}		
	return h1;	
}

void LeftistHeap::makeEmpty( LNode* &h )
{
	if( !h )
	{
		return;
	}

	makeEmpty( h->left );
	makeEmpty( h->right );
	delete h;
}

void LeftistHeap::insert( int v )
{
	LNode* nNode = new LNode( v );
	root = merge( nNode, root );
}

int LeftistHeap::findMin()
{
	if( root )
	{
		return root->value;
	}
	else
	{
		return -1;
	}
}

int LeftistHeap::deleteMin()
{
	LNode* tempNode = root;
	int tempInt = root->value;
	root = merge( root->left, root->right );	
	delete tempNode;
	return tempInt;
}

bool LeftistHeap::isEmpty()
{
	return root == NULL;
}

void LeftistHeap::makeEmpty()
{
	makeEmpty( root );
}

LeftistHeap::~LeftistHeap()
{
	makeEmpty();
}






























