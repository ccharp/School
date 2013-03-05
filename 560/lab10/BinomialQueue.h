#ifndef BINOMIALQUEUE_H
#define BINOMIALQUEUE_H

#include <algorithm>
#include <vector>
#include "BNode.h"

class BinomialQueue {
	
	private:
		int currentSize;
		int minIndex;

		int count;
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

		int getComparisons(){return count;};
		int resetComparisons(){count = 0;};
		~BinomialQueue();

};

#endif /* BINOMIALQUEUE_H_ */
