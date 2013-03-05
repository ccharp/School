#ifndef BNODE_H_
#define BNODE_H_

#include <iostream>
using namespace std;

class BNode
{	
	public:
		int key;
		BNode* leftChild;
		BNode* nextSibling;
	
		BNode(int k){
			key = k;
			leftChild = NULL;
			nextSibling = NULL;
		}
		
};

#endif /* BNODE_H_ */
