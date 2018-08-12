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

truct Edge {
    int u;
    int v;
    int weight;
    Edge(int uin, int vin, weightin) : u(uin), v(vin), weight(weightin) {}
}

// For finding minimal spanning tree
Graph prim(Graph const& g) {
    auto comp = [](Edge e1, Edge e2){return e1.weight < e2.weight};
    priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);
    unordered_set<int> covered;

    auto insertEdges = [&](const int u, unordered_map<int, int> const& neighbors) {
        for(auto neighbor : neighbors) {
            if(covered.find(neighbor.first) != covered.end()) {
                continue;
            }
            pq.insert(Edge(u, neighbor.first, neighbor.second));
        }
    }

    // Outer loop ensures we cover disconnected components
    for(int root = 0; root < g.size(); root++) {
        covered.insert(root);
        insertEdges(root, g[root].neighbors);

        Graph mst(g.size());
        while(!pq.empty()) {
            Edge const& e = pq.top(); pq.pop();
            covered.insert(e.v); // We don't have to check e.u because we know it was covered already
            mst[e.u][e.v] = e.weight;

            insertEdges(e.v, g[e.v])
        }
    }

    return mst;
}