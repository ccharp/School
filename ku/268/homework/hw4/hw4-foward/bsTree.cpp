#ifndef BSTREE_CPP 
#define BSTREE_CPP

#include "bsTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
bsTree<T>::bsTree() //constructor: sets root to NULL and size to 0. 
{
	root = NULL;
	size = 0;
} 
/* REMOVE FUNCTION:
 *	Remove first finds the node containing value, 'item'. If it exists, Remove considers the Following
 *  cases: node is a leaf, node has only right child, node has only left child, or node has two children.
 *	All cases excpet for the two children case call function removeLink to perform the actually value swap 
 *  and node deletion. The two child case calls either getSmallest or getLargest, depending if item is
 *	greater or less than root. getSmallest() and getBiggest() call removeLink to delete the node. 
 */
template <typename T>
void bsTree<T>::remove(const T & item)
{		//cout << "Removing: " << item << endl;

		//cout << "Returned search: " << search(root, item) << endl;
		TNode<T> *tN = search(root, item);					//Returns node of value, item.
		if(!tN) 											//if node is not found, remove nothing.
			return;	
		//cout << "tN " << tN << endl;
		//cout << "tN: " << tN->getValue() << endl;

		//cout << "Removing1: " << item << endl;
		TNode<T> *pN= tN->getParent();						//Points to tN's parent.
		
		if(tN->getLeft() == NULL && tN->getRight() == NULL) //node is leaf
		{
			removeLink(tN, pN, NULL);
		}
		else if(tN->hasOnlyLeft())						    //Node has only left child
		{
			removeLink(tN, pN, tN->getLeft());
		}
		else if(tN->hasOnlyRight())						    //Node has only right child
		{
			removeLink(tN, pN, tN->getRight());
		}
		else 											    // has two children
		{
			if(tN->getValue() > root->getValue())
			{
				getSmallest(tN->getRight(), tN, tN);
			}
			else
			{
				getBiggest(tN->getLeft(), tN, tN);
			}
		}
}
/* GETBIGGEST:
 * 	getBiggest is called only if the node to be removed has two children and is less than root's value. 
 *  getBiggest recursively finds the largest value on the left side of the tree and it's parent. That value is them 
 * 	swapped with the current node's and is then deleted by removeLink(). Functions in same way as 
 *  getSmallest() except finds largest.
 */
template <typename T>
void bsTree<T>::getBiggest(TNode<T> *cN, TNode<T> *bN, TNode<T> *realcN)
{
	if(cN->getRight() != NULL)								//Recursively searches for largest until hits NULL
	{
		getBiggest(cN->getLeft(), cN, realcN);
	}
	else if(cN->getRight() == NULL)							//Found smallest, calls removeLink()
	{	
		realcN->setValue(cN->getValue());
		if(cN->getLeft() == NULL)								//if cN has no parent
			removeLink(cN, cN->getParent(), NULL);
		else
			removeLink(cN, cN->getParent(), cN->getLeft());
	}
}

template <typename T>
void bsTree<T>::getSmallest(TNode<T> *cN, TNode<T> *sN, TNode<T> *realcN)
{
	if(cN->getLeft() != NULL)
	{
		getSmallest(cN->getLeft(), cN, realcN);
	}
	else
	{
		realcN->setValue(cN->getValue());
		if(cN->getRight() == NULL)	
			removeLink(cN, cN->getParent(), NULL);
		else
			removeLink(cN, cN->getParent(), cN->getRight());
	}
}
/* REMOVELINK:
 *	RemoveLink() is called by every case of removal. It takes three parameters as inputs: the current
 *  node and its child and parent. RemoveLink() swaps the value of parent and child, then deleting child. 
 *  In the case Current node is root, cN is swapped with child instead of its parent, which would be NULL.
 */
template <typename T>
void bsTree<T>::removeLink(TNode<T> *cN, TNode<T> *pN, TNode<T> *child)
{
	if(cN == root)					//if cN is root
	{
		root = child;
	}
	else if(cN == pN->getLeft())    //if cN is a left child of its parent
	{
		pN->setLeft(child);
		if(child)
			child->setParent(pN);
	}
	else							//if cN is a right child of its parent
	{
		pN->setRight(child);
		if(child)
			child->setParent(pN);
	}

	delete cN;
	size--;
}
/* SEARCH:
 *	Recursively finds node containig value, value. If node is not found, outputs error. 
 */
template <typename T>
TNode<T>* bsTree<T>::search(TNode<T> *node, const T &value)
{
	if(node == NULL)
	{
		cout << "Node containing item " << value << " was not found." << endl;
		return NULL;
	}
	if(value == node->getValue())
	{
		cout << "Search: " << endl;
		cout << "Node in search Value: " << node->getValue() << " at " << node <<endl;
		return node;
	}
	else if(value < node->getValue())
		search(node->getLeft(), value);
	else if(value > node->getValue())
		search(node->getRight(), value);
}

/* INSERT:
 *	Recursively populates binary search tree. If value is less than current node, insert() calls itself
 *	with node->getRight() as node parameter. Cycles through tree until it finds a nodes left or right
 * 	depending on value, that equals NULL. 
 */
template <typename T>
void bsTree<T>::insert(TNode<T> *node, T value)//must be passed root
{	
	if(size==0)									 	//If tree is empty
	{
		TNode<T> *t = new TNode<T>(value);
		root = t;
		size++;
	}
	else if(value < node->getValue())				//if value is less than node's value
	{
		if(node->getLeft() == NULL)					//if node's left is NULL, places new node there
		{
			TNode<T> *t = new TNode<T>(value);
			node->setLeft(t);
			t->setParent(node);
			size++;
		}
		else										//else recursively searches left side
			insert(node->getLeft(), value);
	}
	else if(value > node->getValue())				//if value is greater than node's value
	{
		if(node->getRight() == NULL)				//if node's right is NULL, places new node there
		{
			TNode<T> *t = new TNode<T>(value);
			node->setRight(t);
			t->setParent(node);
			size++;
		}
		else										//else recursively searches to the right
			insert(node->getRight(), value);	
	}
}

//InOrderTraversal: recursively outputs tree's node's values in ascending order.
template <typename T>
void bsTree<T>::inOrderTraversal(TNode<T> *t, ofstream &fout)//must be passed root
{	
	if(!t) return;  			  //stops when NULL is found. 
	inOrderTraversal(t->getLeft(), fout);
	fout << t->getValue() << " "; //to output file.
	inOrderTraversal(t->getRight(), fout);
} 

#endif




