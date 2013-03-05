#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#define ARRAY_SIZE 100

using namespace std;

void createRandomArray(int arr[]);

//partitions and sorts given array
void qSort(int array[], int left, int right);


int main()
{    
    int theArray[ARRAY_SIZE];

    createRandomArray(theArray);
	
	int count = 1;
	//print unsorted array
	cout<< "Unsorted: " << endl;
	for(int i=0; i<ARRAY_SIZE; i++)
	{	
		cout << setw(3) << theArray[i] << " ";	
		if(count==10)
		{
			cout << endl;
			count = 0;
		}
		count++;
	}
	cout << endl;
	
	qSort(theArray, 0, ARRAY_SIZE-1);
	count = 1;
	//print sorted array
	cout << "Sorted: " << endl;
	for(int i=0; i<ARRAY_SIZE; i++)
	{
		cout << setw(3) << theArray[i] << " ";	
		if(count==10)
		{
			cout << endl;
			count = 0;
		}
		count++;
	}
	cout << endl;

    return 0;
}

//fills array with randomly generated numbers
void createRandomArray(int arr[])
{
    srand( time(NULL) );

    for( int i = 0; i < ARRAY_SIZE; i++ )
    {        
        arr[i] = rand() % 256;
    }

}

//Partitions and sorts given array
void qSort(int arr[], int left, int right) 
{
	  //sets i and j to front and back and pivot as value at middle index
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
	
	  //Partitioner
      while (i <= j) 
	  {		//gets values at indexes around pivot
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
			//swaps them of j is larger
            if (i <= j) 
			{	  //'swap' function in a nutshell
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
	
	  //recursive function call
      if (left < j)
            qSort(arr, left, j);
      if (i < right)
           qSort(arr, i, right);

}


