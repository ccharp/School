#ifndef MYDLISTINDEXOUTOFRANGE_H
#define MYDLISTINDEXOUTOFRANGE_H

#include <stdexcept>
#include <string>

using namespace std;

class MyDListIndexOutOfRange : public out_of_range 
{
	public: 
		MyDListIndexOutOfRange(const string & message = ""):
			out_of_range(message.c_str())
		{ }
};
#endif
