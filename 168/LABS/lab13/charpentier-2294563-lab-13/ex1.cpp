// ex1.cpp
#include <iostream>
using namespace std;

int main()
{
    // Variable Declaration
    double dValue = 1.5;
    int iValue = 10;
    double *pDouble; // INSERT YOUR CODE: Declare a double-typed pointer named as pDouble.
    int *pInt; // INSERT YOUR CODE: Declare a int-typed pointer named as pInt.
    pDouble = &dValue; // INSERT YOUR CODE: Assign dValue's address to pDouble. 
    pInt = &iValue; // INSERT YOUR CODE: Assign iValue's address to pInt.

    iValue++;
    dValue *= 3.0;

    // Outputs: shows the relationship between pointer and the variable linked to the pointer
    cout << *pInt << endl;
    cout << *pDouble << endl;

    return 0;
}

