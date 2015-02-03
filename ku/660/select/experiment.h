#ifndef TIMETEST_H_
#define TIMETEST_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <time.h>

#include "Timer.h"

using namespace std;

//Timer timer = Timer();

// Generates vector of unique items of size n
void generateRandomDataRange(int n, vector<int> &v) {
	unordered_map<int, bool> m;

	v.clear();
	while(v.size() <= n) {
		int r = (int)rand();
		
		// Make sure r is not a duplicate 
		if(m.find(r) == m.end()) {
			m[r] = true;
			v.push_back(r);
		}
	}
}

#endif /* TIMETEST_H_ */
