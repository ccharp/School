#ifndef NODE_H_
#define NODE_H_

class Node {
	
	public:
		int value;
		Node* next;
		
		Node();
		Node( int v /*= 0*/, Node * n/* = NULL*/): value( v ), next( n )
		{}
};

#endif /* NODE_H_ */
