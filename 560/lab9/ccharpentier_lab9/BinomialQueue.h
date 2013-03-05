#ifndef BINOMIALQUEUE_H_
#define BINOMIALQUEUE_H_

#include <algorithm>
#include <vector>
#include "BNode.h"

class BinomialQueue {
	
	private:
		int currentSize;
		int minIndex;
		vector<BNode*> theTrees;
		
		void combine( int currIndex );
		void findNewMin();
		void makeEmptyTree( BNode *node );
		BNode *getFarRightSib( BNode *start );	
		BNode *mergeTrees( BNode *currRoot, BNode *nextRoot );
		
	public:
		
		BinomialQueue();
		BinomialQueue(int v);
		void insert(int v);
		int findMin();
		int deleteMin();
		bool isEmpty();
		void makeEmpty();
		void print();
		void printTree( BNode *node );
		~BinomialQueue();

};

#endif /* BINOMIALQUEUE_H_ */
