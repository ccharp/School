#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std; // for convenience for this assignment

vector<int> parseNums(const string& listStr) {
    vector<int> output;
    stringstream ss(listStr);
    string tok;
    while(getline(ss, tok, ',')) {
        try {
            output.push_back(stoi(tok));
        } catch(const exception& e) {
            // maybe have some logging here...
            return {};
        }
    }
    return output;
}

// ASSUMPTION: nums is never empty.
// ASSUMPTION: there can be multiple solutions. We will output the first encountered.
int findNearest(const int target, const vector<int>& nums) {
    int nearestVal;
    int nearestDist = INT_MAX;
    for(const int num : nums) {
        // ASSUMPTION: target and num are not so large or small that 
        //     currDist < INT_MIN or currDist > INT_MAX.
        int currDist = abs(num - target);
        if(currDist < nearestDist) {
            nearestDist = currDist;
            nearestVal = num;
        }
    }
    return nearestVal;
}

int main() {
    cout << "Enter a list of comma separated integers on a single line:\n";

    string numsStr;
    vector<int> nums;
    getline(cin, numsStr);
    nums = parseNums(numsStr);
    if(nums.empty()) {
        cout << "Invalid input! Could not parse list. Exiting...\n"; 
        return 1;
    }

    // ASSUMPTION: target is an int parsable integer
    int target;
    cout << "Enter a number, and I will return the closest value from the list above...\n";
    cin >> target;

    int nearest = findNearest(target, nums);
    cout << "The nearest value is: " << nearest << ".\n";

    return 0;
}