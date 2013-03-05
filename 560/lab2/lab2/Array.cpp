#include "Array.h"

using std::cout;
using std::endl;

Array::Array()
{
    capacity = CAPACITY_INCREMENT;
    size = 0;
    items = new int[capacity];
}

Array::~Array()
{
	delete [] items;
}

void Array::append( int x )
{
	// If array is full, don't add anything
    if( size == capacity )
    {
        cout << "Array at capacity; cannont append." << endl;
        return;
    }

	
	// Appends integer on end of array 
    items[size] = x;
	
    size++;
}   

void Array::print()
{
	// Prints elements of the array
    for( int i = 0; i < size; i++ )
    {
        cout << items[i] << " ";
    }

    cout << endl;
}

void Array::reverse()
{
    int temp;

	// Reverses elements of array
    for( int i = 0, j = size - 1; i < size/2; i++, j-- )
    {
        temp = items[i];
        items[i] = items[j];
        items[j] = temp; 
    }
}

void Array::insert( int i, int x )
{
	if( i > size || i < 0)
	{
		cout << "Index, " << i << ", out of bounds for insertion." << endl;
	}
	else if( size+1 >= capacity )
	{
		cout << "Over capacity. Can't insert." << endl;
	}
	else
	{	// Shift all elements down 1
		for( int j = size-1; j >= i; j-- )
		{
			items[j+1] = items[j];	
		} 
		items[i] = x;
		size++;
	}
}

int Array::remove( int i )
{
	if( i >= size || i < 0)
	{
		cout << "Index, " << i << ", out of bounds for removal." << endl;
	} 
	else
	{		
		for( ; i < size; i++ )
		{
			items[i] = items[i+1];
		}
		size--;
	}
}

int Array::find( int x )
{
	return binarySearch( x, 0, size );
}

int Array::binarySearch( int key, int low, int high )
{
	int middle = (low + high)/2;

	if( low < high )
	{
		if( items[middle] == key )
		{	
			return middle;
		}
		else if( key < items[middle] )
		{
			return binarySearch( key, low, middle );
		}	
		else
		{
			return binarySearch( key, middle + 1, high );
		}
	}
	return -1;
}

void Array::sort()
{
	mergeSort( 0, size-1 );
}

void Array::mergeSort( int low, int high )
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

void Array::merge( int low, int middle, int high )
{
	int h = low;
	int i = low;
	int j = middle + 1;
	int temp[size];

	while ( (h <= middle) && (j <= high) )
	{
		if( items[h] <= items[j] )
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
























