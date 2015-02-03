#ifndef SKEWHEAP_H
#define SKEWHEAP_H 

#include "LeftistHeap.h"
#include <algorithm>


class SkewHeap : public LeftistHeap
{
	private:
		void print( LNode* h, int level );
		LNode* merge( LNode* h1, LNode* h2 );
		void makeEmpty( LNode * &h );
	public: 
		SkewHeap();
		~SkewHeap();
};

#endif	
