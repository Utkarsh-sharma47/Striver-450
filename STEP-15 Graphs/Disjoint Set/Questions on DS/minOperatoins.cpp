/*
you are given n edges, now 
find min number of operatoin so that whole graph can be connected

*/

/*
APP:
if there are n components so we need n-1 edge to connect them however
we need to find extra edges so IF extra edges >= n-1 then ans= n-1 : else -1
*/
#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Class
class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

// Solution Class
class Solution {
public:
    int Solve(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int cntExtras = 0;

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }

        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};

int main() {
    Solution sol;

    // Sample Input 1
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 4},
        {2, 5},
        {4, 5},
        {1, 2}  // extra edge forming cycle
    };

    int res = sol.Solve(n, edges);
    cout << "Minimum edges required to connect all components: " << res << endl;

    return 0;
}
