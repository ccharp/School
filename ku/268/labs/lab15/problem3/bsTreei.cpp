#include <cstdlib>
#include <iostream>
#include <string> 
#include <fstream>
#include "bsTree.h"

using namespace std;

int main(int argc, char* argv[])//takes two inputs: inputfile and outputfile
{
	if(argc < 3)
        {
            cout << "Problem with input or output files" << endl; 
            exit(0);
        }
    string input = argv[1];
	string output = argv[2];

	//opens input and output files and handles associated syntax errors
	ifstream fin(input.c_str()); //opens intput file
	if(fin.fail())
	{
		cout << "intput failed to open" << endl;
		exit(1);
	}
	ofstream fout(output.c_str()); //opens outputfile
	if(fout.fail())	
	{
		cout << "output failed to open" << endl;
		exit(1);
	}

	bsTree<int> tree; //calls constructor with type int
	
	string<int> com;
	int x;

	while(fin >> com) //takes commands while not end of file
	{
		if(com == "Insert")
		{
			fin >> x;
			tree.insert(x);
		}
		else if(com == "Search")
		{
			fin >> x;
			tree.search(x, fout);
		}
		else if(com == "In-order-traversal")
		{
			tree.inOrderTraversal(fout);
		}
		else if(com == "Delete")
		{	
			fin >> x;
			tree.remove(x);
		}
		else
		{
			cout << " SyntaxError: command '" << com 
				 << "' does not exist. Ignoring." << endl;
		}
	}	

	return 0;
}
























