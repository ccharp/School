#include "MaxHeap.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{    
    MyHeap<int> h1;
    h1.insert(10);
    h1.insert(5);  
    h1.insert(12);
    cout << h1.toString();
    h1.deleteMax();
    cout << h1.toString();
    return 0;
}


