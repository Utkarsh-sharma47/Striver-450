#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to recursively build the BST from preorder traversal
    TreeNode* build(vector<int>& pre, int &i, int bound) {
        // Base condition: return null if index out of bounds or value > bound
        if (i == pre.size() || pre[i] > bound) {
            return NULL;
        }

        // Create node with current value
        TreeNode* node = new TreeNode(pre[i]);
        i++; // Move to next element in preorder

        // Left subtree with updated bound (current node value)
        node->left = build(pre, i, node->val);

        // Right subtree with original bound
        node->right = build(pre, i, bound);

        return node;
    }

    // Entry point: builds BST from preorder vector
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX); // INT_MAX as upper bound initially
    }
};

// Utility function to print inorder traversal of the tree (for verification)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);         // Visit left subtree
    cout << root->val << " ";         // Visit current node
    printInorder(root->right);        // Visit right subtree
}

int main() {
    Solution sol;

    // Example preorder input
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Build BST from preorder
    TreeNode* root = sol.bstFromPreorder(preorder);

    // Print inorder traversal (should be sorted for a BST)
    cout << "Inorder Traversal of BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
