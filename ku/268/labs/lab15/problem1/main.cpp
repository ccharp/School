#include <iostream>
#include <stdlib.h>
#include "MyDlist.h"

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

	//call constructor
	MyDlist<int> list1;
	MyDlist<int> list2;

	int x;
	while(fin >> x)
	{
		list1.push_back(x);
	}
		
	cout << "List1 is " << list1.toString() << endl;
	list2 = list1;
	cout << "list2 is " << list2.toString() << endl;

	return 0;
}
