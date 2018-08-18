#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <priority_queue>
#include <string>
#include <stack>
#include <stdlib.h>

using namespace std;

template<typename T>
struct ListNode {
    T val;
    ListNode* next;

    ListNode(T v) : val(v) {}
};

template<typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;

    ListNode(T v) 
    : val(v) 
    , left(nullptr)
    , right(nullptr)
    {}

    ListNode(T v, TreeNode<T>* l, TreeNode<T>* r) 
    : val(v) 
    , left(l)
    , right(r)
    {}
};

// Save all leaf nodes of a Binary tree in a Doubly Linked List by using Right node as Next node and Left Node as Previous Node.
template<typename T>
TreeNode<T> treeToList(TreeNode<T> const * const root) {
    TreeNode<T> const* head = treeToList(root, nullptr);
    while(head->left) { // Find head of list
        head = head->left;
    }
    return head;
}

template<typename T>
TreeNode<T> rec(TreeNode<T>* root) {
    if(!root) {
        return nullptr;
    } 
    if(!root->left && !root->right) {
        return root;
    }

    TreeNode<T>* lChild = rec(root->left);
    // Alternatively we could pass a constant indicating whehther the child is left or right of parent
    while(lChild && lChild->right) 
        lChild = lChild->right;

    TreeNode<T>* rChild = rec(root->right);

    if(lChild && rChild) {
        lChild->right = rChild;
        rChild->left = lChild;
        return lChild;
    }

    return lChild ? lChild : rChild;
}

// Given an array,find the maximum j – i such that arr[j] > arr[i]
int maxIndexDiff(vector<int> const& arr) {
    int maxDiff = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] > arr[i]) {
                maxDiff = max(maxDiff, j - i);
            } 
        }
    }    
    return maxDiff;
} // TODO: linear solution to this problem

// Remove Alternate Duplicate characters from a char array you have to do it in Place.Like keeping only the odd occurences of each character.
// Example: Input: “you got beautiful eyes”
// Output: ”you gtbeaiful es”
// Allowed Time Complexity was O(n) and Space Complexity was O(1)

int charCount(char c, unorderd_map<char, int>& counts) {
    if(counts.find(c != counts.end()) {
        counts[c] = 1;
    } else {
        counts[c] += 1;
    }
    return counts[c];
}

void keepOddOccurances(string& s) {
    unordered_map<char, int> counts;    
    int rollback = 0;
    for(int i = 0; i < s.size(); i++) {
        if((charCount(s[i], counts) % 2) != 0) {
            rollback++; 
        } else {
            s[i - rollback] = s[i];
        }
    }

    for(int i = s.size() - 1; i > s.size() - rollback; i++) {
        s[i] = '\0';
    }
}

// In a file there are 1 million words . Find 10 most frequent words in that file.
// Assume we have a trie with insert(string) and count(string)
class Trie {
public:
    int insert(const string s); // returns current count of that word
    int count(const string& s) const; // -1 if doesn't exist
};

vector<string> mostCommonWords(const int nMostCommon, vector<string> const& words) {
    Trie trie;
    using P = pair<int, string>;
    priority_queue<P, vetor<P>, less<P>> pq;

    for(string word : words) { 
        int wordCount = trie.insert(word);
        // TODO: if word exists in pq, pull it out, increment it, and push it back
        /*else*/if(pq.size() < nMostCommon) { // TODO: check if word exists in 
            pq.push({wordCount, word});
        } else if(wordCount > pq.top()) {
            pq.pop();
            pq.push({wordCount, word})
        }
    } 

    vector<string> output;
    while(!pq.empty()) {
        output.push_back(pq.top());
        pq.pop(); 
    }

    return output;
}

// TODO
// Find all nodes at k-distance from a given node in a binary tree
int kNeareastNodes(TreeNode<T>* root, T const& target, const int k, unordered_set<T>& kNearest, bool& findMode) {
    // What if k is greater than the number of nodes in the tree? or greater than any path?
    if(!root) {
        return -1;
    }
    if(k == 0 && !findMode) {
        kNearest.insert(root);
        return -1;
    }
    if(k > 0 && !findMode) { // Need way to mark nodes as processed
        kNearestNodes(root->left, target, k - 1, kNearest, findMode); 
        kNearestNodes(root->right, target, k - 1, kNearest, findMode); 
        return -1;
    }
    if(root->val == target && findMode) {
        findMode = false;
        kNearestNodes(root->left, target, k - 1, kNearest, findMode); 
        kNearestNodes(root->right, target, k - 1, kNearest, findMode); 
        return k - 1;
    }

    int distL = kNearestNodes(root->left, target, k, kNearest, findMode);
    int distR = kNearestNodes(root->right, target, k, kNearest, findMode);

    if(distL == 0 || distR == 0) {
        kNearest.insert(root);
        return -1; 
    }

    return distL > 0 ? distL : distR;
}

// Clone a linked list with next and random pointer
// Serialise and Deserialise a linked list with next and random pointer.
// TODO: There's no way to do this with a singly linked list

// Construct a binary tree from given inorder and preorder traversals.
TreeNode<T>* constructTree(int const& preIdx, vector<T> const& preOrder, vector<T> const& inOrder) {
    // Make sure both vectors are the same size
    // Make sure they are not empty
    if(preIdx >= preOrder.size() || inOrder.empty()) {
        return nullptr;
    }

    T val = preOrder[preIdx];
    TreeNode<T>* root = new TreeNode(val);

    auto split = inOrder.find(val);
    root->left = constructTree(++preIdx, preOrder, vector<T>(inOrder.begin(), split);
    root->right = constructTree(++preIdx, preOrder, vector<T>(split + 1, inOrder.end());

    return root;
    // How does it scale? Can't be faster than linear time since we are processing n input. However, we can lower the constant by 
    //  passing around inOrder indeces instead of creating new vectors
    // What if lists aren't big enough to fit into memory? Depends on how the tree is balanced. If it's perfectly balanced,
    //  processing with power-of-2 # of threads would be effective. Otherwise, maybe we just have a vector that reads from disk?
    // Can anything be pre-computed? Somehting that tells us where each pre-order index is on disk
}

// Return a tree such that each internal node stores sum of all its child nodes. Each leaf node stores zero.
// TODO

// How will you implement linked list with 1 million nodes? How will you access 999999 th node? Give some optimal design strategy and implementation.
// TODO

// Reversal of Linked List in groups of K.
template<typename T>
ListNode<T>* reverseK(ListNode<T>* head, const int k) {
    stack<T> s;
    ListNode<T>* newHead = nullptr;
    ListNode<T>* prevGroup = nullptr;
    ListNode<T>* nextGroup = head;

    while(nextGroup) {
        head = nextGroup;
        for(int i = 0; i < k && head, i++) {
            s.push(head);
            head = head->next;
        } 
        
        while(!s.empty()) {
            if(prevGroup) {
                prevGroup->next = s.top();
                prevGroup = prevGroup->next;
            } else { // First group. Initialize
                newHead = s.top();
                prevGroup = newHead;
            }
            s.pop()
        }

        nextGroup = head ? head->next : nullptr;
    }

    return newHead;

    // THis is actually a lot more complex than it needs to be. We can just iterate through the list and change 
    //  the direction of the pointers. 
}

// Check whether given binary tree is balanced or not. Definition was no two leaves should have height difference of greater than one.
using MaxMin = Pair<int,int>;
bool isTreeBalanced(TreeNode<T>* root) {
    if(!root) {
        return true;
    }

    MaxMin depths = balanced(root);
    return abs(depths.first - depths.second) <= 1;
}
MaxMin balanced(TreeNode<T>* root) {
    if(!root) {
        return {0, 0};
    }

    MaxMin leftDepth = balanced(root->left);
    MaxMin rightDepth = balanced(root->right);

    return { max(leftDepth.first, rightDepth.first) + 1
           , min(leftDepth.second, rightDepth.second) + 1
           }
}

// Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
int countStrings(const int n) {
    // one 1: 1 0 0 0 0, 5
    // two 1: 1 0 1 0 0, 3
    //        0 1 0 1 0, 2 
    //        0 0 1 0 1, 1 
    // 3   1: 1 0 1 0 1, 1

    // 0, 1
    // 1, 2
    // 2, 3 
    // 3, 5   0000, 1000, 0100, 0010, 0001, 1010, 1001, 0101, 
    // 4, 8
    //    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i -2];
    }
    /* Are these equivalent?
    int countStrings(int n)
    {
    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
    */
}

// Remove duplicates from string in place in O(n).
// TODO

// Convert binary tree to linked list
ListNode* bTreeToList(TreeNode const * const root) {
    ListNode* head;
    if(root) {
        head = new ListNode(root->val);
    }
    bTreeToList(root->left, curr);
    bTreeToList(root->right, curr);
}

void bTreeToList(TreeNode const * const root, ListNode*& curr) {
    if(!root) {
        return;
    }

    bTreeToList(root->left, curr);
    curr->next = new ListNode(root->val);
    curr = curr->next;
    bTreeToList(root->right, curr);
}

// Connect nodes on same level in a binary tree.
// TODO: BFS through tree. As we're pushing items onto queue, we also push the level. Then, when all elements are on the queue, we 
//  pop them off, attaching neighbrs while their level is the same. Leveled nodes will be contiguous in the queue. 

// Find sum of data of all leaves of a binary tree on same level and then multiply sums obtained of all levels.
// TODO

// Given a matrix of characters and a word.
// you have to count the number of occurrences of that word in that matrix. you can move to any of the eight valid directions from current position.
// TODO

// You are given an string as input which represents a path. You have to normalize that path inplace(NO EXTRA SPACE).
// e.g.input : "\a\b\c\..\..\file.txt" output: "\a\file.txt"
int reverseFind(const string& s, const int startIdx, const char target);

void nomralizePath(string& path) {
    int writeIdx = 0;

    for(int readIdx = 0; readIdx < path.size(); readIdx++, writeIDx++) {
        if(path.substr(readIdx, 3) == "../") {
            writeIdx = reverseFind(path, writeIdx, '/');
            readIdx += 3;
        }
        path[writeIdx] = path[readIdx];
    }
    
}

int reverseFind(const string& s, const int startIdx, const char target) {
    int targetIdx = startIdx;
    while(s[targetIdx] != target && targetIdx > 0) {
        targetIdx--;
    }
    return targetIdx;
}

/*  

Least common ancestor of two nodes in a binary tree
Given two sorted arrays (with repetitive elements) find the kth minimum number from both arrays.
Given the root to a binary tree, a value n and k.Find the sum of nodes at distance k from node with value n
Find an element in a rotated array
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days.

For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, 
the maximum profit can earned by buying on day 0, selling on day 3.
Again buy on day 4 and sell on day 6. 
If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

Given two linked lists both represent a number. Create a linked list that contains its sum.
Given a binary search tree , print the path which has the sum equal to k and has minimum hops. i.e if there are multiple paths with the sum equal to k then print the path with minimum number of nodes.
A MxN matrix containing integers (positive, negative and zero’s). For every position containing 0, mark the corresponding row and column as 0.
Rotate MxN matrix by 90 degress.
Find the nth number that contains the digit k or is divisible by k. (2 <= k <= 9)
Write a program to connect next left node in a binary tree. Also first node of each level should be pointing to last node of next level? (Without using Queue)
Convert a binary tree to its sum tree(each node is the sum of its children)
Given a directed graph. Construct another graph from given graph such that if path exists from vertices A to vertices B and from B to C, then path from A to C and from C to A also should exists.
Implement hashmap on your own. Write good hashing function for string.
Given an array, arrange the elements such that the number formed by concatenating the elements is highest.
*/