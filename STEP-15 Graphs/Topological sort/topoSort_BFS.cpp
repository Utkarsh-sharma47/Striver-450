#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to perform topological sort
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0); // Stores the number of incoming edges for each node

        // Step 1: Calculate indegree for each node
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                indegree[v]++; // Increment indegree of neighbor
            }
        }

        queue<int> q; // Queue for BFS

        // Step 2: Push all nodes with 0 indegree into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i); // Node with no dependencies
            }
        }

        vector<int> topo; // Result vector to store topological order

        // Step 3: Process nodes in BFS manner
        while (!q.empty()) {
            int node = q.front(); // Get the front node from the queue
            q.pop();              // Remove it from the queue
            topo.push_back(node); // Add it to the result (sorted order)

            // Decrease indegree of all adjacent nodes
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;        // Remove the dependency
                if (indegree[neighbor] == 0) // If indegree becomes 0
                    q.push(neighbor);       // Add to queue
            }
        }

        // Optional: Check for cycle (if graph is not a DAG)
        if (topo.size() != V) {
            cout << "Cycle detected, no valid topological ordering.\n";
            return {}; // Return empty if not a DAG
        }

        return topo; // Return the topological order
    }
};

int main() {
    int V = 6; // Number of vertices

    // Adjacency list for a directed graph
    vector<vector<int>> adj(V);

    // Example: edges (0 → 1), (0 → 2), (1 → 3), (2 → 3), (3 → 4), (4 → 5)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);

    Solution sol;
    vector<int> result = sol.topologicalSort(V, adj);

    // Print the topological sort result
    cout << "Topological Sort Order:\n";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
