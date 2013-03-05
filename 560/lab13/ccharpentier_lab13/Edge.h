#ifndef EDGE_H_
#define EDGE_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

class Edge {
public:
	
	int v, w;
	int cost;

	Edge(){
		v = 0;
		w = 0;
		cost = 0;
	}
	
	Edge(int v_val, int w_val, int cost_val){
		v = v_val;
		w = w_val;
		cost = cost_val;
	}
	
	void printSimple(){
		printf("(%d,%d)", v, w);
	}
	
	void print(){
		printf("(%d,%d):%d", v, w, cost);
	}
};

#endif /* EDGE_H_ */
