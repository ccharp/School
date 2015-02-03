#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "TNode.h"

class BinarySearchTree {
	
	private:
		TNode *root;
		
		void insert(int v, TNode* &t);
		
		void inOrderTraversal(TNode* &t);
		void preOrderTraversal(TNode* &t);
		void postOrderTraversal(TNode* &t);
		
		int leafCount(TNode* &t);
		int treeHeight(TNode* &t);
		
		void makeEmpty(TNode* &t);
		
	public:
		void bst2ll(TNode *root, TNode *first, TNode *last );		
		
		BinarySearchTree(){
			root = NULL;
		}
		
		void insert(int v){
			insert(v, root);
		}
		
		void inOrderTraversal(){
			inOrderTraversal(root);
			cout << endl;
		}

		void preOrderTraversal(){
			preOrderTraversal(root);
			cout << endl;
		}

		void postOrderTraversal(){
			postOrderTraversal(root);
			cout << endl;
		}
		
		int leafCount(){
			return leafCount(root);
		}
		
		int treeHeight(){
			return treeHeight(root);
		}
		
		void makeEmpty(){
			makeEmpty(root);
		}

		~BinarySearchTree(){
			makeEmpty();
		}

};

#endif /* BINARYSEARCHTREE_H_ */
