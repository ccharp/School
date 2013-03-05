
#include "BinaryHeap.h"

using namespace std;

BinaryHeap::BinaryHeap( int* data, int n )
{
	size = n;
	
	array = new int[DEFAULT_CAPACITY];
	
	for( int i = 0; i < size; i++ )
	{
		array[i] = data[i];
	}
	
	buildHeap();
}

void BinaryHeap::buildHeap()
{
	for( int i = 0; i < size; i++ )
	{	
		percolateDown( array[i], i );
	}
}

void BinaryHeap::percolateDown(int item, int hole)
{	
	// Node is a leaf
	if( 2 * hole + 1 >= size )
	{
		return;
	}
	
	int child = 2 * i + 1;
	if( array[child] < array[child + 1] )
	{
		child += 1;
	}
	
	if(
}

void BinaryHeap::insert(int item)
{

}

void BinaryHeap::print()
{
	for( int i = 0; i < size; i++ )
	{	
		cout << array[i] << " ";
	}
	cout << endl;
}

void BinaryHeap::percolateUp(int item, int hole)
{

}

bool BinaryHeap::isEmpty()
{
	return size == 0;
}

int BinaryHeap::deleteMin()
{

}
	
int BinaryHeap::find(int item)
{

}

void BinaryHeap::remove(int item)
{

}

int BinaryHeap::deleteMax()
{

}
