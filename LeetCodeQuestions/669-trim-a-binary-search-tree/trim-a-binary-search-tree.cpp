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
class Solution {
public:
    TreeNode* f(TreeNode* root, int low, int high) {
        if (!root) {
            return nullptr;
        }
        if (root -> val < low) {
            root = f(root -> right, low, high);
        }
        else if (root -> val > high) {
            root = f(root -> left, low, high);
        }
        else {
            root -> left = f(root -> left, low, high);
            root -> right = f(root -> right, low, high);
        }
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) {
            return root;
        }
        TreeNode* temp = root;
        return f(temp, low, high);
    }
};