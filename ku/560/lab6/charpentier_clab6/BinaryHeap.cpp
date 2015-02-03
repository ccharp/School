#include "BinaryHeap.h"

using namespace std;

BinaryHeap::BinaryHeap( int* data, int n )
{
	size = n;
	count = 0;
	array = new int[DEFAULT_CAPACITY];
	
	for( int i = 0; i < size; i++ )
	{	
		count++;
		array[i] = data[i];
	}

	buildHeap();
}

BinaryHeap::~BinaryHeap()
{
	delete [] array;
}

void BinaryHeap::buildHeap()
{
	for( int i = size -1 ; i >= size / 2;  i-- )
	{	
		count++;
		percolateDown( array[i], i );
	}
}

void BinaryHeap::percolateDown(int item, int hole)
{	
	if( hole >= size )
	{
		count++;
		return;
	}

	int child;
	int temp = array[hole];
	for( ;2 * hole + 1 <= size; hole = child )
	{
		count++;
		child = 2 * hole + 1;
		if( (child + 1 != size) && (array[child + 1] < array[child]) )
		{
			count++;
			child += 1;
		}
		if( array[child] < temp )
		{
			count++;
			array[hole] = array[child];
		}
		else
		{
			break;
		}
	}

	array[hole] = temp;
}

void BinaryHeap::insert(int item)
{
	if( size == DEFAULT_CAPACITY )
	{
		count++;
		cout << "Heap too large." << endl;
	}	

	array[size] = item;
	size++;
	percolateUp( item, size );
}

void BinaryHeap::print()
{
	for( int i = 0; i < size; i++ )
	{	
		count++;
		cout << array[i] << " ";
	}
	cout << endl;
}

void BinaryHeap::percolateUp(int item, int hole)
{
	for( ; hole > 1 && item < array[hole/2]; hole /= 2 )	
	{
		count++;
		if( array[hole] > item )
		{
			count++;
			array[hole] = array[hole/2];
		}
	}
	array[hole] = item; 
}

bool BinaryHeap::isEmpty()
{
	return size == 0;
}

int BinaryHeap::deleteMin()
{
	if( isEmpty() )
	{
		count++;
		cout << "Can't delete min of an empty heap." << endl;
		return -1;
	}
	int x = array[0];
	array[0] = array[size - 1];
	size--;
	percolateDown( array[0], 0 );
	
	return x;
}
	
int BinaryHeap::find(int item)
{
	int location = -1;
	for( int i = 0; i < size; i++ )
	{
		count++;
		if( array[i] == item )
		{
			count++;
			location = i;
			break;
		}
	}

	return location;
}

void BinaryHeap::remove(int item)
{
	int index = -1;

	// Find index of item to remove
	for( int i = 0; i < size; i++ )
	{
		count++;
		if( array[i] == item )
		{
			count++;
			index = i;
			break;
		}
	}

	if( index != -1 )
	{
		count++;
	 	array[index] = array[size - 1];
		size--;
		percolateDown( array[index], index );
	}
	else
	{
		//cout << "Removal item not on heap." << endl;
	}
}

int BinaryHeap::deleteMax()
{
	int indexBiggest = 0;

	// Find index of the biggest
	for( int i = 0; i < size; i++ )
	{
		count++;
		if( array[i] > array[indexBiggest] )
		{
			count++;
			indexBiggest = i;
		}
	}

	int biggest = array[indexBiggest];

	array[indexBiggest] = array[size -1];
	size--;	

	percolateDown( array[indexBiggest], indexBiggest );	
	
	return biggest;
}

int BinaryHeap::findMin()
{
	return array[0];	
}

int BinaryHeap::findMax()
{
	int biggest = (size + 1) / 2;
	for( int i = ( size + 1 ) / 2; i < size; i++ )
	{
		count++;
		if( array[i] > biggest );
		{
			count++;
			biggest = array[i];
		}
	} 
	return array[biggest];
}













