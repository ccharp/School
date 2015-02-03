// min.cpp
// Programmer: Corbin Charpentier
// 11.30.2010

#include <iostream>
using namespace std;

int main()
{

	//variable declations
        double* pInt;
        int num;
	double temp, min(100000);

        // User Information
        cout << "Please input how many numbers you want to put in the array: ";
        cin >> num;

	cout << "Please input " << num << " numbers: ";
        pInt = new double[num]; // declares new dynamic array of double type
        for(int i=0; i<num; i++)//fills array with user input
	{
             cin >> pInt[i];
	}
	
	for(int i=0; i<num; i++)//computes sum of array's components
	{
		temp = pInt[i];
		if (temp < min)
			min = temp;
	}
	
	
	
	//outputs results to user
	cout << "The smallest number is " << min << ".\n";

return 0;
}
