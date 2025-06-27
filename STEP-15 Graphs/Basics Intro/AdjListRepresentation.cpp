#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge to the graph (for undirected graph)
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);  // Add v to u's list
    adj[v].push_back(u);  // Add u to v's list (because it's undirected)
}

// Function to print the adjacency list of the graph
void printGraph(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices (nodes)

    // Creating an adjacency list with V empty lists
    vector<vector<int>> adj(V);

    // Adding edges
    addEdge(adj, 0, 1);  // Edge between node 0 and 1
    addEdge(adj, 0, 4);  // Edge between node 0 and 4
    addEdge(adj, 1, 2);  // Edge between node 1 and 2
    addEdge(adj, 1, 3);  // Edge between node 1 and 3
    addEdge(adj, 1, 4);  // Edge between node 1 and 4
    addEdge(adj, 2, 3);  // Edge between node 2 and 3
    addEdge(adj, 3, 4);  // Edge between node 3 and 4

    // Print the adjacency list
    printGraph(adj);

    return 0;
}
