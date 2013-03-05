#ifndef LEFTISTHEAP_H_
#define LEFTISTHEAP_H_

#include <algorithm>
#include "LNode.h"

class LeftistHeap {

	private: 
		int computeRank(LNode* h);
	
	protected:
		LNode *root;
		
		virtual void print(LNode* h, int level);
		virtual LNode* merge(LNode* h1, LNode* h2);
		virtual void makeEmpty(LNode* &h);
		
	public:
		
		LeftistHeap();
		void print();
		void insert(int v);
		int findMin();
		int deleteMin();
		bool isEmpty();
		void makeEmpty();
		~LeftistHeap();

};

#endif /* LEFTISTHEAP_H_ */
