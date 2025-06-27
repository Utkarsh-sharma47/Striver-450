#include <bits/stdc++.h>
using namespace std;

// Dijkstra's algorithm function
vector<int> dijkstra(int V, vector<vector<pair<int, int>>> adj, int source) {
    // Step 1: Create a distance array and initialize with INF
    vector<int> dist(V, INT_MAX);

    // Step 2: Min-heap priority queue -> {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Step 3: Set distance to source = 0 and push into the queue
    dist[source] = 0;
    pq.push({0, source});

    // Step 4: Main loop - process until queue is empty
    while (!pq.empty()) {
        int currentDist = pq.top().first; // shortest distance so far
        int currentNode = pq.top().second;
        pq.pop();

        // Step 5: Visit all adjacent nodes
        for (auto neighbor : adj[currentNode]) {
            int neighborNode = neighbor.first;
            int edgeWeight = neighbor.second;

            // Step 6: If found a shorter path, update and push into queue
            if (currentDist + edgeWeight < dist[neighborNode]) {
                dist[neighborNode] = currentDist + edgeWeight;
                pq.push({dist[neighborNode], neighborNode});
            }
        }
    }

    // Step 7: Return the array containing shortest distances
    return dist;
}

// Driver Code
int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Sample Graph (Undirected):
    // Node 0 is connected to 1 (weight 2) and 4 (weight 1)
    // Node 1 is connected to 2 (weight 3)
    // Node 2 is connected to 3 (weight 6)
    // Node 4 is connected to 2 (weight 2) and 3 (weight 1)

    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 6});
    adj[2].push_back({4, 2});
    adj[3].push_back({2, 6});
    adj[3].push_back({4, 1});
    adj[4].push_back({0, 1});
    adj[4].push_back({2, 2});
    adj[4].push_back({3, 1});

    int source = 0;
    vector<int> shortestPaths = dijkstra(V, adj, source);

    // Print the shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " : " << shortestPaths[i] << endl;
    }

    return 0;
}
