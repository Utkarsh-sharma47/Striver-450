#include <iostream>
#include <vector>
#include <queue> // For using queue
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val; // Value of the node
    TreeNode *left; // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to perform zigzag level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; // To store the final result
        if (!root) return ans; // If the tree is empty, return an empty result

        queue<TreeNode*> q; // Queue to facilitate level order traversal
        q.push(root); // Start with the root node
        bool leftToRight = true; // Flag to determine the direction of traversal

        // While there are nodes to process
        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            vector<int> row(size); // Vector to store values of the current level

            // Process each node at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); // Get the front node
                q.pop(); // Remove the front node from the queue

                // Place node value in correct index based on direction
                int index = leftToRight ? i : size - 1 - i; // Determine index based on direction
                row[index] = node->val; // Assign the node's value to the correct index

                // Add child nodes to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(row); // Add the current level's values to the result
            leftToRight = !leftToRight; // Flip the direction for the next level
        }

        return ans; // Return the final zigzag level order traversal
    }
};

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Create a Solution object
    Solution solution;
    // Perform zigzag level order traversal
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    // Output the result
    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory (not shown for brevity)
    return 0;
}
