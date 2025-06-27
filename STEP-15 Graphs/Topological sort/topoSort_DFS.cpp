#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Recursive DFS function for topological sorting
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true; // Mark the current node as visited

        // Visit all the unvisited neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st); // Recur for the neighbor
            }
        }

        // After visiting all neighbors, push current node to stack
        st.push(node); // This ensures post-order DFS behavior
    }

    // Main function to perform topological sort
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false); // Track visited nodes
        stack<int> st; // Stack to store topological order

        // Call DFS for all unvisited nodes (handles disconnected components)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st); // Start DFS from node i
            }
        }

        vector<int> topoOrder; // Vector to store the final topological order

        // Pop nodes from the stack to get correct order
        while (!st.empty()) {
            topoOrder.push_back(st.top()); // Add node to result
            st.pop(); // Remove from stack
        }

        return topoOrder; // Return the topological sorting
    }
};

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V); // Adjacency list

    // Example graph:
    // 5 → 2, 5 → 0
    // 4 → 0, 4 → 1
    // 2 → 3
    // 3 → 1
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution sol;
    vector<int> result = sol.topologicalSort(V, adj);

    cout << "Topological Sort Order (DFS):\n";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
