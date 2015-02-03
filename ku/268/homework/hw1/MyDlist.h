#include <iostream>
#include <fstream>

using namespace std;

class MyDlist {

private:
	int value;
	MyDlist * front;
	MyDlist * back;
public:
	MyDlist(string s1);
	~MyDlist();
};
