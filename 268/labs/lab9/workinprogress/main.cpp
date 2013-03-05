#include <iostream>
#include "MyList.h"

using namespace std;

int main(int argc, char * argv[] )
{
	MyList aList;
	
	aList.push_back(1);
	aList.push_back(2); 
    aList.push_back(3); 
	
	try
	{
		aList.insert(8,8);
	}
	catch( MyDListIndexOutOfRange & s )
	{
		cout << s.what() << endl;
	}
	
	cout << "List: " << aList.toString() << endl;

	return 0;
}

