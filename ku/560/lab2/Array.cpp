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
