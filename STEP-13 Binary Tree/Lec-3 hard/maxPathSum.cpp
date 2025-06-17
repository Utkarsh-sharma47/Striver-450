#include <iostream>
#include <climits> // For INT_MIN
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
    // Helper function to calculate the maximum path sum
    int util(TreeNode* root, int &maxi) {
        // Base case: if the current node is null, return 0
        if (root == NULL) return 0;

        // Recursively calculate the maximum path sum for the left and right children
        // We only consider positive contributions (max(0, ...)) to avoid negative sums
        int left = max(0, util(root->left, maxi));
        int right = max(0, util(root->right, maxi));

        // Update the maximum path sum found so far
        // The path can include the current node and both children
        maxi = max(maxi, left + right + root->val);

        // Return the maximum path sum including the current node and one of its children
        return max(left, right) + root->val;
    }

    // Main function to find the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        // Initialize the maximum path sum to the smallest integer value
        int maxi = INT_MIN;
        // Call the helper function
        util(root, maxi);
        // Return the maximum path sum found
        return maxi;
    }
};

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // Create a Solution object
    Solution solution;
    // Calculate the maximum path sum
    int result = solution.maxPathSum(root);
    // Output the result
    cout << "Maximum Path Sum: " << result << endl;

    // Clean up memory (not shown for brevity)
    return 0;
}
