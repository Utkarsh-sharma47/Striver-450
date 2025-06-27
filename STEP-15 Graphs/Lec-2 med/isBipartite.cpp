/*
Bipartite - graph in which nodes can be colored by 2 colors such that
            NO 2 Adjacent nodes are of same color
*/
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS function to color the graph and check for conflicts
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colorArr) {
        colorArr[node] = color; // Color the current node with the given color (0 or 1)

        // Loop through all neighbors of the current node
        for (int neighbor : graph[node]) {
            if (colorArr[neighbor] == -1) {
                // If the neighbor hasn't been colored, color it with the opposite color
                if (!dfs(neighbor, 1 - color, graph, colorArr))
                    return false; // If conflict occurs deeper in recursion, graph is not bipartite
            }
            else if (colorArr[neighbor] == color) {
                // If the neighbor is already colored with the same color, return false
                return false; // This means two adjacent nodes have same color → not bipartite
            }
        }
        return true; // All neighbors processed without conflict → valid bipartite part
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of nodes in the graph
        vector<int> colorArr(n, -1); // Color array: -1 means unvisited, 0 and 1 are the two colors

        // The graph might be disconnected, so we run DFS on every component
        for (int i = 0; i < n; i++) {
            if (colorArr[i] == -1) { // If node i hasn't been visited
                if (!dfs(i, 0, graph, colorArr)) {
                    return false; // If any component is not bipartite, return false
                }
            }
        }
        return true; // All components are bipartite → return true
    }
};

int main() {
    Solution sol;

    // Example bipartite graph
    vector<vector<int>> graph = {
        {1, 3},  // Node 0 connects to 1 and 3
        {0, 2},  // Node 1 connects to 0 and 2
        {1, 3},  // Node 2 connects to 1 and 3
        {0, 2}   // Node 3 connects to 0 and 2
    };

    bool result = sol.isBipartite(graph); // Run the bipartite check

    cout << (result ? "Bipartite" : "Not Bipartite") << endl; // Print result
    return 0;
}
