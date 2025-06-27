// ..shortest path in directed acyclic graph
#include <bits/stdc++.h>
using namespace std;

// Function to perform Topological Sort using DFS
void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        int v = it.first;
        if (!vis[v]) {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node); // push after all children are processed
}

// Function to find shortest path in DAG
void shortestPath(int N, int src, vector<pair<int, int>> adj[]) {
    vector<int> vis(N, 0);
    stack<int> st;

    // Step 1: Topological Sort of all nodes
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            topoSort(i, adj, vis, st);
        }
    }

    // Step 2: Distance initialization
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    // Step 3: Process nodes in topological order
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (dist[u] != INT_MAX) {
            for (auto it : adj[u]) {
                int v = it.first;
                int wt = it.second;
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    // Print distances
    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int N = 6; // number of nodes
    vector<pair<int, int>> adj[N];

    // Example DAG edges (u -> v with weight w)
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int src = 0;
    shortestPath(N, src, adj);

    return 0;
}
