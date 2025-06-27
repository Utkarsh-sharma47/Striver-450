#include <iostream>
#include <vector>
using namespace std;

// DFS function to visit all reachable nodes from 'node'
void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    cout << node << " ";           // Visit the current node (can also store it)
    visited[node] = true;          // Mark the current node as visited

    // Visit all unvisited neighbors
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);  // Recursive DFS call
        }
    }
}

int main() {
    int V = 6;  // Number of vertices

    // Create an adjacency list for the graph
    vector<int> adj[V];

    // Add undirected edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[5].push_back(4);

    // Create a visited array initialized to false
    vector<bool> visited(V, false);

    cout << "DFS traversal starting from node 0: ";
    dfs(0, adj, visited);  // Start DFS from node 0

    return 0;
}
