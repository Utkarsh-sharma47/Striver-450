#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;         // The value stored in the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *prev = NULL; // This will keep track of the previously visited node

    void flatten(TreeNode *node)
    {
        // Base case: if the current node is NULL, just return
        if (node == NULL)
            return;

        // Recursively flatten the right subtree first
        flatten(node->right);

        // Recursively flatten the left subtree
        flatten(node->left);

        // Set the current node's right to the previously processed node
        node->right = prev;

        // Since we want a singly linked list (right pointers only), set left to NULL
        node->left = NULL;

        // Update prev to current node for the next call
        prev = node;
    }
};
