#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class PriorityQueue {
public:
    PriorityQueue() {
        
    }
    void push(T val) {
        mData.push_back(val);
        trickleUp();
    }

    T pop() { // for now, assume it is not empty. Throw exception otherwise
        T top = mData[0];
        trickleDown(); 
    }

private:
    vector<T> mData;
    
    // Return index of Left or Right child
    int getChildL(const int parent) const;
    int getChildR(const int parent) const;
    int getParent(const int child) const; 

    void trickleUp () {
        int currIdx = mData.size() - 1;
        int parentIdx = getParent(mData.Size());
        while(parentIdx != -1 && mData[currIdx] > mData[parentIdx]) {
            swap(mData[currIdx], mData[parentIdx]);
            currIdx = parentIdx;
            parentIdx = getParent(parentIdx); 
        }
    }

    void trickleDown() {
        mData[0] = mData.back();
        mData.pop();

        int currIdx = 0; 
        int childIdxL = getChildL(currIdx);
        int childIdxR = getChildR(currIdx);
        int dataSize = mData.size();

        do {
            int maxChild = max(mData[childIdxL], mData[childIdxR]);
            // TODO:
        } while(childIdxL < dataSize && childIdxR < dataSize && );
    }
};

int PriorityQueue::getChildL(const int parent) {
    int childIdx = 2*parent + 1;
    return childIdx < mData.size() ? childIDx ? -1;
}

int PriorityQueue::getChildR(const int parent) {
    int childIdx = 2*parent + 2; 
    return childIdx < mData.size() ? childIDx ? -1;
}

int PriorityQueue::getParent(const int child) {

    return child != 0 ? (parent - 1)/2 : -1;
}

int main() {
    // generate random data
    

    return 0;
}