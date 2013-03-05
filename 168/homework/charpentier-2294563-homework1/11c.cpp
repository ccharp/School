#include <iostream>

using namespace std;

int main()
{

int age;

//if you are not old enough to vote, program will run until you enter a valid age
do
{

cout << "Please enter your age: ";
cin >> age;

	//program will terminate if you are ellegable to vote
        if (age >= 18)
	{
		cout << "You can vote\n";
	}
	else
	{	
		cout << "You are not old enough to vote\n";
	}
}while (age < 18);

return 0;
}
