#include <iostream>
     using namespace std;
    
     void myFunc(int& a, int b);

     int main()
     {
          int a = 5, b = 3;

          myFunc(b, a);
          
          cout << "Result in main(): \n";
          cout << "a: " << a 
               << "\nb: " << b << endl;

          return 0;
     }

     void myFunc(int& a, int b)
     {
          a *= 2;
          b++;

          cout << "Result in myFunc: \n";
          cout << "a: " << a 
               << "\nb: " << b << endl;
     }

