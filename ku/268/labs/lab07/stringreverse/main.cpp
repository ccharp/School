#include <iostream>

using namespace std;

//reverses string
void reverse(string s, int size);

int main()
{
	string s;
	cout << "Enter string and I will reverse it: ";
	cin >> s; //user inputs string

	int size = s.size(); //get size of string
	reverse(s, size); //calls function to reverse string
	cout << endl;
	return 0;
}

void reverse(string s, int size)
{	//base case if size is zero
	if(size == 0)
		cout << s[0];
	else 
	{
		cout << s[size];
		reverse(s, size-1);//recursive call, subtracts size by 1
	}
}
