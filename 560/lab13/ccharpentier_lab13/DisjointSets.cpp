#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "DisjointSets.h"

using namespace std;

DisjointSets::DisjointSets( int n )
{
	parent = new int[n];
	size = n;
	count = 0;
	for( int i = 0; i < size; i++ )
	{
		count++;
		parent[i] = -1;
	}
}

DisjointSets::~DisjointSets()
{
	delete parent; 
}

bool DisjointSets::isRoot( int x )
{
	return parent[x] < 0;
}

void DisjointSets::print()
{
	for( int i = 0; i < size; i++ )
	{
		count++;
		printf( "%4d", parent[i] );
	}
	std::cout << endl;
	for( int i = 0; i < size; i++ )
	{
		count++;
		printf("%4d", i);
	}
	std::cout << "\n\n";
}

// Returns root of tree containing x (first negative index).
int DisjointSets::find( int x ) 
{
	vector<int> vec;
	while( parent[x] >= 0 )
	{
		count++;
		vec.push_back( x );
		x = parent[x];
	}
	for( int i = 0; i < vec.size(); i++ )
	{
		count++;
		parent[vec[i]] = x;
	}
	return x;
}

void DisjointSets::merge( int x, int y )
{
	int xRoot = find( x );
	int yRoot = find( y );

	// Already merged.
	if( xRoot == yRoot )
	{
		count++;
		return;
	}
	// Same rank	
	if( parent[xRoot] == parent[yRoot] )
	{
		count++;
		//always make y child of x
		parent[yRoot] = xRoot;
		parent[xRoot] -= 1;
	}
	else //ranks are not equal
	{
		if( parent[xRoot] > parent[yRoot] )
		{
			count++;
			int tmp;
			tmp = xRoot;
			xRoot = yRoot;
			yRoot = tmp;
		}
		parent[yRoot] = xRoot;
	}
}








































