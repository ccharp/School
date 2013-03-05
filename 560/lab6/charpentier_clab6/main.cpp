#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "BinaryHeap.h"
#include "BinarySearchTree.h"
#include "experiment.h"
using namespace std;



void test(int n){

	Timer timer;
	BinarySearchTree tree;

	int *original_values = generateRandomDataRange( n, n );
	int *insert_values = generateRandomDataRange( 5000, n );
	int *search_values = generateRandomDataRange( 5000, n );

	cout << "---Build Sturctures size: " << n << endl; 	
	// Build Search Tree
	timer.start();
	for( int i = 0; i < n; i++ )
	{
		tree.insert( original_values[i] );
	}
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	cout << "Tree build: " << timer.stop() << endl;
	tree.resetComparisons();
	
	// Build Heap
	timer.start();
	BinaryHeap heap( original_values, n );
	cout << "Heap comparisons: " << heap.getComparisons() << endl;
	cout << "Heap build: " << timer.stop() << endl;	
	heap.resetComparisons();

	
	//////////////////////////INSERT///////////////////////////
	cout << endl << "---Insertion: " << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		tree.insert( original_values[i] );
	}
	cout << "Tree insert: " << timer.stop() << endl;
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	tree.resetComparisons();
	

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		heap.insert( original_values[i] );
	}
	cout << "Heap insert: " << timer.stop() << endl;
	cout << "Heap comparisions: " << heap.getComparisons() << endl;
	heap.resetComparisons();
	
	
	///////////////////////SEARCH////////////////////////////
	// Search tree
	
	cout << endl << "----Search: " << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		tree.find( search_values[i] );
	}
	cout << "Tree search: " << timer.stop() << endl;
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	tree.resetComparisons();
	
	// Search Heap
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		heap.find( search_values[i] );
	}
	cout << "Heap search: " << timer.stop() << endl;
	cout << "Heap comparisions: " << heap.getComparisons() << endl;
	heap.resetComparisons();

	/////////////////////////REMOVE//////////////////////////
	cout << endl << "----Remove: "<< endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		tree.remove( search_values[i] );
	}
	cout << "Tree remove: " << timer.stop() << endl;
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	tree.resetComparisons();
	
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		heap.remove( search_values[i] );
	}
		cout << "Heap remove: " << timer.stop() << endl;
	cout << "Heap comparisions: " << heap.getComparisons() << endl;
	heap.resetComparisons();

	////////////////////////findMin//////////////////////////
	cout << endl << "----FindMin: " << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		tree.findMin();
	}
	cout << "Tree findMIn: " << timer.stop() << endl;
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	tree.resetComparisons();

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		heap.findMin();
	}
	cout << "Heap findMin: " << timer.stop() << endl;
	cout << "Heap comparisions: " << heap.getComparisons() << endl;
	heap.resetComparisons();

	///////////////////////DELETEMIN///////////////////////
	cout << endl << "----DeleteMin" << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		tree.deleteMin();
	}
	cout << "Tree deleteMin: " << timer.stop() << endl;
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	tree.resetComparisons();

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		heap.deleteMin();
	}
	cout << "Heap deleteMin: " << timer.stop() << endl;
	cout << "Heap comparisions: " << heap.getComparisons() << endl;
	heap.resetComparisons();

	///////////////////////FINDMAX////////////////////////
	cout << endl << "----FindMax: " << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		tree.findMax();
	}
	cout << "Tree findMax: " << timer.stop() << endl;	
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	tree.resetComparisons();
	
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		heap.findMax();
	}
	cout << "Heap findMax: " << timer.stop() << endl;
	cout << "Heap comparisions: " << heap.getComparisons() << endl;
	heap.resetComparisons();

	///////////////////////DELETEMAX/////////////////////////
	cout << endl << "----DeleteMax: " << endl;
	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		tree.deleteMax();
	}	
	cout << "Tree deleteMax: " << timer.stop() << endl;
	cout << "Tree comparisions: " << tree.getComparisons() << endl;
	tree.resetComparisons();

	timer.start();
	for( int i = 0; i < 5000; i++ )
	{
		heap.deleteMax();
	}
	cout << "Heap deleteMax: " << timer.stop() << endl;
	cout << "Heap comparisions: " << heap.getComparisons() << endl;
	heap.resetComparisons();	

	if( !original_values || !insert_values || !search_values )
	{
		cout << endl << "Array is empty" << endl;
	}

	delete [] original_values;	
	delete [] insert_values;
	delete [] search_values;
}

int main() {
	
	test(12000);
	test(24000);
	test(36000);
	test(48000);

	//int *original_elements = generateRandomData( 
	
	return 0;
}
