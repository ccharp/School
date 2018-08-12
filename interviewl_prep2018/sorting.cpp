#include <iostream>
#include <vector>
#include <random> 
#include <time.h>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int low, int high);

void printVector(vector<int> const& v) {
    for(int i : v) {
        cout << i << " "; 
    }
    cout << endl;
}

void quickSort(vector<int>& nums, int low, int high) {
    if(low >= high) {
        cout << "Ended\n";
        return;
    }
    cout << low << ", " << high << endl;
    int mid = partition(nums, low, high);
    printVector(nums);
    quickSort(nums, low, mid - 1);
    quickSort(nums, mid + 1, high);
}

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];

    for(int i = low; i < high; i++) {
        if(nums[i] < pivot) {
            swap(nums[i], nums[low]);
            low++;
        }
    }

    swap(nums[high], nums[low]);
    return low;
}


int main() {
    srand(time(NULL));

    int n;
    cin >> n;
    vector<int> toSort;
    for(int i = 0; i < n; i++) {
        toSort.push_back(rand() % 100);
    }

    printVector(toSort);
    quickSort(toSort, 0, n - 1); 
    printVector(toSort);

    cout.flush();

    return 0;
}