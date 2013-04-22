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
	int piv_idx = -1;

	// Find the index of pivot
	for(int x = i; x <= j; x++) {
		if(v[x] == pivot) {
			piv_idx = x;
			break;
		}		
	}

	if(piv_idx == -1) {
		cout << "Error in partition\n";
		return -1;
	}

	swap(piv_idx, j, v);

	for( ; i < j; i++) {
		if(v[i] < pivot) {
			swap(store_i++, i, v);
		}	
	}

	if(v[j] < v[store_i]) {
		swap(j, store_i, v);
	}

	return store_i;
}

double select(int i, int j, int k, vector<double> &A) {
	int n = j - i;

	//cout << "i: " << i << " j: " << j << " k: " << k << endl;

	if(n < CUTOFF) {
		sort(A.begin() + i, A.begin() + j + 1);
		return A[i + k];
	}

	vector<double> medians;
	int num_parts = n/r;

	for(int i_m = i; i_m <= j; i_m += r ) {
		
		int j_m = i_m + r > j ?
			j :
			i_m + r - 1;
		
		int k_m = (j_m - i_m) / 2;

		cout << "i_m: " << i_m << " j_m: " << j_m << " k_m: " <<k_m << endl;
		medians.push_back(select(i_m, j_m, k_m, A));
	}

	cout << "Medians: "; printVec(0, medians.size() - 1, medians);
	int pivot = select(0, medians.size() - 1, medians.size() / 2, medians); 
	int p = partition(i, j, pivot, A);

	cout << "After partitioning. pivot, p: " << pivot << " " << p << endl;
	cout << "A: ";
	printVec(i, j, A);

	if(k <= p) {
		cout << "Calling on lower half.\n";
		return select(i, p, k, A); 	
	} 
	else if (k > p) {
		cout << "Calling on upper half.\n";
		return select(p + 1, j, k - p + i - 1, A);			
	} else {
		cout << "HEY! THEY'RE EQUAL!\n";
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

		if(k == -1) {
			break;
		}
			
#else
	//randomly get k value
	//randomly build test data
#endif

	if(k > v.size()) {
		cout << "The value of k you entered is larger than the array of numbers."
			 << "\nTry again. ";
		continue;
	}

	//partition(0, v.size() - 1, k, v);
	//printVec(0, v.size() - 1, v);

	int kth_smallest = select(0, v.size() - 1, k - 1, v);

	cout << "The " << k << "th number is "
		 << kth_smallest << endl;

#if test
	} //end while
#endif

	return 0;
}
	 


















































