#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std; 

Matrix::Matrix( int n_val )
{
	n = n_val;
	array_size = n * n;
	array = new int[array_size];

	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			if( i == j )
			{
				array[index(i,j)] = 0;
			}
			else 
			{
				array[index(i,j)] = INF;
			}
		}
	}
}

Matrix::~Matrix()
{
	delete array;
}

int Matrix::index( int i, int j )
{
	return i * n + j;
}

int Matrix::get( int i, int j )
{
	return array[index(i, j)];
}

void Matrix::set( int i, int j, int value )
{
	array[index(i,j)] = value;
}

void Matrix::print()
{
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			int x = array[index(i,j)];
			if( x == INF )
			{
				printf( "%-9c", '-' );
			}
			else 
			{
#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std; 

Matrix::Matrix( int n_val )
{
	n = n_val;
	array_size = n * n;
	array = new int[array_size];

	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			if( i == j )
			{
				array[index(i,j)] = 0;
			}
			else 
			{
				array[index(i,j)] = INF;
			}
		}
	}
}

Matrix::~Matrix()
{
	delete array;
}

int Matrix::index( int i, int j )
{
	return i * n + j;
}

int Matrix::get( int i, int j )
{
	return array[index(i, j)];
}

void Matrix::set( int i, int j, int value )
{
	array[index(i,j)] = value;
}

void Matrix::print()
{
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			int x = array[index(i,j)];
			if( x == INF )
			{
				printf( "%-9c", '-' );
			}
			else 
			{
				printf("%-9d", x);
			}
		}
		cout << endl;
	}
}



				printf("%-9d", x);
			}
		}
		cout << endl;
	}
}



