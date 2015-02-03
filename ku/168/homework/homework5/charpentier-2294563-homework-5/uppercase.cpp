//uppercase.cpp
//Programmer: Corbin Charpentier
//Descrpription: Program converts a string of characters from lowercase to upper case
//Date Created: 12.6.10

#include <iostream>
using namespace std;

int main()
{
	int array_size;
	char *array, next, uppernext;
	array = new char[array_size]; //creates you dynamic array, 'array'.
	
	cout << "Please enter the size of the string to be made all CAPS: ";
	cin >> array_size;
	cout << "Now enter the string you wish to be made all CAPS: "; 
	
	//fills dynamic array
	for(int i=0; i < array_size + 1; i++)
	{
		cin.get(next);

		//if 'next' is lower case, program changes it to upper case and fills array with that character
		if(islower(next)) 
		{
			next = toupper(next);
		}
		array[i] = next;
	}

	//outputs filled array
	for(int i=0; i < array_size + 1; i++)
	{
		cout << array[i];
	}
	
	cout << endl;
return 0;
}
