#include <cstdlib>
#include <iostream>
#include <string> 
#include <fstream>
#include "Graph.cpp"
#include <vector>

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

	Graph graph; //calls constructor with type int
	
	int n1, n2, w;

	while(fin >> n1 >> n2 >> w) //takes commands while not end of file
	{
		graph.insertEdge(n1, n2, w);
	}	

	cout << "Original Graph: " << endl;
	cout << graph.toString() << endl;
	
	cout <<"Minimal Spanning Tree: " << endl;
	cout << graph.getMST()->toString() << endl;

	return 0;
}
