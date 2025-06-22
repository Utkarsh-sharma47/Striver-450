#include <iostream>
#include <climits> // For LONG_MIN and LONG_MAX
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to check if the tree is a valid BST
    bool check(TreeNode* root, long maxi, long mini) {
        if (!root) return true;

        // If current node violates the min/max constraint, it's not a BST
        if (root->val >= maxi || root->val <= mini) return false;

        // Recursively check left and right subtrees with updated bounds
        bool leftIsValid = check(root->left, root->val, mini);
        bool rightIsValid = check(root->right, maxi, root->val);

        return leftIsValid && rightIsValid;
    }

    // Public function to start the validation
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MAX, LONG_MIN);
    }
};

// Sample usage
int main() {
    // Construct the tree:
    //       5
    //      / \
    //     3   7
    //    / \   \
    //   2   4   8

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution sol;
    if (sol.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    // Free memory (important in real-world programs)
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
