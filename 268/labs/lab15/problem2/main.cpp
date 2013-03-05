#include <cstdlib>
#include <iostream>
#include <string> 
#include <fstream>
#include "bsTree.h"

using namespace std;

int main(int argc, char* argv[])//takes two inputs: inputfile and outputfile
{
	if(argc < 2)
        {
            cout << "Problem with input or output files" << endl; 
            exit(0);
        }
    string input = argv[1];
	//string output = argv[2];
	
	//opens input and output files and handles associated syntax errors
	ifstream fin(input.c_str()); //opens intput file
	if(fin.fail())
	{
		cout << "intput failed to open" << endl;
		exit(1);
	}
	ofstream fout;
	bsTree<int> tree;
	int x;
	while(fin >> x)
	{
		tree.insert(x);
	}

	tree.preOrderTraversal();
	return 0;
}
