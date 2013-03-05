#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "List.h"
#include "Array.h"
#include "experiment.h"
using namespace std;



void test(int n){
	List L;
	Array A;
	
	Timer timer;

	/* implement testing sequence */
	int *original_elements = generateRandomData( n );
	int *insert_positions  = generateRandomData( n/2 );
	int *insert_elements   = generateRandomData( n/2 );
	int *remove_positions  = generateRandomData( n/2 );
	
	int duration;

	// Append original_elements 
	for( int i = 0; i < n; i++ )
	{
		A.append( original_elements[i] );
		L.append( original_elements[i] );
	}

	timer.start();
	// Insert elements Array 
	for( int i = 0; i < 10000; i++ )
	{
		A.insert( insert_positions[i], insert_elements[i] );
	}
	cout << endl << "Array Insert: " << endl;
	timer.printTime( timer.stop() );

	// Insert Elements List
	timer.start();
	for( int i = 0; i < 10000; i++ )
	{
		L.insert( insert_positions[i], insert_elements[i] );
	}
	cout << endl << "List Insert: " <<  endl;
	timer.printTime( timer.stop() );
	
	// Remove elements
	timer.start();
	for( int i = 0; i < 10000; i++ )
	{
		A.remove( remove_positions[i] );
	}
	cout << endl << "Array Remove: " << endl; 
	timer.printTime( timer.stop() );
	
	timer.start();
	for( int i = 0; i < 10000; i++ )
	{
		L.remove( remove_positions[i] );
	}
	cout << endl << "List remove: " << endl;
	timer.printTime( timer.stop() );

	/*cout << "Array Insert: "   << arrInsert << "\nList Insert: " << listInsert 
		 << "\nArray Remove: " << arrRemove << "\nList Remove: " << listRemove << endl;
	*/
	cout << "Array Comparisions: " << A.getComparisons() << " List comparisons: " << L.getComparisons() << endl;;
	
}

int main() {
	
	test(25000);
	test(50000);
	test(75000);
	test(100000);

	//int *original_elements = generateRandomData( 
	
	return 0;
}
