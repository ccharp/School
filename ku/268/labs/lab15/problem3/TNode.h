#ifndef TNODE_H //prevents recompilation
#define TNODE_H

#include <iostream>

using namespace std;

template <typename T> //so 'value' can be of any type
class TNode
{
	private:
		T value;
		TNode<T> *parent;						//points to parent node, Unique to doublylinked bsTree. 
		TNode<T> *left;
		TNode<T> *right;
	public:
		TNode(){ parent = NULL; left = NULL; right = NULL; }; //default constructor
		TNode(const T & v);									  //constructor for value, v. 

		bool hasOnlyLeft(); 					//returns true if node has only a left child
		bool hasOnlyRight();					//returns true if node has only right child
		void setValue(const T & v);				//sets value of node. 
		void setParent(TNode<T> *n); 			//Sets the node's parent. Unique to doubly linked binary tree. 
		void setLeft(TNode<T> *n);
		void setRight(TNode<T> *n);
		TNode<T>* getParent(){return parent;}; //returns parent. unique to Doubly Linked binary tree.
		TNode<T>* getLeft();
		TNode<T>* getRight();
		T getValue();
};

#include "TNode.cpp" //Because of template, must include .cpp file after class def. 
#endif
