#ifndef DISJOINTSETS_H_
#define DISJOINTSETS_H_

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class DisjointSets {

private:
	
	int* parent;
	int size;
	
	bool isRoot(int x);
	//void pathCompress( int xRoot, int yRoot, int y );
	
public:
	
	DisjointSets(int n);
	void print();
	void merge(int x, int y);
	int find(int x);
	~DisjointSets();
	
};

#endif /* DISJOINTSETS_H_ */
