#include <iostream>
#include <algorithm> // For std::max
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
    int maxdia = 0; // Variable to store the maximum diameter

    // Helper function to calculate the height of the tree
    int height(TreeNode* root) {
        // Base case: if the current node is null, return height 0
        if (root == NULL)
            return 0;

        // Recursively calculate the height of the left and right subtrees
        int left = height(root->left);
        int right = height(root->right);

        // Update the maximum diameter found so far
        // The diameter at the current node is the sum of the heights of the left and right subtrees
        maxdia = max(maxdia, left + right);

        // Return the height of the current node
        return max(left, right) + 1;
    }

    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        height(root); // Call the height function to compute the diameter
        return maxdia; // Return the maximum diameter found
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

    // Create a Solution object
    Solution solution;
    // Calculate the diameter of the binary tree
    int result = solution.diameterOfBinaryTree(root);
    // Output the result
    cout << "Diameter of the binary tree: " << result << endl;

    // Clean up memory (not shown for brevity)
    return 0;
}
