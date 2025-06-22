#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        // Step 1: Find the node to be deleted
        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Search in left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Search in right subtree
        } else {
            // Node found

            // Case 1: Node has no left child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: Node has no right child
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has both children
            // Find inorder successor (leftmost in right subtree)
            TreeNode* leftmost = root->right;
            while (leftmost->left) {
                leftmost = leftmost->left;
            }

            // Replace root's value with successor's value
            root->val = leftmost->val;

            // Delete the inorder successor node from right subtree
            root->right = deleteNode(root->right, leftmost->val);
        }

        return root;
    }
};

// Helper function to print tree in inorder
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

// Sample usage
int main() {
    Solution sol;

    // Build this BST:
    //        5
    //       / \
    //      3   6
    //     / \   \
    //    2   4   7

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    root->right = new TreeNode(6, nullptr, new TreeNode(7));

    cout << "Original BST (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    int key = 3;
    root = sol.deleteNode(root, key);

    cout << "After deleting " << key << " (Inorder): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
