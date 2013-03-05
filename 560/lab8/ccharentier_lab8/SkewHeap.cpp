#include <iostream>
#include "SkewHeap.h"

using namespace std;

SkewHeap::SkewHeap()
{
	root = NULL;
}

SkewHeap::~SkewHeap()
{
	makeEmpty();
}

void SkewHeap::print( LNode* h, int level )
{
	if( !h )
	{
		return;
	}

	print( h->right, level + 1);

	for( int i = 0; i < level; i++ )
	{
		cout << "	";
	}

	cout << h->value;

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

	print( h->left, level + 1 );
}

void SkewHeap::makeEmpty( LNode* &h )
{
	while( root )
	{
		deleteMin();
	}
}

LNode* SkewHeap::merge( LNode* h1, LNode* h2 )
{
	if( !h1 && !h2 )
	{
		return NULL;
	}
	else if( !h2 )
	{
		return h1;
	}
	else if( !h1 )
	{
		return h2;
	}

	if( h1->value < h2->value )
	{
		LNode* temp = h1;
		h1 = h2;
		h2 = temp;
	}
	
	LNode* temp = h1->right;
	h1->right = h1->left;
	h1->left = merge( temp, h2 );

	return h1;
}













































