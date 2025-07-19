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
    Node* insert(Node* root, int val) {
        if (!root) {
            return new Node(val);
        }

        if (val > root -> val) {
            root -> right = insert(root -> right, val);
            return root;
        } 
        root -> left = insert(root -> left, val);
        return root; 
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return insert(root, val);
    }
};