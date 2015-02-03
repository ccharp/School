#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "List.h"
#include "Array.h"
using namespace std;

void concatenate(List& L1, List& L2){
	if( !L2.isEmpty() )
	{
		L1.append( L2.remove(0) );
		concatenate( L1, L2 );
	}
}

int main() {
	
	// Create data structures
	List L;
	Array A;
	
	// Get items
	int x;
	ifstream dataFile ("data.txt");
	if (dataFile.is_open()) {
		while (dataFile >> x){
			L.append(x);
			A.append(x);
		}
	}
	dataFile.close();
	
	//////////////////////
	/// Perform List tests
	cout << "==List==" << endl;
	L.reverse();
	// Test remove/insert
	// (convert reverse fibonacci sequence to count down)
	L.remove(3);
	L.remove(2);
	L.remove(1);
	L.remove(0);
	L.insert(0, 10);
	L.insert(1, 9);
	L.insert(3, 6);
	L.remove(7);
	L.insert(3, 7);
	L.insert(6, 4);
	L.remove(10);
	L.print();
	// Test find
	cout << L.find(10) << L.find(8) << L.find(6) << L.find(3) << L.find(1) << endl;
	// Test concatenate
	List otherL;
	otherL.append(2);
	otherL.append(3);
	otherL.append(4);
	otherL.append(5);
	concatenate(L, otherL);
	L.print();
	
	cout << endl;
	
	//////////////////////
	/// Perform Array tests
	cout << "==Array==" << endl;
	A.reverse();
	// Test remove/insert
	// (convert reverse fibonacci sequence to count down)
	A.remove(3);
	A.remove(2);
	A.remove(1);
	A.remove(0);
	A.insert(0, 10);
	A.insert(1, 9);
	A.insert(3, 6);
	A.remove(7);
	A.insert(3, 7);
	A.insert(6, 4);
	A.remove(10);
	A.print();
	// Test sort/find
	A.sort();
	A.print();
	cout << A.find(10) << A.find(8) << A.find(6) << A.find(3) << A.find(1) << endl;
	

	return 0;
}
