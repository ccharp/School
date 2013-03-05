#include <iostream>

using namespace std;

int main()
{


int count = 0, sum;

//limite of count is 100
while(count <= 100)
    {
        cout << sum << endl;
        count = count + 2; //adds 2 to count each time
	sum = sum + count; //sum is previous sum plus 2
    } 
return 0;
}
