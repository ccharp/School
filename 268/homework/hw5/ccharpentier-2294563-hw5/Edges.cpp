#ifndef EDGES_CPP
#define EDGES_CPP

#include <iostream>

using namespace std;
//EDGE CLASS
class Edges
{
	private:
		int nIndex1, nIndex2; //indexes (locations) of the nodes within the vector
		int weight; //weight of the edge
	public:
		Edges(int i, int j, int w)//constructor
		{
			weight = w;
			nIndex1 = i;
			nIndex2 = j;
		}	
		int getWeight(){return weight;};//returns weight
		int getNode1(){return nIndex1;};//returns index 1
		int getNode2(){return nIndex2;};//returns index 2
};

#endif
