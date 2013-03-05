#ifndef TNODE_H_
#define TNODE_H_

#include <iostream>
using namespace std;

class TNode
{
	public:
		int value;
		TNode* left;
		TNode* right;
	
		TNode(int v){
			value = v;
			left = NULL;
			right = NULL;
		}
		
		TNode(int v, TNode* lt, TNode* rt){
			value = v;
			left = lt;
			right = rt;
		}
		
		void print(){
			cout << value << " ";
		}
};

#endif /* TNODE_H_ */