//example1.cpp
#include <iostream>
using namespace std;

//Function declaration
int incrByValue(int x);
int incrByReference(int& x);

int main()
{
  int a=2, b=2;
  int c1=0, c2=0;
  //Function call
  c1 = incrByValue(a);
  cout << " After call-by-value, a value is " << a << endl;
  cout << " After call-by-value, b value is " << b << endl;
  cout << " After call-by-value, c1 value is " << c1 << endl;
  
  c2 = incrByReference(b);
  cout << " After call-by-reference, a value is " << a << endl;
  cout << " After call-by-reference, b value is " << b << endl;
  cout << " After call-by-reference, c2 value is " << c2 << endl;

  return 0;
}

//Call-by function to increase x by 1 
int incrByValue(int x)
{
    x = x+13;
    return x;
}

//Call-by-reference to increase x by 1 
int incrByReference( int& x )
{
    x = x+13;
    return x;
}

