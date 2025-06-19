#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;                // Value of the node
    TreeNode* left;         // Pointer to left child
    TreeNode* right;        // Pointer to right child

    // Constructor to initialize a node with a value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Recursive utility function to build the tree
    TreeNode* buildUtil(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& inMap) {

        // Base case: if the range is invalid, return NULL (no node)
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // The first element in the preorder segment is the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the index of the root value in inorder traversal
        int inRoot = inMap[root->val];

        // Number of nodes in the left subtree (in inorder)
        int numsLeft = inRoot - inStart;

        // Build the left subtree using:
        // preorder from preStart+1 to preStart + numsLeft
        // inorder from inStart to inRoot-1
        root->left = buildUtil(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inMap);

        // Build the right subtree using:
        // preorder from preStart + numsLeft + 1 to preEnd
        // inorder from inRoot + 1 to inEnd
        root->right = buildUtil(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inMap);

        // Return the root of the subtree
        return root;
    }

    // Main function to be called with preorder and inorder vectors
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap; // To store value → index mapping for inorder

        // Fill the map with inorder values and their indices
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Call the recursive utility to build the full tree
        return buildUtil(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1, inMap);
    }
};

// Helper function to print inorder traversal of the tree (for verification)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);           // Traverse left subtree
    cout << root->val << " ";           // Visit root
    printInorder(root->right);          // Traverse right subtree
}

// Helper function to print preorder traversal of the tree (for verification)
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";           // Visit root
    printPreorder(root->left);          // Traverse left subtree
    printPreorder(root->right);         // Traverse right subtree
}

// Main function to test the code
int main() {
    // Sample input
    vector<int> preorder = {3, 9, 20, 15, 7};   // Root → Left → Right
    vector<int> inorder = {9, 3, 15, 20, 7};    // Left → Root → Right

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder); // Build the tree

    // Print the tree to verify
    cout << "Inorder of constructed tree: ";
    printInorder(root);          // Expected: 9 3 15 20 7
    cout << "\nPreorder of constructed tree: ";
    printPreorder(root);         // Expected: 3 9 20 15 7
    cout << endl;

    return 0;
}
