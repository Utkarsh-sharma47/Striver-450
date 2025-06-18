/*
APP:-
if the current node is either p or q, we return 
it as a potential answer.

Recurse on both left and right subtrees.

There are 3 possible cases:

Both left and right recursive calls return non-null → current node 
is the LCA.

Only one side returns non-null → propagate that non-null node upward.

Both return null → return null.

This works in a Binary Tree (not necessarily BST), and assumes
both nodes p and q exist in the tree.
*/
#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is NULL, return NULL
        if (!root) return NULL;

        // If root matches either p or q, return root (found one node)
        if (root->val == p->val) return root;
        if (root->val == q->val) return root;

        // Recurse on left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // Case 1: If both sides return non-null, current node is LCA
        if (leftLCA && rightLCA) return root;

        // Case 2: Return the non-null one (either one node found or still propagating LCA)
        if (leftLCA) return leftLCA;
        return rightLCA;
    }
};

// Utility function to build a sample binary tree:
//          3
//        /   \
//       5     1
//      / \   / \
//     6   2 0   8
//        / \
//       7   4
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    return root;
}

// Find node with given value in the tree
TreeNode* findNode(TreeNode* root, int value) {
    if (!root) return NULL;
    if (root->val == value) return root;
    TreeNode* left = findNode(root->left, value);
    if (left) return left;
    return findNode(root->right, value);
}

int main() {
    TreeNode* root = buildSampleTree();

    // Choose nodes for which to find LCA
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}
