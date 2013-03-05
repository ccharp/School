#include <iostream>
#include <fstream>
#include <cstdlib>
#include "DisjointSets.h"
using namespace std;

int main() {
	
	// Initialize
	int n = 10;
	DisjointSets D(n);
	D.print();
	
	// Test merges
	D.merge(1,2);
	D.merge(3,4);
	D.merge(1,3);
	D.print();
	
	// Verify path compression for 4
	cout << D.find(4) << endl << endl;
	D.print();
	
	// Test merge special cases
	D.merge(2,5); // non-root merge
	D.merge(2,5); // duplicate merge
	D.merge(9,1); // higher-ranked y
	D.print();
	
	// Develop independent non-trivial partitions
	D.merge(6,7);
	D.merge(0,8);
	D.print();
	
	// Show partitions
	for(int i = 0; i < n; i++)
		printf("%4d", D.find(i));
	printf("\n\n");
	
	// Merge all sets
	D.merge(0,6);
	D.print();
	D.merge(0,1);
	D.print();
	
	// Show partitions
	for(int i = 0; i < n; i++)
		printf("%4d", D.find(i));
	printf("\n\n");

	return 0;
}