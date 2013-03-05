// cin_tst.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
        string str1,str2;
        cout << "Please input a string: ";
        cin >> str1;
        getline(cin,str2);
        cout << str1 << endl;
        cout << str2 << endl;
}

