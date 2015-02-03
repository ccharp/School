#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <sstream>
#include <vector> //used to store neighboring nodes 

#include "MyDlist.h" //doubly linked list to store nodes
#include "Edges.cpp" // 

using namespace std;

//GRAPH CLASS. Uses doubly linked list to store nodes.
class Graph
{
	private:
		int gSize; 
		MyDlist<Edges*> listE; 
		
		bool contains(int x, vector<int> v);
		int getEdgeIndex(int i, int j);
	public:
		Graph(){gSize = 0;}; //constructor
		bool isConnected(vector<int> &u, int i, int j);
		Graph *getMST();
		vector<int> getNeighbors(int key);
		int getSize(){return gSize;};
		void insertEdge(int i, int j, int w); //i and j are indexes of the vector
		void removeEdge(int i, int j); 
		Edges * findMinWeight();
		string toString();		
};

//determins whether an edge node has already been searched
bool Graph::contains(int x, vector<int> v)
{
	bool dec = false;

	for(int i=0; i < v.size(); i++)
	{	
		if(v[i] == x)
			dec = true;
	}	
	return dec;
}

//removes an edge from the list
void Graph::removeEdge(int i, int j)
{
	listE.remove(getEdgeIndex(i, j));
	gSize--;
}

//returns the neighbors of a given node by finding all edges that contain that node. 
//		populates neighboring nodes into a vector returned to isConnected().
vector<int> Graph::getNeighbors(int key)
{	
	vector<int> v;

	for(int i=0; i < listE.getSize(); i++)
	{	
		int x = listE.getNode(i)->getValue()->getNode1();
		int y = listE.getNode(i)->getValue()->getNode2();
		if(x == key)
			v.push_back(y);
		else if(y == key)
			v.push_back(x);
	}

	return v;
}

//recursively determins whether a path exists which connects two nodes on the graph.
//		vector r contrains nodes that have already been checked
bool Graph::isConnected(vector<int> &r, int i, int j)
{ 	
	if(!contains(i, r)) //if the vector does not contain i, it's pushed back
		r.push_back(i);
	else
		return false; //if has be checked, kill this recursion. 

	vector<int> u = getNeighbors(i); //vector to hold neighbors

	if(contains(j, u)) //checks if one of the neibhros is key
		return true;
	else //if not, iterate through u, calling isConnected() for each neighbor
	{	
		for(int a=0; a<u.size(); a++)	
		{	bool x = false;
			if(!contains(u[a], r))
			{
				x = isConnected(r, u[a], j);
			}
			if(x == true)
				return true;
		}
		return false; 
	}
}

//Returns the minimal spanning tree of a graph. Accomplishes this by finding the smallest edge, removing it, and 
//		adding it to another graph. 
Graph* Graph::getMST()
{
	Graph * mst = new Graph;
	vector<int> u;
	while(listE.getSize() != 0)
	{
		u.clear();
		Edges *p = findMinWeight();

		if(!mst->isConnected(u, p->getNode1(), p->getNode2()))
		{
			mst->insertEdge(p->getNode1(), p->getNode2(), p->getWeight());
		}

		this->removeEdge(p->getNode1(), p->getNode2());

	}
	return mst;
}

//finds edge with smallesetweight
Edges * Graph::findMinWeight()
{
	Edges* minEdge = listE.getNode(0)->getValue();
	int minWeight = minEdge->getWeight();

	for(int i=1; i< listE.getSize(); i++)
	{
		if(listE.getNode(i)->getValue()->getWeight() < minWeight)
			minEdge = listE.getNode(i)->getValue();
	}
	return minEdge;
}
	
//interts a new egdge into the graph
void Graph::insertEdge(int i, int j, int w)
{
	Edges * e = new Edges(i, j, w);

	listE.push_back(e);
	gSize++;
	
}

//returns the index of an of the node containing the two edges nodes. 
int Graph::getEdgeIndex(int i, int j)
{
	int index = -1;
	int x, y;
	for(int a=0; a< listE.getSize(); a++)
	{
		x = listE.getNode(a)->getValue()->getNode1();
		y = listE.getNode(a)->getValue()->getNode2();
		if((x == i && y == j) || (y==i && x==j))
		{
			index = a;
		}
	}
	return index;
}

//fills a string with all nodes and edges in the graph. returns them as a string. 
string Graph::toString()
{
	stringstream oss; //uses string stream library
   
	for(int i=0; i<listE.getSize(); i++)
	{
		oss << listE.getNode(i)->getValue()->getNode1() << " "
			<< listE.getNode(i)->getValue()->getNode2() << " "
			<< listE.getNode(i)->getValue()->getWeight() << endl;
	}
	
	return oss.str();
}

#endif




















