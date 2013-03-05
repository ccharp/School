#include <stdio.h>

int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}

float addf(float x, float y) {
	return x + y;
}

float subf(float x, float y) {
	return x - y;
}

int eq(int x, int y) { 
	return x == y;
}

int ne(int x, int y) {
	return x != y;
}

int lt(int x, int y) {
	return x < y;
}

int gt(int x, int y) {
	return x > y;
}

int lte(int x, int y) {
	return x <= y;
}

int gte(int x, int y) {
	return x >= y;
}

int logand(int x, int y) {
	return x && y;
}

int logor(int x, int y) {
	return x || y;
}

int shiftleft(int x, int y) {
	return x << y;
}

int shiftright(int x, int y) {
	return x >> y;
}

int bitand(int x, int y) {
	return x & y;
}

int bitor(int x, int y) {
	return x | y;
}

int feq(float x, float y) { 
	return x == y;
}

int ltf(float x, float y) {
	return x < y;
}

int assign(float x, float y) {
	x = y;
	return x;
}

int usub(int y) {
	y--;
	return y;
}

int div(int x, int y) {
	return x / y;
}

int mult(int x, int y) {
	return x * y;
}

int main() {

	add(5, 12);
	
	printf("string %i", 42);

	return 0;
}


