#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

#define BREAK -1;

int CUTOFF = 10;
const int r = 7;

void swap(int i, int j, vector<double> &v) {
	double tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void printVec(int i, int j, vector<double> &v) {
	for(; i < j + 1; i++) {
		cout << v[i] << " ";	
	}

	cout << endl;
}

int partition(int i, int j, int pivot, vector<double> &v) {

	int store_i = i;

	for( ; i + 1 < j - 1; i++) {
		if(v[i] == pivot) {
			swap(i--, j, v);
		} 
		else if(v[i] < pivot) {
			swap(store_i++, i, v);
		}	
	}

	swap(j, store_i, v);

	return store_i;
}

double select(int i, int j, int k, vector<double> &A) {
	int n = j - i;


	if(n < CUTOFF) {
		sort(A.begin() + i, A.begin() + j);
		return A[i + k];
	}

	vector<double> medians;
	int num_parts = n/r;

	for(int i_m = i; i_m < n; i_m += r ) {
		
		int j_m = i_m + r > j ?
			j :
			i_m + r - 1;
		
		int k_m = (j_m - i_m) / 2;

		medians.push_back(select(i_m, j_m, k_m, A));
		
		//cout << "i: " << i_m << " j: " << j_m << endl;
	}

	int pivot = select(0, medians.size() - 1, medians.size() / 2, medians); 
	int p = partition(i, j, pivot, A);

	cout << "After partitioning. pivot, p: " << pivot << " " << p << endl;
	cout << "A: ";
	printVec(i, j, A);

	if(k < p) {
		return select(i, p - 1, k, A); 	
	} 
	else if (k > p) {
		return select(p + 1, j, k - p + i - 1, A);			
	} else {
		return p;	
	}
}

int main() {
	int k = 10000;
	vector<double> v;

#if test
	ifstream fin("select.txt");

	if(fin.fail()) {
		cout << "Fin failed to open select.txt\n";	
	}
		
	int num;
	while(fin >> num) {
		v.push_back(num);	
	}

	while(true) {
		cout << "Enter a value for k (-1 to exit): ";
		cin  >> k;
		cout << "\n";
			
#else
	//randomly get k value
	//randomly build test data
#endif

	printVec(0, v.size() - 1, v);

	int kth_smallest = select(0, v.size() - 1, k, v);

	cout << "The " << k << "'th number is "
		 << kth_smallest << endl;

#if test
	} //end while
#endif

	return 0;
}
	 


















































