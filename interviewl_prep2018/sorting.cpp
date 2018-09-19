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
        return;
    }
    int mid = partition(nums, low, high);
    quickSort(nums, low, mid - 1);
    quickSort(nums, mid + 1, high);
}

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];

    for(int i = low ; i < high; i++) {
        if(nums[i] < pivot) {
            swap(nums[i], nums[low]);
            low++;
        }
    }

    swap(nums[high], nums[low]);
    return low;
}

// When is bucket sort more effective than a comparative sort?
// - When this conditions are met:
//      a) The data has to be evenly distributed. If it isn't bucketsort will collapse into n^2
//      b) Data distributed across finite range 
// This implementation assums values [0, 1000)
// An alternative to this is to copy the buckets back to nums before sorting, and then sort on the ranges
void bucketSort(vector<int>& nums) {
    vector<vector<int>> buckets(10); 
    for(auto num : nums) {
        buckets[num/100].push_back(num);
    }
    nums.clear();
    for(auto& b : buckets) {
        quickSort(b, 0, b.size() - 1);
        nums.insert(nums.end(), b.begin(), b.end());
    }
}

vector<int> genRandoms(int n) {
    vector<int> toSort;
    for(int i = 0; i < n; i++) {
        toSort.push_back(rand() % 1000);
    }
    return toSort;
}

int main() {
    srand(time(NULL));

    int n;
    cin >> n;

    cout << "Quick Sort: \n";
    auto toSort = genRandoms(n);
    printVector(toSort);
    quickSort(toSort, 0, n - 1); 
    printVector(toSort);

    cout << "\n\nBucket Sort: \n";
    toSort = genRandoms(n);
    printVector(toSort);
    bucketSort(toSort);
    printVector(toSort);

    cout.flush();
    return 0;
}