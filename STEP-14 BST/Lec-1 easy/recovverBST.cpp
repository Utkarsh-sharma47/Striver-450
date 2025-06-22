/*
 where two nodes have been swapped by mistake. 
 The goal is to restore the BST by swapping them back, 
 without modifying the structure of the tree.
*/

/*
APP:-
1.inorder traversal to make pointer to the violated nodes
  as prev value cant be more than current node value (use this)
2.in 'first' node , update prev value
  in 'second' node update root value

*since one violated node will be "prev" and other it will be "root"
(while travesing)

*/
#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* first = NULL;   // First wrong node
    TreeNode* second = NULL;  // Second wrong node
    TreeNode* prev = NULL;    // Previous node in in-order traversal

    // In-order traversal to find the two swapped nodes
    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Check for violation of BST property
        if (prev != NULL && prev->val > root->val) {
            // First time violation
            if (!first) {
                first = prev;
                second = root;
            } else {
                // Second time violation
                second = root;
            }
        }
        prev = root;  // Update previous node

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        // Swap values of the two nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};

// ---------- Below is test example usage ----------

void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    /*
       Original BST:        3
                          /   \
                         1     4
                              /
                             2
       Here, 2 and 3 are swapped to make it wrong. The correct BST should be:
                             2
                           /   \
                          1     4
                               /
                              3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder before recovery: ";
    inorderPrint(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "Inorder after recovery: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
