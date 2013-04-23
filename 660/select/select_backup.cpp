#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

#include "experiment.h"
#include "Timer.h"

using namespace std;

#if test
int CUTOFF = 10;
#else
int CUTOFF = 100;
#endif

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

int partition(int i, int j, double pivot, vector<double> &v) {
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

		//cout << "i_m: " << i_m << " j_m: " << j_m << " k_m: " <<k_m << endl;
		medians.push_back(select(i_m, j_m, k_m, A));
	}

	double pivot = select(0, medians.size() - 1, medians.size() / 2, medians); 
	int p = partition(i, j, pivot, A);

	if(k + i < p) {
		return select(i, p - 1, k, A);	
	} else if(k + i > p) {
		return select(p + 1, j, k - p + i - 1, A);	
	}
}

void performExperiment(const int n) {
	vector<double> v;	
	int k;
	Timer timer;

	cout << "Commencing trials of size " << n << " .\n";

	// Perform each experiment 10 times
	for(int i = 0; i < 10; i++) {
		k = rand() % (n - 1);
		generateRandomDataRange(n, v);

		cout << "Trial " << i << ", k: " << k << ", time: ";
		timer.start();
		select(0, v.size() - 1, k, v);
		timer.printTime(timer.stop());
	}

	cout << endl;
}

int main() {
	int k = 10000;
	vector<double> v;

#if test
	ifstream fin("select.txt");

	if(fin.fail()) {
		cout << "Fin failed to open select.txt\n";	
	}
		
	double num;
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
		
		double kth_smallest = select(0, v.size() - 1, k - 1, v);

		cout << "The " << k << "th number is "
			 << kth_smallest << endl;
	}
			
#else
	//randomly get k value
	performExperiment(25000);
	//performExperiment(50000);
	//performExperiment(100000);
	//performExperiment(200000);
#endif

	return 0;
}
	 


















































