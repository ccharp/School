#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "TNode.h"

class BinarySearchTree {
	
	private:
		TNode *root;
		int count;
		void insert(int v, TNode* &t);
		
		void inOrderTraversal(TNode* &t);
		void preOrderTraversal(TNode* &t);
		void postOrderTraversal(TNode* &t);
		
		int leafCount(TNode* &t);
		int treeHeight(TNode* &t);
		
		void makeEmpty(TNode* &t);

        TNode*& find(int v, TNode* &t);
        TNode*& findMin(TNode* &t);
        TNode*& findMax(TNode* &t);

        void remove(TNode* &t);

        int deleteMin(TNode* &t);
        int deleteMax(TNode* &t);
		
	public:
		int getComparisons() {
			return count;
		}

		void resetComparisons() {
			count = 0;
		}

		BinarySearchTree(){
			root = NULL;
			count = 0;
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
    
        TNode*& findMin(){
            return findMin( root );
        }
    
        TNode*& findMax(){
            return findMax( root );
        }

        TNode*& find(int v){
            return find( v, root );
        }

        void remove( int v ){
            remove( find( v ) );
        }

        int deleteMin(){
            return deleteMin( findMin() );
        }

        int deleteMax(){
            return deleteMax( findMax() );
        }

		~BinarySearchTree();

};

#endif /* BINARYSEARCHTREE_H_ */
























