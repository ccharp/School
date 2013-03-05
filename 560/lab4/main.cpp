#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	
	// Create data structure
	BinarySearchTree tree;
	
	// Build tree using insert
	int v;
	ifstream dataFile ("data.txt");
	if(dataFile.is_open())
		while(dataFile >> v)
			tree.insert(v);			
	dataFile.close();

	// Test traversals
	tree.inOrderTraversal();
	tree.preOrderTraversal();
	tree.postOrderTraversal();
	
	// Test tree property methods
	cout << tree.leafCount() << endl;
	cout << tree.treeHeight() << endl;
	
	return 0;
}