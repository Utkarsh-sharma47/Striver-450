#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // Sentinel to mark end of level

        vector<int> level;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                ans.push_back(level);
                level.clear();

                // If there are more nodes, add a new NULL to mark the next level
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                level.push_back(curr->val); // Add current node's value

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    /*
        Constructed Binary Tree:
             1
            / \
           2   3
          / \
         4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
