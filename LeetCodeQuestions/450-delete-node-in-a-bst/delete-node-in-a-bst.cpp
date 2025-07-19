/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef TreeNode Node;

class Solution {
    // delete and return node
    Node* del(Node* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key > root -> val) {
            root -> right = del(root -> right, key);
            return root;
        } else if (key < root -> val) {
            root -> left = del(root -> left, key);
            return root;
        } 

        if (root -> left && root -> right) {
            Node* right = root -> left;
            while (right -> right) {
                right = right -> right;
            }
            root -> val = right -> val; 
            root -> left = del(root -> left, right -> val);
            return root;
        } else if (!root -> left && !root -> right) {
            delete root;
            return nullptr;
        } else if (!root -> left) {
            return root -> right;
        } 
        return root -> left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = del(root, key);
        return root;
    }
};