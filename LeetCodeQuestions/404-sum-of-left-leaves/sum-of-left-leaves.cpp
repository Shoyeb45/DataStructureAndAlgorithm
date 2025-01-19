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
    int f(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (!root -> left && !root -> right) {
            return root -> val;
        }

        int left = f(root -> left);
        int right = 0;
        TreeNode* temp = root -> right;
        if (temp && (temp -> left || temp -> right)) {
            right = f(temp);
        }

        return left + right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root -> left && !root -> right) {
            return 0;
        }
        return f(root);
    }
};