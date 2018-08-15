#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <priority_queue>
#include <string>

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

    ListNode(T v) : val(v) {}
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

/*
Find all nodes at k-distance from a given node in a binary tree
Clone a linked list with next and random pointer
Serialise and Deserialise a linked list with next and random pointer.
Construct a binary tree from given inorder and preorder traversals.
Return a tree such that each internal node stores sum of all its child nodes. Each leaf node stores zero.
How will you implement linked list with 1 million nodes? How will you access 999999 th node? Give some optimal design strategy and implementation.
Reversal of Linked List in groups of K.
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
Check whether given binary tree is balanced or not. Definition was no two leaves should have height difference of greater than one.
Remove duplicates from string in place in O(n).
Convert binary tree to linked list
Connect nodes on same level in a binary tree.
Find sum of data of all leaves of a binary tree on same level and then multiply sums obtained of all levels.
Given a matrix of characters and a word.
you have to count the number of occurrences of that word in that matrix. you can move to any of the eight valid directions from current position.
You are given an string as input which represents a path. You have to normalize that path inplace(NO EXTRA SPACE).

e.g.input : "\a\b\c\..\..\file.txt" output: "\a\file.txt"

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