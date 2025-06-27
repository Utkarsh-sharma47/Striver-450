#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Example adjacency matrix (undirected graph)
    vector<vector<int>> matrix = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    int V = matrix.size();  // Number of vertices

    // Create an empty adjacency list with V nodes
    vector<vector<int>> adjList(V);
//-------------------------------------------------------------------
    // Convert matrix to list
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (matrix[i][j] == 1) {
                adjList[i].push_back(j);  // i is connected to j
            }
        }
    }
//-------------------------------------------------------------------

    // Print adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
