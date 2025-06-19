#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string using level order traversal (BFS).
    string serialize(TreeNode* root) {
        if (!root) return "#";  // If the tree is empty, return "#"

        string s;
        queue<TreeNode*> q;
        q.push(root);  // Start BFS from the root

        while (!q.empty()) {
            TreeNode* node = q.front();  // Get the front node
            q.pop();

            if (node == NULL) {
                s += "#,";  // Use "#" to represent null node
            } else {
                s += to_string(node->val) + ",";  // Add current node value
                q.push(node->left);              // Push left child to queue
                q.push(node->right);             // Push right child to queue
            }
        }

        return s;  // Final serialized string
    }

    // Decodes your encoded data to tree using level order traversal.
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;  // If data represents an empty tree

        stringstream ss(data);  // Create a string stream from the input string
        string str;

        // Read the root value from the stream
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));  // Create root node
        queue<TreeNode*> q;
        q.push(root);  // Start BFS from the root

        while (!q.empty()) {
            TreeNode* node = q.front();  // Current node to attach children
            q.pop();

            // Process left child
            if (getline(ss, str, ',')) {  // Read next token
                if (str == "#") {
                    node->left = NULL;  // Null if token is "#"
                } else {
                    node->left = new TreeNode(stoi(str));  // Create left child
                    q.push(node->left);  // Push left child to queue
                }
            }

            // Process right child
            if (getline(ss, str, ',')) {  // Read next token
                if (str == "#") {
                    node->right = NULL;  // Null if token is "#"
                } else {
                    node->right = new TreeNode(stoi(str));  // Create right child
                    q.push(node->right);  // Push right child to queue
                }
            }
        }

        return root;  // Return reconstructed root
    }
};

// Example usage
int main() {
    Codec ser, deser;

    // Manually creating a sample tree:
    //     1
    //    / \
    //   2   3
    //      / \
    //     4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serialized = ser.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    // Deserialize the tree
    TreeNode* newRoot = deser.deserialize(serialized);
    cout << "Tree deserialized successfully!" << endl;

    return 0;
}
