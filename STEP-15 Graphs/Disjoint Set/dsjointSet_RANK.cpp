
#include <iostream>
#include <vector>
using namespace std;

// Class for Disjoint Set (Union-Find)
class DisjointSet {
private:
    vector<int> parent; // Stores ultimate parent of each node
    vector<int> rank;   // Stores rank (approximate depth) of trees

public:
    // Constructor: initialize parent and rank vectors
    DisjointSet(int n) {
        parent.resize(n + 1); // +1 to make it 1-based indexing
        rank.resize(n + 1, 0); // Initially all ranks are 0

        // Each node is its own parent at the beginning
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Function to find the ultimate parent of a node (with path compression)
    int findUltiParent(int node) {
        // If the node is not its own parent, recurse and compress path
        if (parent[node] != node) {
            parent[node] = findUltiParent(parent[node]); // Path compression
        }
        return parent[node]; // Return the ultimate parent
    }

    // Function to perform union of two nodes by rank
    void unionByRank(int u, int v) {
        // Find ultimate parents of both nodes
        int pu = findUltiParent(u);
        int pv = findUltiParent(v);

        // If they have the same parent, they are already connected
        if (pu == pv) return;

        // Union by rank logic:
        // Attach the smaller rank tree under the larger one
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            // If ranks are same, make one root and increase its rank
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Optional: utility to print parent array (for debugging)
    void printParents() {
        for (int i = 1; i < parent.size(); i++) {
            cout << "Node " << i << " -> Parent: " << parent[i] << endl;
        }
    }
};

// Main function to demonstrate DSU usage
int main() {
    int n = 7; // Let's say we have 7 nodes (1 to 7)
    DisjointSet ds(n);

    // Perform unions
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Try connecting 3 and 7
    if (ds.findUltiParent(3) == ds.findUltiParent(7)) {
        cout << "3 and 7 are in the same component.\n";
    } else {
        cout << "3 and 7 are in different components. Connecting them...\n";
        ds.unionByRank(3, 7);
    }

    // Check again
    if (ds.findUltiParent(3) == ds.findUltiParent(7)) {
        cout << "Now 3 and 7 are in the same component.\n";
    }

    // Optional: Print final parent array
    cout << "\nFinal parent structure:\n";
    ds.printParents();

    return 0;
}
