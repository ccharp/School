// ex3.cpp
#include <iostream>
using namespace std;

int main()
{
    // Variable Declaration
    int* pInt;
    int num;

    // User Information
    cout << "Please input how many numbers you want to put in the array: ";
    cin >> num;

    // Get Input
    cout << "Please input " << num << " integers: ";
    pInt = new int[num];
    for(int i=0;i<num;i++)
        cin >> pInt[i];

    // Output
    cout << "The array is: \n";
    for(int i=0;i<num;i++)
        cout << pInt[i] << " ";
    cout << endl;

    // Release memory
    delete[] pInt;

    return 0;
}

