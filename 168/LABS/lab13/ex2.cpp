// ex2.cpp
#include <iostream>
using namespace std;

int main()
{
    // Variable Declaration
    int *p1, *p2;

    p1 = new int; // INSERT YOUR CODE: use new operator to create p1 as a dynamic int variable.
    *p1 = 42;
    p2 = p1; // INSERT YOUR CODE: assign p1 to p2.
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    *p2 = 53;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    p1 = new int; // INSERT YOUR CODE: use new operator to create p1 as a dynamic int variable.
    *p1 = 88;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;
    
    delete p1; // INSERT YOUR CODE: release the memory using delete.

    return 0;
}

