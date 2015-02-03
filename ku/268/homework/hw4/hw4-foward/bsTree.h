#ifndef BSTREE_H //prevents recompilation error
#define BSTREE_H

#include "TNode.h"
#include <iostream>

using namespace std;

template <typename T> 
class bsTree
{
	private:
		int size;
		TNode<T> * root;

		void insert(TNode<T> *node, T value);							//cleates and places new node
		void inOrderTraversal(TNode<T> *t, ofstream &fout);				//outputs tree's values in order
		void removeLink(TNode<T> *p1, TNode<T> *p2, TNode<T> *p3);		//swaps values and deletes node
		void getSmallest(TNode<T> *cN, TNode<T> *sN, TNode<T> *realcN); //finds smallest node
		void getBiggest(TNode<T> *cN, TNode<T> *bN, TNode<T> *realcN);  //finds largest node
		TNode<T>* search(TNode<T> *node, const T &value);						//finds pointer to node containing 'value'
		
	public:
		bsTree(); 							 //constructor
				void remove(const T & item); //calls remove function.

		//All of the following functions correspond to an overloaded private function of the same name.
		//	Necessary because private variable, root, cannot be accessed from the client. 
		void insert(T value){insert(root, value);};
		void inOrderTraversal(ofstream &fout){
			inOrderTraversal(root, fout); fout << endl;
		};
		void search(T value, ofstream &fout){
			fout << search(root, value) << endl;
		};
		
};

#include "bsTree.cpp" //must include for template
#endif
