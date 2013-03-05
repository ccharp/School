#include <iostream>
#include "MyDlist.h"

using namespace std;

int main(int argc, char * argv[] )
{
	MyDlist<string> aStringList;
    MyDlist<int> aIntList;
	
	aStringList.push_back("one");
	aStringList.push_back("two"); 
    aStringList.push_back("three"); 
	
    aIntList.push_back(1);
    aIntList.push_back(2);
    aIntList.push_back(3);

    cout << "String List is: " << aStringList.toString() << endl;
    cout << "Int List is: " << aIntList.toString() << endl;

	return 0;
}



