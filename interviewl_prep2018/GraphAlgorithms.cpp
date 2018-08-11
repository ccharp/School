// Outline of Kosaraju's Algorithm for finding strongly connected components 
#include <iostream>
#include <vector>
#include <unordered_set>
#include <priority_queue>
#include <limits>

using namespace std;

using Neighbors = unordered_map<int, int> weights;
struct Vertex {
    int label;
    Neighbors neighbors; 
};
using Graph = vector<Vertex>;

void kosarajuDfs(Vertex const& root, Graph const& g, stack<int>& s, unordered_set<int>& visited) {
    if(visited.find(root.label) != visited.end()) {
        return;
    }

    visited.insert(root.label);
    for(int neighbor : root.neighbors) {
        sccDfs(g[neighbor], g, visited); 
    }

}

void kosaraju(Graph g) {

    unordered_set<int> visited;
    stack<int> ordering;
    for(Vertex v : g) {
        // check if v is in one of our reachables. If it is, do nothing
        sccDfs(v, g, visited); 
    }

    // Invert graph
    // DFS in order of stack on inverted graph
    //  Each DFS iteration is strongly connected component

}


using P = pair<int, int>; // first value is label, second is weight
void dijkstra(Graph const& g, const int source, const int target) {
    auto comp = [](P p1, P p2){ return p1.second < p2.second; };
    priority_queue<P, vector<P>, decltype(comp)> pq(comp);
    unordered_set<int> explored;
    vector<int> parents(g.size(), INT_MIN);
    vector<int> dist(g.size(), INT_MAX);

    pq.insert(source, 0);
    parent[currVert] = 0;
    dist[currVert] = 0;

    int currVert;
    // We can stop as soon as we find target since the paths to each node in the path
    //  must also be minimized.
    while(currVert != target || !pq.empty()) {
        currVert = pq.top(); pq.pop();

        for(auto neighbor : g[currVert].neighbors) {
            int neighborDist = dist[currVert] + neighbor.second;
            if(neighborDist < dist[neighbor]) {
                dist[neighbor.first] = neighborDist;
                parents[neighbor.first] = currVert;
            }

            if(explored.find(neighbor) == explored.end()) {
                explored.insert(neighbor.first);
                pq.push(neighbor, dist[neighbor.first]);
            }
        }
    }

    // Print results
    if(currVert == target) {
        cout << "No path from " << source << " to " << target << ".\n";
    }
    int currVert = target;
    while(currVert != source) {
        cout << currVert << " <- ";
        currVert = parents[currVert];
    }
    cout << endl;
}

void floyd() {

}

bool edgeExists(const int u, const int v, Graph const& g) {

}

void bellmanFord(Graph const& g) {

}

Graph prim(Graph const& g) {

    // Initialize set of unvisited vertices
    unordered_set<int> vertsToAdd;
    // choose a vertex
    // Add edges to priority queue
    // select top element in priority queue, add it to the solution
    priority_queue<int> q;
    // initialize q somehow
    Graph minTree;
    while(!vertsToAdd.empty() && !q.empty()) {

    }

    return minTree;
}