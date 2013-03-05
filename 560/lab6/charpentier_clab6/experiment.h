#ifndef TIMETEST_H_
#define TIMETEST_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Timer.h"
using namespace std;

//Timer timer = Timer();

int* generateRandomDataRange(int n, int range)
{
	int *array = new int[n];
	
	for( int i = 0; i < n; i++ )
	{
		array[i] = rand() % range;
	} 

	return array;
}

#endif /* TIMETEST_H_ */
