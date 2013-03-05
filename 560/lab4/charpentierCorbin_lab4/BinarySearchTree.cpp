#include "BinarySearchTree.h"

// this should be called with root initally 
void BinarySearchTree::insert(int v, TNode* &t)
{
	if( t )
	{	
		if( v < t->value )
		{		
			insert( v, t->left );
		}
		else
		{	
			insert( v, t->right );
		}
	}
	else
	{
		t = new TNode( v );
	}
}

void BinarySearchTree::inOrderTraversal( TNode* &t )
{
	if( !t )
	{
		return;
	}
	else
	{
		inOrderTraversal( t->left );
		cout << t->value << " ";
		inOrderTraversal( t->right );
		//cout << t->value << " ";
	}
}

void BinarySearchTree::preOrderTraversal( TNode* &t )
{
	if( !t )
	{
		return;
	}		

	cout << t->value << " ";
	preOrderTraversal( t->left );
	preOrderTraversal( t->right );

}

void BinarySearchTree::postOrderTraversal( TNode* &t )
{
	if( !t )
	{
		return;
	}	
	
	postOrderTraversal( t->left );
	postOrderTraversal( t->right );
	cout << t->value << " ";
	
}

int BinarySearchTree::leafCount( TNode* &t )
{
	if( !t )
	{
		return 0;
	}
	else 
	{
		if( !t->left && !t->right )
		{	
			return 1;
		} 
		else
		{
			return leafCount( t->left ) + leafCount( t->right );
		}
		//return leafCount( t->right );
	}
}

int BinarySearchTree::treeHeight( TNode* &t )
{
	if( !t )
	{
		return -1;
	}
	
	int heightl = 1 + treeHeight( t->left );
	int heightr = 1 + treeHeight( t->right );
	
	//int height = 1 + maximum( heightl, heightr );	
	if( heightl > heightr )
	{
		return heightl;
	}
	else
	{
		return heightr;
	}
	
	//return height;
}

void BinarySearchTree::makeEmpty(TNode* & t)
{
	if( !t )
	{
		return;
	}
	else
	{
		makeEmpty( t->left );
		makeEmpty( t->right );
		delete t;
	}
}



























