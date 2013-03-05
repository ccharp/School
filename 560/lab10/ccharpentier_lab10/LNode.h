#ifndef LNODE_H_
#define LNODE_H_

#include <iostream>
using namespace std;

class LNode
{	
	public:
		int value;
		int rank;
		LNode* left;
		LNode* right;
	
		LNode(int v){
			rank = 1;
			value = v;
			left = NULL;
			right = NULL;
		}
};

#endif /* LNODE_H_ */
