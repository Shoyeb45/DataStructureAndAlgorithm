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
    int find_depth(TreeNode* root) {
        if (!root) return 0;
        return max(find_depth(root->left), find_depth(root->right)) + 1; 
    }


    TreeNode* dfs(TreeNode* root, int curr_len, int mx_depth) {
        if (curr_len == mx_depth - 1) return root;

        TreeNode *left = nullptr, *right = nullptr;
        
        if (root->left) left = dfs(root->left, curr_len + 1, mx_depth);
        if (root->right) right = dfs(root->right, curr_len + 1, mx_depth);

        if (left && right) return root;

        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       int mx_depth = find_depth(root);
       cout << mx_depth;
       return dfs(root, 0, mx_depth);
    }
};