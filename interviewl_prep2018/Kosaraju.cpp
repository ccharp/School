// Outline of Kosaraju's Algorithm for finding strongly connected components 
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Vertex {
    int label;
    unordered_set<int> neighbors;
};

using Graph = vector<Vertex>;

void dfs(Vertex const& root, Graph const& g, stack<int>& s, unordered_set<int>& visited) {
    if(visited.find(root.label) != visited.end()) {
        return;
    }

    visited.insert(root.label);
    for(int neighbor : root.neighbors) {
        dfs(g[neighbor], g, visited); 
    }

}

void scc(Graph g) {

    unordered_set<int> visited;
    stack<int> ordering;
    for(Vertex v : g) {
        // check if v is in one of our reachables. If it is, do nothing
        dfs(v, g, visited); 
    }

    // Invert graph
    // DFS in order of stack on inverted graph
    //  Each DFS iteration is strongly connected component

}