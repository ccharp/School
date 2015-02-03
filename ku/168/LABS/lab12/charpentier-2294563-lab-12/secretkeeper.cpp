#include <iostream>
#include <string>
#include <cstring>
using namespace std;




int main()
{
	string line;
	char next;
	cout << "Please type a word or phrase and end it with enter key." << endl; 
	getline(cin, line);
	cout << line << endl;

	for(int i=0; i < line.length(); i++)
	{
		
		if(isdigit(line[i]))
		{
			line[i] = 'x';
		}
	}

	cout << line << endl;
			
	return 0;
}


