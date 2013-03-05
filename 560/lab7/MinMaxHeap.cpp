#include <cmath> 

#include "MinMaxHeap.h"

void MinMaxHeap::swapArrayIndex( int i, int j )
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

bool MinMaxHeap::atMinLevel( int i )
{
	return( (int)floor( log2( i ) ) % 2 == 0 );
}

int MinMaxHeap::getMinIndex()
{
	return array[1];
}

int MinMaxHeap::getMaxIndex()
{
	int i = 1;
	int largesti = 1;
	while( i <= size && i <= 3 )
	{
		if( array[i] > array[largesti] )
		{
			largesti = i;	
		}	
		i++;
	}
	return largesti;
}

int MinMaxHeap::findMinChild( int parent )
{
	// Function assumes parent HAS childern 
	int firstChild = parent * 2;
	
	int smallesti = firstChild;
	while( firstChild <= parent*2 + 1 && firstChild <= size )
	{
		if( array[firstChild] < array[smallesti] )
		{
			smallesti = parent;
		}
		firstChild++;
	}
	if( parent*4 <= size ) // has parent has grandChildren
	{
		int firstGrandChild = parent * 4;
		while( firstGrandChild <= parent*4 + 3 && firstGrandChild <= size)
		{
			if( array[firstGrandChild] < array[smallesti] )
			{
				smallesti = firstGrandChild;
			}
			firstGrandChild++;
		}
	}
	return smallesti;
}


int MinMaxHeap::findMaxChild( int parent )
{
	int firstChild = parent * 2;
	
	int largesti = firstChild;
	while( firstChild <= parent * 2 + 1 && firstChild <= size )
	{
		if( array[firstChild] > array[largesti] )
		{
			largesti = parent;
		}
		firstChild++;
	}
	
	if( parent*4 <= size ) // has parent has grandChildren
	{
		int firstGrandChild = parent * 4;
		while( firstGrandChild <= parent*4 + 3 && firstGrandChild <= size)
		{
			if( array[firstGrandChild] > array[largesti] )
			{
				largesti= firstGrandChild;
			}
			firstGrandChild++;
		}
	}
	return largesti;
}

int MinMaxHeap::getParent( int child )
{
	if( hasParent( child ) )
	{
		return (int)floor( child / 2);	
	}
	return -1;
}

int MinMaxHeap::getGrandParent( int child )
{
	if( hasParent( child ) )
	{
		return (int)floor( child / 4);
	}
}

bool MinMaxHeap::hasParent( int child )
{
	return child > 1;
}

bool MinMaxHeap::hasGrandParent( int child )
{
	return child > 3;
}

int MinMaxHeap::getFirstChild( int child )
{
	return child * 2;
}

int MinMaxHeap::getFirstGrandChild( int parent )
{
	return parent* 4;
}

bool MinMaxHeap::hasChildren( int parent)
{
	return parent * 2 <= size;	
}

bool MinMaxHeap::isGrandChild( int child, int parent )
{
	return child >= parent * 4 && child <= parent * 4 + 3;
}


void MinMaxHeap::buildHeap()
{
	for( int i = size/2; i >= 1 ; i-- )
	{
		trickleDown( i );	
	}
}

void MinMaxHeap::trickleDown( int i )
{
	if( atMinLevel( i ) )
	{
		trickleDownMin( i );
	}
	else
	{
		trickleDownMax( i );
	}
}

void MinMaxHeap::trickleDownMin( int i )
{
	if( hasChildren( i ) )
	{
		int m = findMinChild( i );

		if( isGrandChild( m, i ) )
		{
			if( array[m] < array[i] )
			{
				swapArrayIndex( m, i );
				if( array[m] > array[getParent( m )] )
				{
					swapArrayIndex( m, getParent( m ) );
				}
				trickleDownMin( m );
			}
		}
		else
		{
			if( array[m] < array[i] )
			{
				swapArrayIndex( i, m );
			}
		}
	}
}

void MinMaxHeap::trickleDownMax( int i )
{
	if( hasChildren( i ) )
	{
		int m = findMaxChild( i );

		if( isGrandChild( array[m], i ) )
		{
			if( array[m] > array[i] )
			{
				swapArrayIndex( m, i );
				if( array[m] < array[getParent( m )] )
				{
					swapArrayIndex( m, getParent( m ) );
				}
				trickleDownMin( m );
			}
		}
		else
		{
			if( array[m] > array[i] )
			{
				swapArrayIndex( i, m );
			}
		}
	}
}

void MinMaxHeap::bubbleUp( int i )
{
	if( atMinLevel( i ) )
	{
		if( hasParent( i ) && array[i] > array[getParent( i )] )
		{
			swapArrayIndex( i, getParent( i ) );
			bubbleUpMax( getParent( i ) );
		}
		else 
		{
			bubbleUpMin( i );	
		}	
	}
	else
	{
		if( hasParent( i ) && array[i] < array[getParent( i )] )
		{
			swapArrayIndex( i, getParent( i ) );
			bubbleUpMin( getParent( i ) );
		}
		else
		{
			bubbleUpMax( i ); 
		}
	}
}

void MinMaxHeap::bubbleUpMin( int i )
{
	if( hasGrandParent( i ) )
	{
		if( array[i] < array[getGrandParent( i )] )
		{
			swapArrayIndex( i, getGrandParent( i ) );
			bubbleUpMin( getGrandParent( i ) );
		}
	}
}

void MinMaxHeap::bubbleUpMax( int i )
{
	
	if( hasGrandParent( i ) )
	{
		if( array[i] > array[getGrandParent( i )] )
		{
			swapArrayIndex( i, getGrandParent( i ) );
			bubbleUpMin( getGrandParent( i ) );
		}
	}
}

// public methods 

bool MinMaxHeap::isEmpty()
{
	return size == 0;
}

MinMaxHeap::MinMaxHeap( int* data, int n )
{
	size = n;
	array = new int[DEFAULT_CAPACITY];

	for( int i = 0; i < n; i++ )
	{
		array[i+1] = data[i];
	}

	buildHeap();
}

void MinMaxHeap::print()
{
	for( int i = 1; i <= size; i++ )
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void MinMaxHeap::insert( int item )
{
	size++;
	array[size] = item;
	bubbleUp( size );
}

int MinMaxHeap::findMin()
{
	return getMinIndex();
}

int MinMaxHeap::findMax()
{
	return array[getMaxIndex()];
}

int MinMaxHeap::deleteMin()
{
	if( size == 0 )
	{
		return -1;
	}
	else if( size == 1 )
	{
		size--;
		return array[1];
	}
	else if( size == 2 )
	{
		int temp = array[1];
		array[1] = array[2];
		size--;
		return temp;
	}	
	else //size >= 3
	{
		int temp = array[1];
		array[1] = array[size];
		size--;
		trickleDown( 1 );
		return temp;
	}
}

int MinMaxHeap::deleteMax()
{
	
	if( size == 0 )
	{
		return -1;
	}
	else if( size == 1 )
	{
		size--;
		return array[1];
	}
	else if( size == 2 )
	{
		size--;
		return array[2];
	}	
	else //size >= 3
	{
		int maxIndex = getMaxIndex();
		int temp = array[maxIndex];
		array[maxIndex] = array[size];
		size--;
		trickleDown( maxIndex );
		return temp;	
	}
}

void MinMaxHeap::increaseKey( int i, int amount )
{	
	array[i] += amount;
	trickleDown( i );
	bubbleUp( i );
}

void MinMaxHeap::decreaseKey( int i, int amount )
{
	array[i] -= amount;
	trickleDown( i );
	bubbleUp( i );
}

MinMaxHeap::~MinMaxHeap()
{
	delete [] array;
}























































