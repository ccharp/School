#include "BinarySearchTree.h"


BinarySearchTree::~BinarySearchTree()
{
	while( root )
	{
		remove( root );
	}
}
// this should be called with root initally 
void BinarySearchTree::insert(int v, TNode* &t)
{
	if( t )
	{	
		count++;
		if( v < t->value )
		{	
			count++;	
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
		count++;
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
		count++;
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
		count++;
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
		count++;
		return 0;
	}
	else 
	{
		if( !t->left && !t->right )
		{	
			count++;
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
		count++;
		return -1;
	}
	
	int heightl = 1 + treeHeight( t->left );
	int heightr = 1 + treeHeight( t->right );
	
	//int height = 1 + maximum( heightl, heightr );	
	if( heightl > heightr )
	{
		count++;
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
		count++;
		return;
	}
	else
	{
		makeEmpty( t->left );
		makeEmpty( t->right );
		delete t;
	}
}

TNode*& BinarySearchTree::find(int v, TNode* &t)
{
    if( !t || t->value == v )
    {
		count++;
        return t;
    }

    find( v, t->left );
    find( v, t->right );
}

TNode*& BinarySearchTree::findMin(TNode* &t)
{
    if( t->left == NULL )
    {	
		count++;
        return t;
    }

    findMin( t->left );
}

TNode*& BinarySearchTree::findMax(TNode* &t)
{
    if( t->right == NULL )
    {
		count++;
        return t;
    }

    findMax( t->right );
}

void BinarySearchTree::remove(TNode* &t)
{
    TNode *oldPointer = t;
    
    if( !t )
    {
		count++;
        return;
    }
    else if( !t->left && !t->right )
    {
		count++;
        t = NULL;
        delete oldPointer;
    } 
    else if( !t->left )
    {
		count++;
        t = t->right;
        delete oldPointer;
    }
    else if( !t->right )
    {
		count++;
        t = t->left;
        delete oldPointer;
    }
    else // Has left and right child
    {   
        TNode*& delNode = findMin( t->right );
        t->value = delNode->value;
        remove( delNode );
    }
}

int BinarySearchTree::deleteMin(TNode* &t)
{
    int retVal = t->value;
    remove( t );
    return retVal;    
}

int BinarySearchTree::delete
