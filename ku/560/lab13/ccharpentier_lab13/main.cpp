#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "EdgeArray.h"
#include "DisjointSets.h"
#include "Matrix.h"
#include "Timer.h"
using namespace std;

int _count = 0;

void generateRandomEdges( int n, Matrix &m, bool prob ) 
{
	int right_m_bound = 0;
	for(int i = 0; i < n; i++ )
	{
		for( int j = 0; j < right_m_bound; j++ )
		{
			if( i != j )
			{
				int value = (rand() % 1001) + 1;
				if( prob && rand() % 2 )
				{
					m.set( i, j, value );
					m.set( j, i, value );	
				}
				else if( !prob )
				{
					m.set( i, j, value );
					m.set( j, i, value );	
				}
			}
		}
		++right_m_bound;
	}
}

void buildEdgeArray( int n, EdgeArray &e, Matrix &m )
{
	int right_m_bound = 1;
	for( int i = 1; i < n; i++ )
	{
		for( int j = 0; j < right_m_bound; j++ )
		{
			if( i != j && m.get( i, j ) != INF )
				e.append( i, j, m.get( i, j ) );
		}
		++right_m_bound;
	}
}



void Kruskal(EdgeArray& Q, int n){
	_count = 0;
	DisjointSets D(n);
	EdgeArray E_T;
	int size = Q.getSize();	
	int i = 0;
	//Q.sort();
	while( size != 0 && E_T.getSize() != n - 1 )
	{
		_count++;
		Edge edge = Q[i];
		if(edge.cost == INF)
			break;
		size--;
		if( D.find( edge.v ) != D.find( edge.w ) )
		{
			_count++;
			D.merge( edge.v, edge.w );
			E_T.append( edge.v, edge.w, edge.cost );
		}
		i++;
	}
	_count += D.count;
	/*if( E_T.getSize() == n - 1 )
	{
		_count++;
		E_T.printSimple();
	}
	else 
	{
		cout << "Failure!\n";
	}*/
}

void Prim(Matrix& c, int n){
	_count = 0;
	EdgeArray E_T;
	bool* V_T = new bool[n];
	int* mins = new int[n];
	int* other = new int[n];
	
	V_T[0] = true; 
	mins[0] = INF;
	for( int i = 1; i < n; i++ )
	{
		_count++;
		V_T[i] = false; 
		mins[i] = c.get(0, i);
		other[i] = 0; 
	}
	int w = INF;
	while( E_T.getSize() < n-1 )
	{
		_count++;
		int min = INF;
		for( int v = 1; v < n; v++ )
		{
			_count++;
			if( mins[v] < min && !V_T[v] )
			{
				_count++;
				min = mins[v];
				w = v;
			}
		}

		if(w == INF)
		{
			_count++;
			break;
		}
		V_T[w] = true;
		E_T.append(w, other[w], c.get(w, other[w]) );
		
		for( int v = 1; v < n; v++ )
		{
			_count++;
			if( mins[v] > c.get(w, v) && !V_T[v])
			{
				_count++;
				mins[v] = c.get(w,v);
				other[v] = w;
			}
		}
	}
	//E_T.printSimple();
}

void test( int n )
{
	cout << "Size: " << n << endl;
	Timer timer;
	EdgeArray empty_e;
	EdgeArray half_e;
	EdgeArray full_e;
	Matrix empty_m(n);
	Matrix half_m(n);
	Matrix full_m(n);

	cout << "Generating random Edges...\n";
	generateRandomEdges( n, half_m, true );	
	generateRandomEdges( n, full_m, false );	

	cout << "Building edge array...\n";
	buildEdgeArray( n, half_e, half_m );
	buildEdgeArray( n, full_e, full_m );

	/*half_m.print();
	half_e.print();
	full_m.print();
	full_e.print();*/

	cout << "Timing Experiment... \n";

	double time; 
	timer.start();
	Kruskal( empty_e, n );
	time = timer.stop();
	cout << "Kruskal empty time: " << time << endl;
	cout << "Comparisons: " << _count << "\n\n";
	
	timer.start();
	Prim( empty_m, n );
	time = timer.stop();
	cout << "Prim empty time: " << time << endl;
	cout << "Comparisons: " << _count << "\n\n";	

	timer.start();
	Kruskal( half_e, n );
	time = timer.stop();
	cout << "Kruskal half time: " << time << endl;
	cout << "Comparisons: " << _count << "\n\n";

	timer.start();
	Prim( half_m, n );
	time = timer.stop();
	cout << "Prim half time: " << time << endl;
	cout << "Comparisons: " << _count << "\n\n";	

	timer.start();
	Kruskal( full_e, n );
	time = timer.stop();
	cout << "Kruskal full time: " << time << endl;
	cout << "Comparisons: " << _count << "\n\n";

	timer.start();
	Prim( full_m, n );
	time = timer.stop();
	cout << "Prim full time: " << time << endl;
	cout << "Comparisons: " << _count << "\n\n";	
}

int main() {
	srand((unsigned)time(0));
	test(1000);
	test(2000);
	test(3000);
	test(4000);
	return 0;
}

