#include <iostream>
#include <vector>
using namespace std;

// Disjoint Set (Union-Find) with Union by Size and Path Compression
class DisjointSet {
    vector<int> parent, size;

public:
    // Constructor: initialize parent and size arrays
    DisjointSet(int n) {
        parent.resize(n + 1);  // +1 for 1-based indexing
        size.resize(n + 1, 1); // Initially, size of each set is 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;     // Initially, every node is its own parent
        }
    }

    // Find with Path Compression
    int findUPar(int node) {
        if (node == parent[node]) {
            return node; // If the node is the ultimate parent
        }
        // Path compression: set parent directly to ultimate parent
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); // Ultimate parent of u
        int ulp_v = findUPar(v); // Ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in the same set

        // Attach smaller size tree under larger one
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;     // u joins v
            size[ulp_v] += size[ulp_u]; // Update size
        } else {
            parent[ulp_v] = ulp_u;     // v joins u
            size[ulp_u] += size[ulp_v]; // Update size
        }
    }

    // Utility function to check if two nodes are in the same set
    bool isConnected(int u, int v) {
        return findUPar(u) == findUPar(v);
    }
};

// Main function to demonstrate Disjoint Set
int main() {
    int n = 7; // Let's say we have 7 nodes (1 to 7)
    DisjointSet ds(n);

    // Perform some union operations
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);

    // Check if 3 and 7 are connected
    if (ds.isConnected(3, 7)) {
        cout << "3 and 7 are in the same set\n";
    } else {
        cout << "3 and 7 are in different sets\n";
    }

    // Print ultimate parents
    for (int i = 1; i <= 7; i++) {
        cout << "Ultimate parent of " << i << " is: " << ds.findUPar(i) << "\n";
    }

    return 0;
}
