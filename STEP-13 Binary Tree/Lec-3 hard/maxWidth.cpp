#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

// Definition of a binary tree node
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Queue for level order traversal: stores (node, index)
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); // Root is at index 0

        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second; // To normalize indices
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                unsigned long long currIndex = q.front().second - minIndex;
                q.pop();

                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;

                if (node->left) {
                    q.push({node->left, 2 * currIndex + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * currIndex + 2});
                }
            }

            // Update maximum width
            int width = last - first + 1;
            maxWidth = max(maxWidth, width);
        }

        return maxWidth;
    }
};

// Helper function to build the test tree:
//         1
//       /   \
//      3     2
//     / \     \
//    5   3     9
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    // Build the binary tree
    TreeNode* root = buildSampleTree();

    // Create solution object and calculate width
    Solution sol;
    int result = sol.widthOfBinaryTree(root);

    // Output the result
    cout << "Maximum width of the binary tree is: " << result << endl;

    // Clean up memory (not strictly necessary for small test case)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
