#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

#define ARRAY_SIZE 100

using namespace std;

//Creates array filled with random integers
void createSortedRandomArray(int arr[]);

//binary search function
int bSearch(int a[], int size, int key, int offset);

int main()
{    
	int size = 100;
    int theArray[ARRAY_SIZE];
	int n, index;

	//calls finary search function
    createSortedRandomArray(theArray);

	//this loop was used for the purpose of testing
	/*for(int i = 0; i<100; i++)
	{
		cout << theArray[i] << " ";
	}*/

	//user input
	cout << "Enter the integer to search for: ";
	cin >> n;

	//sets index equl to returned value from binary search
	 index = bSearch(theArray, size, n, 0);
    
	//outputs results
	if(index < 100)
	{
		cout << n << " was found at index " << index << endl;
	}
	else
	{
		cout << "Key was not found" << endl;
	}
    return 0;
}

void createSortedRandomArray(int arr[])
{
    srand( time(NULL) );

    for( int i = 0; i < ARRAY_SIZE; i++ )
    {        
        arr[i] = rand() % 256;
    }

    sort( arr, arr + ARRAY_SIZE );    
}

/*Binary search function functions as follows:
-	Takes an array, size, key, and offset as parameters. Base case is if middle equls key.
-	Assuming the array is sorted, key is greater than middle, bSearch checks 
-	the top half of the array. If key is less than, checks the bottom half. A problem occurs
-	in addressing the index if key is greater than middle, so 'offset' is the distance 
-	from the first middle to the next. This sum is added to the returned value to provide
-	correct index for keys greater than the initial middle. 
*/
int bSearch(int a[], int size, int key, int offset)
{
	int middle;
	if(size < 1) return 0;

	if(size == 1)
	{
		return middle+offset;		

	}

	middle = size/2;

	if(key < a[middle])
		return bSearch(a, middle, key, offset);
	else if(key == a[middle])
	{
		
		return middle+offset;
	}
	else //if(key > a[middle])
	{
		offset = offset + middle + 1;
		return bSearch(a+middle+1, size-middle-1, key, offset);
	}
}










