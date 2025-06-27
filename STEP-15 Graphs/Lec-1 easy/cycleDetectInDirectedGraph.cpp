#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to perform DFS and detect cycle
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsVis) {
        vis[node] = 1;       // mark the node as visited
        dfsVis[node] = 1;    // mark the node in the current DFS path

        // visit all the neighbors
        for (int neighbor : adj[node]) {
            // if the neighbor is not visited, call dfs on it
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, dfsVis))
                    return true; // if cycle is found in DFS
            }
            // if neighbor is visited and is also in the current DFS path
            else if (dfsVis[neighbor]) {
                return true; // cycle found (back edge)
            }
        }

        dfsVis[node] = 0; // backtrack: remove node from current DFS path
        return false;     // no cycle found from this node
    }

    // Main function to check if cycle exists in directed graph
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);     // visited array
        vector<int> dfsVis(V, 0);  // recursion stack array

        // check all components of the graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, dfsVis))
                    return true; // if any component has a cycle
            }
        }

        return false; // no cycle in any component
    }
};


int main() {
    int V = 4; // number of vertices
    vector<int> adj[V];

    // Example: Directed graph with a cycle
    // 0 → 1 → 2 → 3 → 1 (back to 1 creates a cycle)
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    if (obj.isCyclic(V, adj))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle." << endl;

    return 0;
}

