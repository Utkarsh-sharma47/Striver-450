#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;         // Value of the node
    TreeNode *left;  // Pointer to left child
    TreeNode *right; // Pointer to right child

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Function to perform Morris Inorder Traversal
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;  // Result vector to store inorder traversal
        TreeNode *cur = root; // Start from the root

        // Traverse the tree
        while (cur != nullptr)
        {
            // Case 1: If current node has no left child
            if (cur->left == nullptr)
            {
                inorder.push_back(cur->val); // Visit current node
                cur = cur->right;            // Move to right subtree
            }
            else
            {
                // Case 2: Current node has a left child
                // Find the inorder predecessor (rightmost node of left subtree)
                TreeNode *prev = cur->left;
                while (prev->right != nullptr && prev->right != cur)
                {
                    prev = prev->right; // Move to the rightmost node
                }

                // If right pointer of predecessor is NULL, create a thread
                if (prev->right == nullptr)
                {
                    prev->right = cur; // Make thread to current node
                    cur = cur->left;   // Move to left subtree
                }
                // If thread already exists, break it and visit current
                else
                {
                    prev->right = nullptr;       // Remove the thread
                    inorder.push_back(cur->val); // Visit current node
                    cur = cur->right;            // Move to right subtree
                }
            }
        }

        return inorder; // Return the traversal result
    }
};

// Sample usage
int main()
{
    // Example tree:
    //     1
    //   /  \
    // 6      2
    //      /
    //     3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(6);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal (Morris): ";
    for (int val : result)
    {
        cout << val << " ";
    }

    // Output should be: 1 3 2
    return 0;
}
