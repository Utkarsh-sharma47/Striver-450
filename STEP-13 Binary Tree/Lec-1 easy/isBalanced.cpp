#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Returns height if balanced, -1 if not balanced
    int check(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftHeight = check(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = check(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root)
    {
        return check(root) != -1;
    }
};

// Sample main function to test the code
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    // root->left->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(4);

    if (sol.isBalanced(root))
        cout << "Tree is balanced\n";
    else
        cout << "Tree is not balanced\n";

    return 0;
}
