/*
You are in a city that consists of n intersections numbered from 0 to n - 1 
with bi-directional roads between some intersections. The inputs are generated 
such that you can reach any intersection from any other intersection and that 
there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where
 roads[i] = [ui, vi, timei] means that there is a road between 
 intersections ui and vi that takes timei minutes to travel. 
 You want to know in how many ways you can travel from intersection 
 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the 
shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Define modulo as answer can be large
        const int MOD = 1e9 + 7;

        // Create an adjacency list to store graph:
        // Each node has a list of pairs: (neighbor, weight)
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];
            // Since the graph is undirected, add both directions
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // dist[i] = shortest time to reach node i from node 0
        vector<long long> dist(n, LLONG_MAX);

        // ways[i] = number of ways to reach node i using shortest path
        vector<int> ways(n, 0);

        // Min-heap priority queue: stores pairs (time, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // (time = 0, node = 0)

        while (!pq.empty()) {
            auto it = pq.top();
            int currTime=it.first;
            int node=it.second;
            pq.pop();

            // Skip if we already found a better path
            if (currTime > dist[node]) continue;

            // Explore neighbors
            for (auto it : adj[node]) {
                int adjNode=it.first;
                int weight=it.second;
                long long newTime = currTime + weight;

                // Case 1: Found a shorter path to adjNode
                if (newTime < dist[adjNode]) {
                    dist[adjNode] = newTime;
                    ways[adjNode] = ways[node];  // start a new count from current path
                    pq.push({newTime, adjNode});
                }
                // Case 2: Found another shortest path to adjNode
                else if (newTime == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;  // add to count
                }
            }
        }

        // Return number of ways to reach destination node n-1
        return ways[n - 1];
    }
};

// Main function for testing
int main() {
    Solution sol;

    // Example input:
    // Graph with 7 nodes and edges: (u, v, time)
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 5, 1}
    };

    // Compute and print the number of shortest paths from node 0 to node n-1
    int result = sol.countPaths(n, roads);
    cout << "Number of shortest paths from node 0 to node " << n-1 << " is: " << result << endl;

    return 0;
}
