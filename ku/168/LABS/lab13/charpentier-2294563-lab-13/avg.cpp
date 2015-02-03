//avg.cpp
//Programmer: Corbin Charpentier
//11.15.2010

#include <iostream>
using namespace std;

int main()
{

	//variable declations
        double* pInt;
        int num;
	double sum(0), AVG;

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
		sum = pInt[i] + sum;
	}
	
	AVG = sum/num;//computes average of array
	
	//outputs results to user
	cout << "The average of " << num << " numbers is " << AVG << "." << endl;

return 0;
}
