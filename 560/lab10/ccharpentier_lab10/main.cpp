#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "BinomialQueue.h"
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include "experiment.h"
using namespace std;

void resetCounts( BinomialQueue &bQueue, LeftistHeap &lHeap, SkewHeap &sHeap )
{
	bQueue.resetComparisons();
	lHeap.resetComparisons();
	sHeap.resetComparisons();	
}

void test(int n){

	cout << "\n\nAt Test: " << n << endl<< endl;

	Timer timer;
	BinomialQueue bQueue;
	LeftistHeap lHeap;
	SkewHeap sHeap;

	int *original_values = generateRandomDataRange( n, n );
	int *insert_values = generateRandomDataRange( 5000, n );

	cout << "---Build Sturctures size: " << n << endl; 	
	// Build Binomial Queue
	timer.start();
	for( int i = 0; i < n; i++ )
	{
		bQueue.insert( original_values[i] );
	}
	cout << "bQueue comparisions: " << bQueue.getComparisons() << endl;
	cout << "bQueue build: " << timer.stop() << endl;
	
	// build lHeap
	timer.start();
	for( int i = 0; i < n; i++ )
	{
		lHeap.insert( original_values[i] );
	}
	cout << "lHeap comparisions: " << lHeap.getComparisons() << endl;
	cout << "lHeap build: " << timer.stop() << endl;

	timer.start();
	for( int i = 0; i < n; i++ )
	{
		sHeap.insert( original_values[i] );
	}
	cout << "sHeap comparisions: " << sHeap.getComparisons() << endl;
	cout << "sHeap build: " << timer.stop() << endl;

	resetCounts( bQueue, lHeap, sHeap );
	
	//////////////////////////INSERT///////////////////////////
	cout << endl << "---Insertion: " << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		bQueue.insert( insert_values[i] );
	}
	cout << "bQueue insert: " << timer.stop() << endl;
	cout << "bQueue comparisions: " << bQueue.getComparisons() << endl;

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		lHeap.insert( insert_values[i] );
	}
	cout << "lHeap insert: " << timer.stop() << endl;
	cout << "lHeap comparisions: " << lHeap.getComparisons() << endl;
	
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		sHeap.insert( insert_values[i] );
	}
	cout << "sHeap insert: " << timer.stop() << endl;
	cout << "sHeap comparisions: " << sHeap.getComparisons() << endl;

	resetCounts( bQueue, lHeap, sHeap );
	
	////////////////////////findMin//////////////////////////
	cout << endl << "----FindMin: " << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		bQueue.findMin();
	}
	cout << "bQueue findMIn: " << timer.stop() << endl;
	cout << "bQueue comparisions: " << bQueue.getComparisons() << endl;

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		lHeap.findMin();
	}
	cout << "lHeapfindMIn: " << timer.stop() << endl;
	cout << "lHeapcomparisions: " << lHeap.getComparisons() << endl;

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		sHeap.findMin();
	}
	cout << "sHeapfindMIn: " << timer.stop() << endl;
	cout << "sHeapcomparisions: " << sHeap.getComparisons() << endl;

	resetCounts( bQueue, lHeap, sHeap );

	///////////////////////DELETEMIN///////////////////////
	cout << endl << "----DeleteMin" << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		bQueue.deleteMin();
	}
	cout << "bQueue deleteMin: " << timer.stop() << endl;
	cout << "bQueue comparisions: " << bQueue.getComparisons() << endl;

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		lHeap.deleteMin();
	}
	cout << "lHeap deleteMin: " << timer.stop() << endl;
	cout << "lHeap comparisions: " << lHeap.getComparisons() << endl;

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		sHeap.deleteMin();
	}
	cout << "sHeap deleteMin: " << timer.stop() << endl;
	cout << "sHeap comparisions: " << sHeap.getComparisons() << endl;

	resetCounts( bQueue, lHeap, sHeap );

	if( !original_values || !insert_values )
	{
		cout << endl << "Array is empty" << endl;
	}

	delete [] original_values;	
	delete [] insert_values;
}

int main() {
	
	test(12000);
	test(24000);
	test(36000);
	test(48000);

	//int *original_elements = generateRandomData( 
	
	return 0;
}
