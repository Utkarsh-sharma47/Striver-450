/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
The graph is represented by a 0-indexed 2D integer array graph where graph[i] 
is an integer array of nodes adjacent to node i, meaning there is an edge from 
node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node 
if every possible path starting from that node leads to a terminal node 
(or another safe node).

Return an array containing all the safe nodes of the graph. 
The answer should be sorted in ascending order.
*/

/*
APP:- using DFS
all nodes which are
1.part of cycle
2.leads to cycle

use cycle detection in directed graph by DFS
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS function to detect cycles and mark safe/unsafe nodes
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
        vis[node] = 1;        // mark node as visited
        pathVis[node] = 1;    // mark node in the current path

        for (int neighbor : adj[node]) {
            // if neighbor is not visited, do DFS
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis, safe)) {
                    return true; // cycle found
                }
            }
            // if neighbor is already in current path => cycle
            else if (pathVis[neighbor]) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0;    // backtrack from current path
        safe[node] = 1;       // no cycle found from this node => safe
        return false;         // no cycle
    }

    // Function to return all eventual safe nodes
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);      // visited array
        vector<int> pathVis(V, 0);  // recursion stack (path) array
        vector<int> safe(V, 0);     // marks safe nodes

        // check for every node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, pathVis, safe);
            }
        }

        vector<int> result;
        // collect all safe nodes
        for (int i = 0; i < V; i++) {
            if (safe[i] == 1) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    int V = 7;
    vector<int> adj[V];

    // Example graph:
    // 0 → 1 → 2 → 3 → 4 → 5 → 6
    //         ↑         ↓
    //         └─────────┘ (Cycle involving 3-4-5)

    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {5};
    adj[5] = {3, 6};
    adj[6] = {};

    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

    cout << "Eventual Safe Nodes: ";
    for (int node : safeNodes)
        cout << node << " ";
    cout << endl;

    return 0;
}
