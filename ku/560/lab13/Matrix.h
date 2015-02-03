#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <limits.h>
using namespace std;

// Just define INF as maximum integer size
const int INF = INT_MAX;

class Matrix {

private:
	
	int n;
	int* array;
	int array_size;
	
	int index(int i, int j);
	
public:
	
	Matrix(int n_val);
	int get(int i, int j);
	void set(int i, int j, int value);
	void print();
	~Matrix();
	
};

#endif /* MATRIX_H_ */
