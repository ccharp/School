#include <iostream>
#include <string>
#include <cstdlib>
#include "MyDlist.h"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc < 2)
        {
            cout << "hw1 inputFile" << endl; 
            exit(0);
        }
        string file1 = argv[1];
       
	//calls constructor
        MyDList dllist(file1);

	return 0;
}
