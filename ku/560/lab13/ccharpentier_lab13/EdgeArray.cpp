#include "EdgeArray.h"

using std::cout;
using std::endl;

EdgeArray::EdgeArray()
{
    capacity = CAPACITY_INCREMENT;
    size = 0;
    items = new Edge[capacity];
	comparisons = 0;
}

EdgeArray::~EdgeArray()
{
	delete [] items;
}

Edge EdgeArray::operator[] (int i)
{
	return items[i];
}

int EdgeArray::getSize()
{
	return size;
}

void EdgeArray::append( int v, int w, int cost )
{
	Edge x = Edge( v, w, cost );
    if( size == capacity )
    {
        cout << "EdgeArray at capacity;" << endl;
        return;
    }

	// Appends integer on end of array 
    items[size] = x;
	
    size++;
}   

void EdgeArray::print()
{
	// Prints elements of the array
    for( int i = 0; i < size; i++ )
    {
		items[i].print();
		cout << " ";
    }

    cout << endl;
}

void EdgeArray::printSimple()
{
	// Prints elements of the array
    for( int i = 0; i < size; i++ )
    {
		items[i].printSimple();
		cout << " ";
    }

    cout << endl;
}


void EdgeArray::insert( int i, int v, int w, int cost )
{
	Edge x = Edge( v, w, cost );
	if( i > size || i < 0)
	{
		comparisons++;
	}
	else if( size+1 >= capacity )
	{
		comparisons += 2;
		cout << "Over capacity. Can't insert." << endl;
	}
	else
	{	// Shift all elements down 1
		for( int j = size-1; j >= i; j-- )
		{
			comparisons++;
			items[j+1] = items[j];	
		} 
		items[i] = x;
		size++;
	}
}

Edge EdgeArray::remove( int i )
{
	Edge edge = Edge();
	if( i >= size || i < 0)
	{
	} 
	else
	{		
		edge = items[i];
		for( ; i < size; i++ )
		{
			comparisons++;
			items[i] = items[i+1];
		}
		size--;
	}
	comparisons++;

	return edge;
}

void EdgeArray::sort()
{
	mergeSort( 0, size-1 );
}

void EdgeArray::mergeSort( int low, int high )
{
	int middle;// = (low + high)/2;
	if( low < high )
	{
		middle = (low + high)/2;
		mergeSort( low, middle );
		mergeSort( middle + 1, high );
		merge( low, middle, high );
	}
}

void EdgeArray::merge( int low, int middle, int high )
{
	int h = low;
	int i = low;
	int j = middle + 1;
	Edge temp[size];

	while ( (h <= middle) && (j <= high) )
	{
		if( items[h].cost <= items[j].cost )
		{
			temp[i] = items[h];
			h++;
		}
		else
		{
			temp[i] = items[j];
			j++;
		}
		i++;
	}

	if( h > middle )
	{
		for( int k = j; k <= high; k++ )
		{
			temp[i] = items[k];
			i++;
		}
	}
	else
	{
		for( int k = h; k <= middle; k++ )
		{
			temp[i] = items[k];
			i++;
		}
	}
	for( int k = low; k <= high; k++ )
	{
		items[k] = temp[k];
	}
}

int EdgeArray::getComparisons()
{
	return comparisons;
}
























