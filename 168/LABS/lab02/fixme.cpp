#include <iostream>
using namespace std;
main()

{

int one(1.00), two(1.41), three(1.73), four(1.00), s1, s2, s3, s4;
cout <<"Enter the four numbers for which you want to find the squares";
cout <<"Square\n";

cin >>one>>two>>three>>four;

s1 = one * one;
s2 = two * two;
s3 = three * three;
s4 = four * four;

cout << "The squares are"<<endl;
cout << s1 << endl;
cout << s2 << endl;
cout << s3 << endl;
cout << s4 << endl;

return 0;

}

